#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_number - to print a number to a buffer.
 * @buffer: char buffer to be stored.
 * @n: number to print.
 *
 * Return: number of printed characters.
 */
int print_number(char *buffer, int n)
{
	return (sprintf(buffer, "%d", n));
}

/**
 * print_padding - to print padding characters to a buffer.
 * @buffer: char buff to stored.
 * @buffer_index: pointer to the current index in the buffer.
 * @num_spaces: number of spaces to print.
 * @padding_char: char to use for padding.
 *
 * Return: number of printed padding chars.
 */
int print_padding(char *buffer, int *buffer_index,
	int num_spaces, char padding_char)
{
	int x;

	for (x = 0; x < num_spaces; x++)
	{
	buffer[(*buffer_index)++] = padding_char;
	}

	return (num_spaces);
}
