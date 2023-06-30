#ifndef main_h
#define main_h
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int check_c(char, char);
int size_of_string(char *);
void _print_percent(int i, int cpt);
void _print_c(char c, int cpt);


#endif
