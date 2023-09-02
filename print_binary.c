#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary - main function that prints
 * an unsigned integer argument in binary format.
 * @args: va_list of arguments.
 *
 * Return: number of printed chars.
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int number_bits = count_digits(n);
	int x = 0;

	for (x = number_bits - 1; x >= 0; x--)
		_putchar((n >> x) & 1 ? '1' : '0');

	return (number_bits);
}
