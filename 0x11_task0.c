#include "main.h"

/**
 * _printf -home made printf
 * Return: number of chars printed
 * @format: string
 */

int _printf(const char *format, ...)
{
	va_list varg;
	int i, c_ase, string_size;
	char c, c_arg, *s_arg;

	cpt = 0;
	c = 30;
	i = 0;
	string_size = 0;
	va_start(varg, format);
	while ((c = format[i]) != '\0')
	{
		i++;
		c_ase = check_c(c, format[i]);
		switch (c_ase)
		{
			case 0:
				write(1, "%%", 2);
				i++;
				break;
			case 1:
				c_arg = va_arg(varg, char);
				write(1, &c_arg, 1);
				i++;
				break;
			case 2:
				s_arg = va_arg(varg, char*);
				string_size = size_of_string(s_arg);
				write(1, &s_arg, string_size);
				i++;
				break;
			case 3:
				write(1, &c, 1);
		}
	}
}

/**
 * check_c -check char value
 * Return: check value
 * @c1: current char
 * @c2: next char
 */


int check_c(char c1, char c2)
{
	if (c2 == '\0')
	{
		return (3);
	}
	if (c1 == '%')
	{
		if (c2 == '&')
		{
			return (0);
		}
		else if (c2 == 'c')
		{
			return (1);
		}
		else if (c2 == 's')
		{
			return (2);
		}
		else
		{
			return (3);
		}
	}
	else
	{
		return (3);
	}
}

/**
 * size_of_string -size of string passed as argument to print function
 * Return: size
 * @arg: pointer to the string
 */

int size_of_string(char *arg)
{
	int cpt;
	char *pointer;

	cpt = 0;
	pointer = arg;
	while (pointer != NULL)
	{
		cpt++;
		pointer++;
	}
	return (cpt);
}

