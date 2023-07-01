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
int _print_formatted(const char *, int*, va_list,
		char[], int, int, int, int);

int _print_char(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_string(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_percent(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_int(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_binary(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_unsigned(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_octal(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_hexa(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_hexa_upper(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_hexadecimal(va_list, char[], char[],
		int, char, int, int, int);
int _print_non_printable(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_pointer(va_list varg, char buff[], int flag,
		int width, int precision, int size);
int _print_string_reversed(va_list, char[], int,
		int, int, int);
int _print_rot13string(va_list, char[], int, int, int, int);
long int convert_number(long int, int);

int _flag(const char *, int *);
int _width(const char *, int *, va_list);
int _precision(const char *, int *, va_list);
int _size(const char *, int *);

int write_number(int, int, char[], int, int, int, int);
int write_num(int, char[], int, int, int, int, char, char);

#define MACR1 2
#define MACR2 1
#define F_P 2
#define F_H 8
#define F_S 16
#define F_Z 4
#define F_M 1
#define UNUSED(x) (void)(x)

#endif
