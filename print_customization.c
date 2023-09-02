#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_custom_string - a function that prints a string
 * with non-printable chars represented as \x followed
 * by the ASCII code value in uppercase hexadecimal format.
 * @args: va_list of arguments.
 * @buffer: char array to store the formatted string.
 * @buffer_index: pointer to the index of the buffer.
 *
 * Return: number of printed characters.
 */
int print_custom_string(va_list args, char *buffer, int *buffer_index)
{
	char *str = va_arg(args, char *);
	int x = 0;
	int count = 0;

	if (str == NULL)
	str = "(null)";

	while (str[x] != '\0')
	{
	if (str[x] < 32 || str[x] >= 127)
	{
		buffer[*buffer_index++] = '\\';
		buffer[*buffer_index++] = 'x';
		buffer[*buffer_index++] = (str[x] / 16) < 10 ?
			((str[x] / 16) + '0') : ((str[x] / 16) - 10 + 'A');
	buffer[*buffer_index++] = (str[x] % 16) < 10 ?
			((str[x] % 16) + '0') : ((str[x] % 16) - 10 + 'A');
	count += 4;
	}
	else
	{
		buffer[*buffer_index++] = str[x];
		count++;
	}

	if (*buffer_index == 1024)
	{
		write(1, buffer, *buffer_index);
		count += *buffer_index;
		*buffer_index = 0;
	}

	x++;
	}

	return (count);
}
