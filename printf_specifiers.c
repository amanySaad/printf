#include "main.h"
/*
 *Get specifier function:
 *Takes a format specifier character and returns a pointer to the appropriate
 *printing function. If the specifier is invalid, it returns NULL.
 */
int(*get_specifier(char *s))(va_list ap, params_t *params)
{
	switch (*s)
	{
		case 'd':
		case 'i':
			return (print_decimal);
		case 'u':
			return (print_unsigned_decimal);
		case 'o':
			return (print_octal);
		case 'x':
		case 'X':
			return (print_hexadecimal);
		case 'c':
			return (print_character);
		case 's':
			return (print_string);
		default:
			return (NULL);
	}
}

/*
 *Get print function:
 *Takes a format string, a va_list of arguments, and a params_t struct.
 *Returns the number of characters printed, or -1 if an error occurred.
 */
int
get_print_func(char *s, va_list ap, params_t *params)
{
	int count = 0;
	if (*s == 'c')
	{
		char c = (char) va_arg(ap, int);
		putchar(c);
		count++;
	}
	else if (*s == 's')
	{
		char *str = va_arg(ap, char *);
		count += printf("%s", str);
	}

	return (count);
}

/*
 *Get flag function:
 *Takes a character and a params_t struct and sets the appropriate flag in the
 *struct if the character is a valid flag. Returns the number of characters consumed.
 */
int
get_flag(char *s, params_t *params)
{
	switch (*s)
	{
		case '-':
			params->flags |= LEFT_JUSTIFY;
			return (1);
		case '+':
			params->flags |= SHOW_SIGN;
			return (1);
		case ' ':
			params->flags |= SPACE_SIGN;
			return (1);
		case '#':
			params->flags |= ALT_FORM;
			return (1);
		case '0':
			params->flags |= ZERO_PAD;
			return (1);
		default:
			return (0);
	}
}

/*
 *Get modifier function:
 *Takes a character and a params_t struct and sets the appropriate modifier in
 *the struct if the character is a valid modifier. Returns the number of characters consumed.
 */
int
get_modifier(char *s, params_t *params)
{
	switch (*s)
	{
		case 'h':
			if (*(s + 1) == 'h')
			{
				params->flags |= CHAR_MODIFIER;
				return (2);
			}
			else
			{
				params->flags |= SHORT_MODIFIER;
				return (1);
			}

		case 'l':
			if (*(s + 1) == 'l')
			{
				params->flags |= LONG_LONG_MODIFIER;
				return (2);
			}
			else
			{
				params->flags |= LONG_MODIFIER;
				return (1);
			}

		case 'j':
			params->flags |= INTMAX_MODIFIER;
			return (1);
		case 'z':
			params->flags |= SIZE_MODIFIER;
			return (1);
		case 't':
			params->flags |= PTRDIFF_MODIFIER;
			return (1);
		default:
			return (0);
	}
}

/*
 *Get width function:
 *Takes a format string, a va_list of arguments, and a params_t struct.
 *Parses the width specifier and returns a pointer to the next character in the
 *string, after consuming any width specifier characters.
 *If no width specifier is present, it returns the original string pointer.
 */
char *
	get_width(char *s, params_t *params, va_list ap)
	{
		char *width_str = NULL;
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
				s++;
			width_str = malloc(s - width_str + 1);
			strncpy(width_str, s, s - width_str);;
			width_str[s - width_str] = '\0';
		}
		else if (*s == '*')
		{
			int width = va_arg(ap, int);
			width_str = malloc(12);
			sprintf(width_str, "%d", width);
		}

		return (width_str);
	}
