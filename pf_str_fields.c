#include "main.h"

/**
 * get_precision - extracts the precision
 * parameter from a format string
 * @p: pointer to the format string
 * @params: parameters struct to store the precision parameter
 * @ap: va_list containing the variable arguments
 *
 * Return: pointer to the next character in the format
 * string after the precision specifier
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	if (*p == '.')
	{
	p++;
	if (*p == '*')
	{
		params->precision = va_arg(ap, int);
		p++;
	}
	else
	{
		params->precision = 0;
		while (isdigit(*p))
	{
			params->precision = params->precision * 10 + (*p - '0');
			p++;
	}
	}
	}
	else
	{
	params->precision = -1;
	}
	return (p);
}
