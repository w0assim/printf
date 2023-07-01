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

int _print_int(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	int i = BUFF_LIMIT - 2;
	int _negative = 0;
	long int n = va_arg(varg, long int);
	unsigned long int nn;

	n = convert_number(n, size);
	if (n == 0)
		buff[i--] = '0';
	buff[BUFF_LIMIT - 1] = '\0';
	nn = (unsigned long int)n;
	if (n < 0)
	{
		nn = (unsigned long int)((-1) * n);
		_negative = 1;
	}
	while (nn > 0)
	{
		buff[i--] = (nn % 10) + '0';
		nn /= 10;
	}
	i++;
	return (write_number(_negative, i, buff, flag, width, precision, size));
}


/**
 * _print_binary -bin
 * @varg: arg
 * @buff: buff
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: nb
 */

int _print_binary(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	unsigned int x, y, j, sm, i[32];
	int count;
	char a;

	UNUSED(flag);
	UNUSED(buff);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	x = va_arg(varg, unsigned int);
	y = 2147483648;
	i[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		i[j] = (x / y) % 2;
	}
	for (j = 0, sm = 0, count = 0; j < 32; j++)
	{
		sm += i[j];
		if (sm || j == 31)
		{
			a = '0' + i[j];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}

