#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int add_to_buffer(char *buffer, int *buffer_index, char c);
int _putchar(char c);
int _printf(const char *format, ...);
int format_parser(const char *format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int count_digits(int n);
int power(int base, int exponent);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_number(char *buffer, int n);
int print_int(va_list args);
int print_custom_string(va_list args, char *buffer,
	int *buffer_index);
int print_pointer(va_list args, char *buffer,
	int *buffer_index);
int parse_flags(const char **format);
int print_int_with_flags(va_list args, char *buffer,
	int *buffer_index, int flags);
int print_unsigned_with_flags(va_list args, char *buffer,
	int *buffer_index, int flags);
int print_int_with_length_width_precision_and_flags
	(va_list args, char *buffer, int *buffer_index,
		int length, int width, int precision, int flags);
void my_printf(const char *format, ...);
void print_reversed_string(char *format, ...);
char *convert(long int num, int base, int flags, int precision);
int print_rot13_string(va_list args, char *buffer,
	int *buffer_index);
void print_arg(const char *format, va_list arg);
int print_padding(char *buffer, int *buffer_index,
	int num_spaces, char padding_char);

#endif
