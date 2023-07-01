#include "main.h"

/**
 * write_number -numb
 * @_ps: ns
 * @i: -s
 * @buff: buf
 * @flag: flag
 * @width: width
 * @precision: preicison
 * @size: size
 * Return: nb
 */

int write_number(int _ps, int i, char buff[], int flag,
		int width, int precision, int size)
{
	int len = BUFF_LIMIT - i - 1;
	char tmp = ' ', ech = 0;

	UNUSED(size);
	if ((flag & F_Z) && !(flag & F_M))
		tmp = '0';
	if (_ps)
		ech = '-';
	else if (flag & F_P)
		ech = '+';
	else if (flag & F_S)
		ech = ' ';
	return (write_num(i, buff, flag, width, precision, len, tmp, ech));
}



/**
 * write_num -write number
 * @i: index
 * @buff: buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @len: lenght
 * @tmp: tmp
 * @ech: ech
 * Return: nb of printed
 */

int write_num(int i, char buff[], int flag, int width,
		int precision, int len, char tmp, char ech)
{
	int ln, padd = 1;

	if (precision == 0 && i == BUFF_LIMIT - 2 && buff[i] == '0' && width == 0)
		return (0);
	if (precision == 0 && i == BUFF_LIMIT - 2 && buff[i] == '0')
		buff[i] = tmp = ' ';
	if (precision > 0 && precision < len)
		tmp = ' ';
	while (precision > len)
		buff[--i] = '0', len++;
	if (ech != 0)
		len++;
	if (width > len)
	{
		for (ln = 1; ln < width - len + 1; ln++)
			buff[ln] = tmp;
		buff[ln] = '\0';
		if (flag & F_M && tmp == ' ')
		{
			if (ech)
				buff[--i] = ech;
			return (write(1, &buff[i], len) + write(1, &buff[1], ln - 1));
		}
		else if (!(flag & F_M) && tmp == ' ')
		{
			if (ech)
				buff[--i] = ech;
			return (write(1, &buff[1], ln - 1) + write(1, &buff[i], len));
		}
		else if (!(flag & F_M) && tmp == '0')
		{
			if (ech)
				buff[--padd] = ech;
			return (write(1, &buff[padd], ln - padd) +
					write(1, &buff[i], len - (1 - padd)));
		}
	}
	if (ech)
		buff[--i] = ech;
	return (write(1, &buff[i], len));
}


/**
 * convert_number -converting
 * @n: numb
 * @size: size
 * Return: converted
 */

long int convert_number(long int n, int size)
{
	if (size == MACR1)
	{
		return (n);
	}
	else if (size == MACR2)
	{
		return ((short)n);
	}
	return ((int)n);
}


/**
 * convert_unsigned -convrt unsigned
 * @number: nb to cnvrt
 * @size: size
 * Return: long int
 */

long int convert_unsigned(unsigned long int number, int size)
{
	if (size == MACR1)
		return (number);
	else if (size == MACR2)
		return ((unsigned short)number);
	return ((unsigned int)number);
}

