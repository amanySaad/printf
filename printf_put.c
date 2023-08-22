#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to a string to be printed
 *
 * Return: number of characters printed (excluding null terminator)
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}

	putchar('\n');

	return (i);
}

/**
 * _putchar - writes a character to stdout
 * @c: character to be written
 *
 * Return: character written as an unsigned
 * char cast to an int or EOF on error
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
