#ifndef main_h
#define main_h
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_LIMIT 1024


int _printf(const char *format, ...);
void _print_buffer(char buff[], int *buff_size);



int _flag(const char *, int *);
int _width(const char *, int *, va_list);
int _precision(const char *, int *, va_list);
int _size(const char *, int *);


#endif
