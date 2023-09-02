#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - main function that prints a character argument.
 * @args: va_list of arguments.
 *
 * Return: number of printed characters.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - main function that prints a string argument.
 * @args: va_list of arguments.
 *
 * Return: number of printed characters.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int x = 0;

	if (str == NULL)
		str = "(null)";

	while (str[x])
	{
		_putchar(str[x]);
		x++;
	}

	return (x);
}

/**
 * _putchar - main function that writes a char to stdout.
 * @c: character to be written.
 *
 * Return: On success, number of characters written.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
