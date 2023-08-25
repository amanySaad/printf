#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_string - prints a string.
 * @args: A va_list containing the argument to print.
 *
 * Return: The number of characters printed.
 */
int _print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}

	return (count);
}

/**
 * _print_percent - prints a percent character.
 * @args: A va_list containing the argument to print.
 *
 * Return: The number of characters printed.
 */
int _print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * _handle_specifier - handles a single conversion specifier.
 * @specifier: The conversion specifier character.
 * @args: A va_list containing the argument to print.
 *
 * Return: The number of characters printed.
 */
int _handle_specifier(char specifier, va_list args)
{
	switch (specifier)
	{
		case 'c':
			return (_print_char(args));

		case 's':
			return (_print_string(args));

		case '%':
			return (_print_percent(args));

		default:
			_print_char(args, specifier);
			return (2);
	}
}

/**
 * _printf - prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			count += _handle_specifier(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}
