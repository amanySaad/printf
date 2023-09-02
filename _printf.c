#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - main function produces
 * output according to a format.
 * @format: char string contain zero
 * or more directives.
 *
 * Return: number of printed characters.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	printed_chars = format_parser(format, args);
	va_end(args);

	return (printed_chars);
}
