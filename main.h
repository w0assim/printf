#ifndef main_h
#define main_h
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_LIMIT 1024

/**
 * struct p -struct
 * @sg: specifier
 * @s: associated function
 */

typedef struct p
{
	char sg;
	int (*s)(va_list, char[], int, int, int, int);
} specifier;


int _printf(const char *format, ...);
void _print_buffer(char buff[], int *buff_size);
int _print_char(va_list varg, char buff[], int flag,
		int width, int precision, int size);

int _flag(const char *, int *);
int _width(const char *, int *, va_list);
int _precision(const char *, int *, va_list);
int _size(const char *, int *);


#endif
