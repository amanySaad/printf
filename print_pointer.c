#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_pointer - main function to print
 * a pointer address in hexadecimal format.
 * @args: va_list of arguments contain printed pointer.
 * @buffer: char array to store the formatted output.
 * @buffer_index: pointer to the current index of the buffer.
 *
 * Return: number of printed characters.
 */
int print_pointer(va_list args, char *buffer, int *buffer_index)
{
	void *ptr = va_arg(args, void *);
	unsigned long int address = (unsigned long int)ptr;
	int x = 0;
	char hex_digits[] = "0123456789abcdef";

	buffer[(*buffer_index)++] = '0';
	buffer[(*buffer_index)++] = 'x';
	for (x = 13; x >= 0; x--)
	{
	if (x % 2 != 0)
	buffer[(*buffer_index)++] = hex_digits[(address >> x * 4) & 0xF];
	}

	return (14);
}
