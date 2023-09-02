#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * format_parser - main function parses the format string and
 * prints the corresponding output.
 * @format: char string contain zero or more directives.
 * @args: va_list of arguments.
 *
 * Return: number of printed characters.
 */
int format_parser(const char *format, va_list args)
{
	int x = 0;
	int printed_chars = 0;

	while (format && format[x])
	{
		if (format[x] == '%')
		{
		x++;
		if (format[x] == '\0')
		return (-1);
		if (format[x] == '%')
			printed_chars += _putchar('%');
		else if (format[x] == 'c')
			printed_chars += print_char(args);
		else if (format[x] == 's')
			printed_chars += print_string(args);
		else
			printed_chars += _putchar('%') + _putchar(format[x]);
		}
	else
	{
		printed_chars += _putchar(format[x]);
	}
	x++;
	}

	return (printed_chars);
}
