#include "main.h"

/**
 * convert - converts the given number to a string
 * in the specified base and with the specified
 * flags and precision.
 *
 * @num: The number to convert.
 * @base: The base to use for conversion (2-36).
 * @flags: The flags to use for conversion
 * (bit 0: '#', bit 1: '+', bit 2: ' ').
 * @params: Pointer to the parameters struct containing
 * the precision parameter.
 * Return: A pointer to a static buffer containing
 * the converted string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char buffer[50];
	char *ptr = &buffer[49];
	*ptr = '\0';
	int precision = params->precision;

	do {
	int digit = num % base;

	if (digit < 10)
	{
	*--ptr = digit + '0';
	}
	else
	{
	*--ptr = digit + 'A' - 10;
	}
	num /= base;
	precision--;
	} while (num != 0);

	if (flags & 0x01 && base == 16)
	{
	*--ptr = 'x';
	*--ptr = '0';
	}
	else if (flags & 0x02 && base == 8)
	{
	*--ptr = '0';
	}
	while (precision-- > 0)
	{
	*--ptr = '0';
	}
	return (ptr);
}

/**
 * print_unsigned - prints an unsigned integer value
 * with the specified parameters.
 *
 * @ap: The variable argument list containing the value to print.
 * @params_t: Pointer to the parameters struct
 * containing the width and precision parameters.
 * Return: The number of characters printed.
 */
int print_unsigned(va_list ap, params_t *params_t)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *str = convert(num, 10, 0, params_t);
	int len = strlen(str);
	int width = params_t->width;

	if (len >= width)
	{
		printf("%s", str);
	}
	else
	{
		int padding = width - len;

		if (params_t->precision >= 0)
		{
			padding = params_t->precision - len;
		}
		if (padding > 0)
		{
			for (int i = 0; i < padding; i++)
			{
				printf(" ");
			}
		}
		printf("%s", str);
	}
	return (len);
}

/**
 * print_address - prints a pointer address in
 * hexadecimal format with the specified parameters.
 *
 * @ap: The variable argument list containing
 * the pointer address to print.
 * @params: Pointer to the parameters struct
 * containing the width parameter.
 * Return: The number of characters printed.
 */
int print_address(va_list ap, params_t *params)
{
	uintptr_t addr = (uintptr_t) va_arg(ap, void*);
	char *str = convert(addr, 16, 0x01, params);

	printf("%s", str);
	return (strlen(str));
}
