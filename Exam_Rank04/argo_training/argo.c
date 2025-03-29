#include "argo.h"

int	g_error = 0;
int parse_json(json *dst, FILE *stream);

int peek(FILE *stream)
{
	int c = getc(stream);
	ungetc(c, stream);
	return c;
}

void unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

char *extract_string(FILE *stream)
{
	char *res = malloc(sizeof(char));
	char cur_char;
	res[0] = '\0';
	int	str_len = 0;

	while(peek(stream) != '"' && peek(stream) != EOF) // else?
	{
		str_len++;
		res = realloc(res, (str_len + 1)*sizeof(char));
		res[str_len] = '\0';
		cur_char = getc(stream);
		// case '\\'
		if(cur_char == '\\')
		{
			if(peek(stream) == '"' || peek(stream) == '\\')
			{
				cur_char = getc(stream);
			}
		}
		res[str_len - 1] = cur_char;
	}
	if(!expect(stream, '"'))
	{
		free(res);
		res = NULL;
	}
	return(res);
}

int	parse_string(json *dst, FILE *stream)
{
	accept(stream, '"');
	dst->type = STRING;

	char *str = NULL;
	dst->string = str;
	str = extract_string(stream);
	if (!str)
		return -1;
	dst->string = str;
	//*dst = (json){.type = STRING, .string = str};
	return 1;
}

int its_digit(json *dst, FILE *stream)
{
	int		num;
	int		ret_scanf;

	ret_scanf = fscanf(stream, "%d", &num);
	if (ret_scanf <= 0 || ret_scanf == EOF)
	{
		return -1;
	}
	dst->type = INTEGER;
	dst->integer = num;
	return 1;
}

int parse_number(json *dst, FILE *stream)
{
	if (its_digit(dst, stream) == -1)
	{
		unexpected(stream);
		return -1;
	}
	return 1;
}

int	parse_map(json *dst, FILE *stream)
{
	accept(stream, '{');
	dst->type = MAP;
	dst->map.data = NULL;
	dst->map.size = 0;
	char *str = NULL;

	while(peek(stream) != '}' && peek(stream) != EOF)
	{
		dst->map.data = realloc(dst->map.data, \
			(dst->map.size + 1) * sizeof(pair));
		if(!dst->map.data)
			return -1;
		if(!expect(stream, '"'))
			return -1;
		str = extract_string(stream);
		if(!str)
			return -1;
		dst->map.data[dst->map.size].key = str;
		if(!expect(stream, ':'))
			return -1;
		if(parse_json(&dst->map.data[dst->map.size].value, stream) == -1)
			return -1;
		dst->map.size++;
		if (peek(stream) == ',')
		{
			accept(stream, ',');
			continue;
		}
		else
			break ;
	}
	if(expect(stream, '}'))
		return 1;
	else
		return -1;
}

int parse_json(json *dst, FILE *stream)
{
	char c;
	c = peek(stream);
	if (c == EOF)
		return -1;
	if (isdigit(c) || c == '-')
		return(parse_number(dst, stream));
	if (c == '"')
		return(parse_string(dst, stream));
	// its_map
	if (c == '{')
	{
		if (parse_map(dst, stream) == -1)
			return -1;
		return 1;
	}
	else 
	{
		unexpected(stream);
		return -1;
	}
}

int argo(json *dst, FILE *stream)
{
	if (!stream)
	{
		printf("NO file\n");
		return (-1);
	}
	if (parse_json(dst, stream) == -1)
		return -1;
	// global errors
	if (peek(stream) == EOF)
		return 1;
	else if (peek(stream) == '\n')
		return 1;
	else 
	{
		unexpected(stream);
		return -1;
	}
	return 1;
}
