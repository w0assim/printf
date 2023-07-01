#include "main.h"

/**
 *_print_pointer - print
 * @varg: arg
 * @buff: buff
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_pointer(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	char ech = 0, pad = ' ';
	int i = BUFF_LIMIT - 2, len = 2, pa = 1;
	unsigned long n;
	char tht[] = "012345678abcdef";
	void *ptr = va_arg(varg, void *);

	UNUSED(width);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_LIMIT - 1] = '\0';
	UNUSED(precision);
	n = (unsigned long) ptr;
	while (n > 0)
	{
		buff[i--] = tht[n % 16];
		n /= 16;
		len++;
	}
	if ((flag & F_Z) && !(flag & F_M))
		pad = '0';
	if (flag & F_P)
		ech = '+', len++;
	else if (flag & F_S)
		ech = ' ', len++;
	i++;
	return (write_pointer(buff, i, len, width, flag, pad, ech, pa));
}

/**
 *_print_non_printable - non printable
 * @varg: arg
 * @buff: buff
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_non_printable(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	int i = 0;
	int ofs = 0;
	char *ptr = va_arg(varg, char*);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
		return (write(1, "(null)", 6));
	while (ptr[i] != '\0')
	{
		if (_printable(ptr[i]))
			buff[i + ofs] = ptr[i];
		else
			ofs += hx(ptr[i], buff, i + ofs);
		i++;
	}
	buff[i + ofs] = '\0';
	return (write(1, buff, i + ofs));
}

/**
 *_print_string_reversed - reversed string
 * @varg: arg
 * @buff: buff
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_string_reversed(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	char *ptr;
	int i;
	int count;
	char a;

	count = 0;
	UNUSED(flag);
	UNUSED(buff);
	UNUSED(width);
	UNUSED(size);
	ptr = va_arg(varg, char *);
	if (ptr == NULL)
	{
		UNUSED(precision);
		ptr = "(Null)";
	}
	for (i = 0; ptr[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		a = ptr[i];
		write(1, &a, 1);
		count++;
	}
	return (count);
}

/**
 * _print_rot13string - rot13'ed string
 * @varg: arg
 * @buff: buff
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: int
 */

int _print_rot13string(va_list varg, char buff[], int flag,
		int width, int precision, int size)
{
	char a, *ptr;
	unsigned int i, j;
	int count;
	char ni[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char tou[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	count = 0;
	ptr = va_arg(varg, char*);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	if (ptr == NULL)
		ptr = "(AHYY)";
	for (i = 0; ptr[i]; i++)
	{
		for (j = 0; ni[j]; j++)
		{
			if (ni[j] == ptr[i])
			{
				a = tou[j];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!ni[j])
		{
			a = ptr[i];
			write(1, &a, 1);
			count++;
		}

	}
	return (count);
}

