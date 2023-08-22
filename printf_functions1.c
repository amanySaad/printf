#include "main.h"

/**
 * print_char - prints a single character
 * @ap: va_list containing the character to print
 * @params: parameters struct
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list ap, params_t *params)
{
	char c = va_arg(ap, int);

	putchar(c);
	return (1);
}

/**
 * print_int - prints an integer
 * @ap: va_list containing the integer to print
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_int(va_list ap, params_t *params)
{
	int num = va_arg(ap, int);
	int width = params->width;
	int precision = params->precision;
	char buffer[50];

	snprintf(buffer, 50, "%.*d", precision, num);

	int len = strlen(buffer);

	if (len < width)
	{
	for (int i = 0; i < width - len; i++)
	{
		putchar(' ');
	}
	}
	fputs(buffer, stdout);
	return (len);
}

/**
 * print_string - prints a string
 * @ap: va_list containing the string to print
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int width = params->width;
	int precision = params->precision;
	int len = strlen(str);

	if (precision >= 0 && precision < len)
	{
		len = precision;
	}
	if (len < width)
	{
	for (int i = 0; i < width - len; i++)
	{
		putchar(' ');
	}
	}
	for (int i = 0; i < len; i++)
	{
		putchar(str[i]);
	}
	return (len);
}

/**
 * print_percent - prints a percent sign
 * @ap: va_list containing no arguments
 * @params: parameters struct
 *
 * Return: number of characters printed (always 1)
 */
int print_percent(va_list ap, params_t *params)
{
	putchar('%');
	return (1);
}

/**
 * print_S - prints a string, replacing non-printable
 * characters with escape codes
 * @ap: va_list containing the string to print
 * @params: parameters struct (unused)
 *
 * Return: number of characters printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int width = params->width;
	int len = strlen(str);
	int count = 0;

	for (int i = 0; i < len; i++)
	{
	if (isprint(str[i]))
	{
		putchar(str[i]);
		count++;
	}
	else
	{
		putchar('\\');
		putchar('x');
		printf("%02X", (unsigned char)str[i]);
		count += 4;
	}
	if (count >= width)
	{
		break;
	}
	}
	return (count);
}
