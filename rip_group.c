#include <stdio.h>

// stack based approach.
int	check_if_balanced(char *str)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			counter++;
		else if (str[i] == ')')
			counter--;
		if (counter < 0)
			return (0);
		i++;
	}
	if (counter == 0)
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*trim(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (s[i] == ')')
		s[i++] = ' ';
	i = ft_strlen(s) - 1;
	while (s[i] == '(')
		s[i--] = ' ';
	return (s);
}

int	handle_case_when_only_empty_space(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == len)
		return (1);
	else
		return (0);
}

/* void    balance_recursively() */

void	balance(char *line, int index, int to_remove, int removed)
{
	int		length;
	char	c;

	length = ft_strlen(line);
	if (removed == to_remove)
	{
		if (check_if_balanced(line))
			puts(line);
		return ;
	}
	if (index == length)
		return ;
	if (removed < to_remove)
	{
		c = line[index];
		line[index] = ' ';
		balance(line, index + 1, to_remove, removed + 1);
		line[index] = c;
	}
	balance(line, index + 1, to_remove, removed);
}

int	get_min_for_balanced(char *str)
{
	int	counter_l;
	int	counter_r;
	int	out;
	int	i;

	counter_l = 0;
	counter_r = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			counter_l++;
		else if (str[i] == ')')
			counter_r++;
		i++;
	}
	out = counter_l - counter_r;
	if (out >= 0)
		return (out);
	else
		return (-out);
}

int	main(int argc, char *argv[])
{
	char	*line;
	int		m_spc;

	line = argv[1];
	if (argc != 2)
		return (0);
	if (!argv[1][0])
		return (0);
	m_spc = get_min_for_balanced(line);
	if (check_if_balanced(line))
	{
		puts(line);
		return (0);
	}
	balance(line, 0, m_spc, 0);
}
