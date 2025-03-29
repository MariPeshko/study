#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#include <errno.h> // temp

typedef struct json {
    enum {
      MAP,
      INTEGER,
      STRING
    } type;
    union {
        struct {
                struct pair *data;
                size_t      size;
        } map;
        int   integer;
        char  *string;
    };
} json;

typedef struct pair {
    char *key;
    json value;
} pair;

void free_json(json j);

int argo(json *dst, FILE *stream);

/*
clang -Wall -Wextra -Werror -c main.c -o main.o
clang -Wall -Wextra -Werror -c argo.c -o argo.o
clang main.o argo.o -o argo
*/
