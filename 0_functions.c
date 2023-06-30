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

/**
 * _print_string -prints a string literal
 * @varg: argument
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: preci
 * @size: size
 * Return: nb of printed
 */

int _print_string(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	int len, i;
	char *arg;

	len = 0;
	arg = va_arg(varg, char*);
	UNUSED(buff);
	if (arg == NULL)
	{
		arg = "(null)";
		if (precision >= 6)
			arg = "      ";
	}
	while (arg[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flag & F_M)
		{
			write(1, &arg[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &arg[0], len);
			return (width);
		}
	}
	UNUSED(flag);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);
	UNUSED(buff);
	UNUSED(varg);
	return (write(1, arg, len));
}


/**
 * _print_percent - print %%
 * @varg: argments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: preci
 * @size: int
 * Return: int
 */


int _print_percent(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	UNUSED(varg);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * _print_int -prints int
 * @varg: argments
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: preci
 * @size: int
 * Return: int
 */

int _print_int
