#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * convert - main function that converts a given
 * number to a string in the specified base and
 * with the specified flags and precision.
 *
 * @num: number to convert.
 * @base: base to be used for conversion (2-36).
 * @flags: flags to be used for conversion
 * @precision: precision value.
 *
 * Return: pointer to a static buffer contain
 * the converted string.
 */
char *convert(long int num, int base, int flags, int precision)
{
	static char buffer[50];
	char *ptr = &buffer[49];
	*ptr = '\0';

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
		}
	while (num != 0);

	while (precision-- > 0)
	{
		*--ptr = '0';
	}

	if (flags & 0x01 && base == 16)
	{
		*--ptr = 'x';
		*--ptr = '0';
	}
	else if (flags & 0x02 && base == 8)
	{
		*--ptr = '0';
	}

	return (ptr);
}
