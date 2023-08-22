#include "main.h"

/**
 * _isdigit - Checks if the given character is a digit.
 *
 * @c: The character to check.
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (isdigit(c));
}

/**
 * _strlen - Calculates the length of the given string.
 *
 * @s: The string to calculate the length of.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * print_number - prints the integer value of the given string to the console.
 *
 * @str: The string containing the integer value to print.
 * @params: Pointer to the parameters struct (unused).
 * Return: The length of the original string.
 */
int print_number(char *str, params_t *params)
{
	int num = atoi(str);

	printf("%d", num);
	return (_strlen(str));
}
/**
 * print_number_right_shift - prints the integer value
 * of the given string with leading spaces to
 * fill the specified width.
 *
 * @str: The string containing the integer value to print.
 * @params: Pointer to the parameters struct
 * containing the width parameter.
 * Return: The length of the original string.
 */
int print_number_right_shift(char *str, params_t *params)
{
	int num = atoi(str);
	int width = params->width;
	int len = snprintf(NULL, 0, "%d", num);

	if (len >= width)
	{
		printf("%d", num);
	}
	else
	{
	for (int i = 0; i < width - len; i++)
	{
		printf(" ");
	}
	printf("%d", num);
	}
	return (len);
}

/**
 * print_number_left_shift - prints the integer value
 * of the given string with trailing spaces to fill
 * the specified width.
 *
 * @str: The string containing the integer value to print.
 * @params: Pointer to the parameters struct containing the width parameter.
 * Return: The length of the original string.
 */
int print_number_left_shift(char *str, params_t *params)
{
	int num = atoi(str);
	int width = params->width;
	int len = snprintf(NULL, 0, "%d", num);

	if (len >= width)
	{
	printf("%d", num);
	}
	else
	{
		printf("%d", num);
	for (int i = 0; i < width - len; i++)
	{
		printf(" ");
	}
	}
	return (len);
}
