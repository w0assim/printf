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

