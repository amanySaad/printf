#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_rot13_string - main function that prints a rot13'ed string.
 * @args: va_list contain arguments.
 * @buffer: char array to store the format string.
 * @buffer_index: pointer to the current index in buffer.
 *
 * Return: number of printed chars.
 */
int print_rot13_string(va_list args, char *buffer, int *buffer_index)
{
	char *str = va_arg(args, char *);
	int x, y;
	int chars_printed = 0;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
	str = "(null)";

	for (x = 0; str[x] != '\0'; x++)
	{
	for (y = 0; rot13[y] != '\0'; y++)
	{
		if (str[x] == rot13[y])
		{
		buffer[(*buffer_index)++] = ROT13[y];
		chars_printed++;
		break;
		}
	}
	if (rot13[y] == '\0')
	{
		buffer[(*buffer_index)++] = str[x];
		chars_printed++;
	}
	}

	return (chars_printed);
}
