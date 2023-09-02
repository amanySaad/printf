#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_reversed_string - main function prints the reversed
 * string corresponding to the "r" specifier in a format string.
 * @format: format string contain "r" specifier.
 */
void print_reversed_string(char *format, ...)
{
	va_list args;
	char *specifier;

	va_start(args, format);

	specifier = strchr(format, 'r');

	if (specifier != NULL)
	{
		char *arg = va_arg(args, char *);
		int length = strlen(arg);
		int x = length - 1;

		for (; x >= 0; x--)
		{
			putchar(arg[x]);
		}
	}

	va_end(args);
}

