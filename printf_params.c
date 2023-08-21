#include "main.h"

/**
 * init_params - initializes a params_t struct with default values
 * and updates the struct with values from the variable argument list.
 *
 * @params: pointer to the params_t struct
 * @ap: va_list object containing the variable arguments
 */
void init_params(params_t *params, va_list ap)
{
	params->flags = 0;
	params->width = 0;
	params->precision = -1;
	params->length = NONE;
	params->specifier = '\0';

	params->specifier = (char) va_arg(ap, int);
	char *p = &params->specifier;
}
