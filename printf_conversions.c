#include "main.h"

/**
 *print_hex - prints an unsigned integer in hexadecimal format
 *@ap: va_list containing the unsigned integer to print
 *@params: parameters struct containing the width and precision parameters
 *
 *Return: number of characters printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	int width = params->width;
	int precision = params->precision;
	char buffer[50];
	if (precision == 0 && num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
	else
	{
		snprintf(buffer, 50, "%.*x", precision, num);
	}

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
 *print_HEX - prints an unsigned integer in uppercase hexadecimal format
 *@ap: va_list containing the unsigned integer to print
 *@params: parameters struct containing the width and precision parameters
 *
 *Return: number of characters printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	int width = params->width;
	int precision = params->precision;
	char buffer[50];
	if (precision == 0 && num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
	else
	{
		snprintf(buffer, 50, "%.*X", precision, num);
	}

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
 *print_binary - prints an unsigned integer in binary format
 *@ap: va_list containing the unsigned integer to print
 *@params: parameters struct containing the width and precision parameters
 *
 *Return: number of characters printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int num = va_arg(ap, unsigned int);
	int width = params->width;
	int precision = params->precision;
	char buffer[50];
	if (precision == 0 && num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
	else
	{
		int i = 0;
		do { 	buffer[i++] = (num & 1) ? '1' : '0';
			num >>= 1;
		} while (num != 0);
		buffer[i] = '\0';
		int len = strlen(buffer);
		for (int j = 0; j < len / 2; j++)
		{
			char temp = buffer[j];
			buffer[j] = buffer[len - j - 1];
			buffer[len - j - 1] = temp;
		}

		if (precision > i)
		{
			for (int j = i; j < precision; j++)
			{
				buffer[j] = '0';
			}

			buffer[precision] = '\0';
		}
	}

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
