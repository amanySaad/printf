#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_unsigned - main function to prints
 * an unsigned integer argument in decimal format.
 * @args: A va_list of arguments.
 *
 * Return: number of printed characters.
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num_digits = count_digits(n);
	int printed_chars = 0;
	int x = num_digits - 1;
	char buffer[20];

	if (n == 0)
		printed_chars += putchar('0');

	while (n > 0)
	{
		buffer[x--] = (n % 10) + '0';
		n /= 10;
	}

	for (; x < num_digits; x++)
	{
		printed_chars += putchar(buffer[x]);
	}

	return (printed_chars);
}

/**
 * print_octal - a function that prints an
 * unsigned integer argument in octal format.
 * @args: A va_list of arguments.
 *
 * Return: number of printed chars.
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num_digits = count_digits(n);
	int printed_chars = 0;
	int x = num_digits - 1;
	char buffer[20];

	if (n == 0)
		printed_chars += putchar('0');
	while (n > 0)
	{
		buffer[x--] = (n % 8) + '0';
		n /= 8;
	}

	for (; x < num_digits; x++)
	{
		printed_chars += putchar(buffer[x]);
	}

	return (printed_chars);
}

/**
 * print_hex - main function to print an unsigned
 * integer argument in hexadecimal format.
 * @args: A va_list of arguments.
 * @uppercase: flag indicate whether to use uppercase
 * letters for hexadecimal digits.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args, int uppercase)
{
	unsigned int n = va_arg(args, unsigned int);
	int num_digits = count_digits(n);
	int printed_chars = 0;
	int x = num_digits - 1;
	char buffer[20];

	if (n == 0)
		printed_chars += putchar('0');
	while (n > 0)
	{
	int digit = n % 16;

	buffer[x--] = digit < 10 ? digit + '0' : digit + (uppercase ? 'A' : 'a') - 10;
	n /= 16;
	}

	for (; x < num_digits; x++)
	{
		printed_chars += putchar(buffer[x]);
	}

	return (printed_chars);
}
