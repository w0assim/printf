#include "main.h"

/**
 * _print_unsigned - unsigned
 * @varg: arg
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_unsigned(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	int j = BUFF_LIMIT - 2;
	unsigned long int n = va_atg(varg, unsigned long int);

	n = convert_unsigned(n, size);
	if (n == 0)
		buff[j--] = '0';
	buff[BUFFER_LIMIT - 1] = '\0';
	while (n > 0)
	{
		buff[j--] = (n % 10) + '0';
		n /= 10;
	}
	j++;
	return (write_unsigned(0, j, buff, flag, width, precision, size));
}


/**
 *_print_octal -octal
 * @varg: arg
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_octal(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	int i = BUFF_LIMIT - 2;
	unsigned long int n = va_arg(varg, unsigned long int);
	unsigned long int num = n;

	n = convert_unsigned(n, size);
	if (n == 0)
		buff[i--] = '0';
	buff[BUFFER_LIMIT - 1] = '\0';
	while (n > 0)
	{
		buff[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flag & F_H && num != 0)
		buff[i--] = '0';
	i++;
	return (write_unsigned(0, i, buff, flag, width, precision, size));
}

/**
 * _print_hexa - unsigned
 * @varg: arg
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_hexa(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	return (_print_hexadecimal(varg, "0123456789abcdef",
				buff, flag, 'x', width, precision, size));
}


/**
 * _print_hexa_upper - demkj
 * @varg: arg
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_hexa_upper(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	return (_print_hexadecimal(varg, "0123456789ABCDEF",
				buff, flag, 'X', width, precision, size));
}

