#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - main function prints an integer argument.
 * @args: va_list of arguments.
 * @format: pointer to a format string being printed.
 * @buffer: char buffer to hold the formatted output.
 * @buffer_index: pointer to the current index of buffer.
 *
 * Return: number of printed chars.
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int num_digits = count_digits(n);
	int x = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		num_digits++;
	}

	while (x < num_digits)
	{
		_putchar('0' + ((n / power(10, num_digits - x - 1)) % 10));
		x++;
	}

	return (num_digits);
}

/**
 * count_digits - main funtion counts number of digits in an integer.
 * @n: integer to count digits in.
 *
 * Return: number of digits in the integer.
 */
int count_digits(int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return (count == 0 ? 1 : count);
}

/**
 * power - main function calculates result of
 * raising a base to an exponent.
 * @base: base to raise.
 * @exponent: exponent to raise the base to.
 *
 * Return: result of raising the base to the exponent.
 */
int power(int base, int exponent)
{
	int result = 1;

	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}

	return (result);
}
