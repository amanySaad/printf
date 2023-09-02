#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * add_to_buffer - a function that adds
 * a character to the output buffer.
 * @buffer: char buffer to store output.
 * @buffer_index: pointer to the current index in the buffer.
 * @c: char to be added to buffer.
 *
 * Return: 1 on success, 0 on failure.
 */
int add_to_buffer(char *buffer, int *buffer_index, char c)
{
	if (*buffer_index >= BUFFER_SIZE)
		return (0);
	buffer[*buffer_index] = c;
	(*buffer_index)++;
	return (1);
}
