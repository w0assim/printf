#include "main.h"

/**
 * write_unsigned -s
 * @is_negative: s
 * @ind: in
 * @buffer: buffer
 * @flags: dfg
 * @width: eid
 * @precision: preci
 * @size: skz
 * Return: int
 */



int write_unsigned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_LIMIT - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_LIMIT - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_Z) && !(flags & F_M))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_M)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}


/**
 * _digit - is a digit
 * @c: c
 * Return: int
 */

int _digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

