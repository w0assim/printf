#include "main.h"

/**
 * _print_buffer -to print buffer content
 * @buff: buffer
 * @buff_size: size of buffer
 * Return: none
 */

void _print_buffer(char buff[], int *buff_size)
{
	if (*buff_size > 0)
	{
		write(1, &buff[0], *buff_size);
	}
	*buff_size = 0;
}


/**
 * _print_formatted -takes care of the printing
 * @format: formatted string
 * @i: index
 * @varg: arguments
 * @buff: buffer
 * @flag: flags
 * @width: width specifieer
 * @precision: ..specifier
 * @size: size
 * Return: int
 */

int _print_formatted(const char *format, int *i, va_list varg, char buff[],
		int flag, int width, int precision, int size)
{
	int ln, len, count;
	specifier specifiers[] = {
		{'c', _print_char}, {'s', _print_string}, {'%', _print_percent},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_unsigned}, {'o', _print_octal}, {'x', _print_hexa},
		{'X', _print_hexa_upper}, {'\0', NULL}
	};

	len = 0;
	count = -1;
	for (ln = 0; specifiers[ln].sg != '\0'; ln++)
	{
		if (format[*i] == specifiers[ln].sg)
		{
			return (specifiers[ln].s(varg, buff, flag, width, precision, size));
		}
	}
	if (specifiers[ln].sg == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		len += write(1, &format[*i], 1);
		return (len);
	}
	return (count);
}

