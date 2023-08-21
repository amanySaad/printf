#include "main.h"

/**
 * print_from_to - prints the characters in the range
 * [start, stop), except for any characters
 * that are also in the string pointed to by except.
 *
 * @start: The start of the character range to print.
 * @stop: The end of the character range to print (not inclusive).
 * @except: A string containing characters to exclude from the output.
 * Return: The number of characters that were printed.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int count = 0;

	while (start < stop)
	{
	if (!strchr(except, *start))
	{
		putchar(*start);
		count++;
	}
	start++;
	}
	return (count);
}

/**
 * print_rev - prints the reverse of the string argument.
 *
 * @ap: The va_list containing the arguments.
 * @params: Pointer to the parameters struct.
 * Return: The length of the original string.
 */
int print_rev(va_list ap)
{
	char *str = va_arg(ap, char*);
	int len = strlen(str);
	char *rev = malloc(len + 1);

	for (int i = 0; i < len; i++)
	{
		rev[i] = str[len - i - 1];
	}
	rev[len] = '\0';
	printf("%s", rev);
	free(rev);
	return (len);
}

/**
 * print_rot13 - prints the ROT13-encoded version
 * of the string argument.
 *
 * @ap: The va_list containing the arguments.
 * @params: Pointer to the parameters struct.
 * Return: The length of the original string.
 */
int print_rot13(va_list ap)
{
	char *str = va_arg(ap, char*);
	int len = strlen(str);
	char *rot13 = malloc(len + 1);

	for (int i = 0; i < len; i++)
	{
	if (isalpha(str[i]))
	{
		if (islower(str[i]))
		{
		rot13[i] = 'a' + (str[i] - 'a' + 13) % 26;
		}
		else
		{
		rot13[i] = 'A' + (str[i] - 'A' + 13) % 26;
		}
	}
	else
	{
	rot13[i] = str[i];
	}
	}
	rot13[len] = '\0';
	printf("%s", rot13);
	free(rot13);
	return (len);
}
