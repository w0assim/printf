#include "main.h"

/**
 * _print_char -print a char
 * Return: nb of char printed
 * @varg: arg
 * @buff: buffer
 * @flag: flags
 * @width: widths
 * @precision: precision
 * @size: size
 */

int _print_char(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	char c, tmp;
	int i;

	c = va_arg(varg, int);
	i = 0;
	tmp = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_Z)
		tmp = '0';
	buff[i++] = c;
	buff[i] = '\0';
	if (width > 1)
	{
		buff[BUFF_LIMIT - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		{
			buff[BUFF_LIMIT - i - 2] = tmp;
		}
		if (flag & F_M)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_LIMIT - i - 1], width - 1));
		else
			return (write(1, &buff[BUFF_LIMIT - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

