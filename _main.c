#include "main.h"

/**
 * _printf -home made printf
 * @format: formatted string
 * Return: nb of printed chars
 */

int _printf(const char *format, ...)
{
	int i, cpt, count, flag, width, precision, size, buff_size;
	va_list varg;
	char buff[BUFF_LIMIT];

	cpt = 0;
	count = 0;
	buff_size = 0;
	if (format == NULL)
		return (0);
	va_start(varg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			_print_buffer(buff, &buff_size);
			flag = _flag(format, &i);
			width = _width(format, &i, varg);
			precision = _precision(format, &i, varg);
			size = _size(format, &i);
			i += 1;
			cpt = _print_formatted(format, &i, varg, buff, flag,
				       width, precision, size);
			if (cpt == -1)
			{
				return (-1);
			}
			count += cpt;
		}
		else
		{
			buff[buff_size++] = format[i];
			if (buff_size == BUFF_LIMIT)
				_print_buffer(buff, &buff_size);
			count++;
		}
	}
	_print_buffer(buff, &buff_size);
	va_end(varg);
	return (count);
}

