#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define BUFF_SIZE 1024
#define BUF_FLUSH -1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 1
#define S_SHORT 2

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define LEFT_JUSTIFY           0x01
#define SHOW_SIGN              0x02
#define SPACE_SIGN             0x04
#define ALT_FORM               0x08
#define ZERO_PAD               0x10

#define CHAR_MODIFIER          0x01
#define SHORT_MODIFIER         0x02
#define LONG_MODIFIER          0x03
#define LONG_LONG_MODIFIER     0x04
#define INTMAX_MODIFIER        0x05
#define SIZE_MODIFIER          0x06
#define PTRDIFF_MODIFIER       0x07

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct params_s
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;
	unsigned int left_align		: 1;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/**
 * struct parameters - struct containing information
 * about printf parameters
 * @flags: flags used to modify the output format
 * @width: minimum field width to print
 * @precision: precision of the output format
 * @length: length modifier for integer types
 */
typedef struct parameters
{
	char flags;
	int width;
	int precision;
	char length;
} parameters_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* printf_functions1.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* printf_functions2.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params_t);
int print_address(va_list ap, params_t *params);

/* printf_specifiers.c */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* printf_conversions.c */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* printf_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap);
int print_rot13(va_list ap);

/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* printf_params.c */
void init_params(params_t *params, va_list ap);

/* pf_str_fields.c */
/*char *get_precision(char *p, params_t *params, va_list ap);*/

/* prinf.c */
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *format, int *i, va_list list,
	char buffer[], int flags, int width, int precision, int size);

#endif
