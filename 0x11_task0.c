#include "main.h"

/**
 * _printf -home made print
 * Return: nb of chars printed
 * @format: formatted string
 */

int _printf(const char *format, ...)
{
	char c;
	va_list varg;
	int i, cpt, value;

	va_start(varg, format);
	cpt = 0;
	for (i= 0; (c = format[i]) != '\0'; i++)
	{
		
	}
}
