#include "main.h"


/**
 * _flag - get flag
 * @format: format
 * @i: i
 * Return: int
 */

int _flag(const char *format, int *i)
{
	int ii;
	int flags = 0;
	int j;
	const char iddd[] = {'-', '+', '0', '#', ' ', '\0'};
	const int idd[] = {F_M, F_P, F_Z, F_H, F_S, 0};

	for (ii = *i + 1; format[ii] != '\0'; ii++)
	{
		for (j = 0; iddd[j] != '\0'; j++)
			if (format[ii] == iddd[j])
			{
				flags |= idd[j];
				break;
			}
		if (iddd[j] == 0)
			break;
	}
	*i = ii - 1;
	return (flags);
}


/**
 * _precision -precision
 * @format: format
 * @i: i
 * @varg: arg
 * Return: int
 */

int _precision(const char *format, int *i, va_list varg)
{
	int ii = *i + 1;
	int precision = -1;

	if (format[ii] != '.')
		return (precision);
	precision = 0;
	for (ii *= 1; format[ii] != '\0'; ii++)
	{
		if (_digit(format[ii]))
		{
			precision *= 10;
			precision += format[ii] - '0';
		}
		else if (format[ii] == '*')
		{
			ii++;
			precision = va_arg(varg, int);
			break;
		}
		else
			break;
	}
	*i = ii - 1;
	return (precision);
}

/**
 * _width -width
 * @format: format
 * @i: i
 * @varg: arg
 * Return: int
 */

int _width(const char *format, int *i, va_list varg)
{
	int ii;
	int width = 0;

	for (ii = *i + 1; format[ii] != '\0'; ii++)
	{
		if (_digit(format[ii]))
		{
			width *= 10;
			width += format[ii] - '0';
		}
		else if (format[ii] == '*')
		{
			ii++;
			width = va_arg(varg, int);
			break;
		}
		else
			break;
	}
	*i = ii - 1;
	return (width);
}


/**
 * _size -size
 * @format: format
 * @i: i
 * Return: int
 */

int _size(const char *format, int *i)
{
	int ii = *i + 1;
	int size = 0;

	if (format[ii] == 'l')
		size = MACR1;
	else if (format[ii] == 'h')
		size = MACR1;
	if (size == 0)
		*i = ii - 1;
	else
		*i = ii;
	return (size);
}

