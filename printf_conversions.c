#include "main.h"

/**
 * print_hex - prints an unsigned integer in hexadecimal format
 * @ap: va_list containing the unsigned integer to print
 * @params: parameters struct containing the width and precision parameters
 *
 * Return: number of characters printed
 */
int print_hex(va_list ap, params_t *params) {
    unsigned int num = va_arg(ap, unsigned int);
    int width = params->width;
    int precision = params->precision; // get the precision parameter from the params struct
    char buffer[50]; // allocate a buffer to hold the formatted string
    if (precision == 0 && num == 0) { // special case: num is zero with zero precision
        buffer[0] = '0';
        buffer[1] = '\0';
    } else { // normal case: format num as a hexadecimal string
        snprintf(buffer, 50, "%.*x", precision, num); // format the integer as a hexadecimal string with the specified precision
    }
    int len = strlen(buffer); // get the length of the formatted string
    if (len < width) { // if the length of the formatted string is less than the width, pad with spaces
        for (int i = 0; i < width - len; i++) {
            putchar(' ');
        }
    }
    fputs(buffer, stdout); // print the formatted string to stdout
    return len; // return the number of characters printed
}
/**
 * print_HEX - prints an unsigned integer in uppercase hexadecimal format
 * @ap: va_list containing the unsigned integer to print
 * @params: parameters struct containing the width and precision parameters
 *
 * Return: number of characters printed
 */
int print_HEX(va_list ap, params_t *params) {
    unsigned int num = va_arg(ap, unsigned int); // get the unsigned integer argument from the variable argument list
    int width = params->width; // get the width parameter from the params struct
    int precision = params->precision; // get the precision parameter from the params struct
    char buffer[50]; // allocate a buffer to hold the formatted string
    if (precision == 0 && num == 0) { // special case: num is zero with zero precision
        buffer[0] = '0';
        buffer[1] = '\0';
    } else { // normal case: format num as an uppercase hexadecimal string
        snprintf(buffer, 50, "%.*X", precision, num); // format the integer as an uppercase hexadecimal string with the specified precision
    }
    int len = strlen(buffer); // get the length of the formatted string
    if (len < width) { // if the length of the formatted string is less than the width, pad with spaces
        for (int i = 0; i < width - len; i++) {
            putchar(' ');
        }
    }
    fputs(buffer, stdout); // print the formatted string to stdout
    return len; // return the number of characters printed
}

/**
 * print_binary - prints an unsigned integer in binary format
 * @ap: va_list containing the unsigned integer to print
 * @params: parameters struct containing the width and precision parameters
 *
 * Return: number of characters printed
 */
int print_binary(va_list ap, params_t *params) {
    unsigned int num = va_arg(ap, unsigned int); // get the unsigned integer argument from the variable argument list
    int width = params->width; // get the width parameter from the params struct
    int precision = params->precision; // get the precision parameter from the params struct
    char buffer[50]; // allocate a buffer to hold the formatted string
    if (precision == 0 && num == 0) { // special case: num is zero with zero precision
        buffer[0] = '0';
        buffer[1] = '\0';
    } else { // normal case: format num as a binary string
        int i = 0;
        do {
            buffer[i++] = (num & 1) ? '1' : '0';
            num >>= 1;
        } while (num != 0);
        buffer[i] = '\0';
        int len = strlen(buffer);
        for (int j = 0; j < len / 2; j++) { // reverse the string to get the correct binary representation
            char temp = buffer[j];
            buffer[j] = buffer[len - j - 1];
            buffer[len - j - 1] = temp;
        }
        if (precision > i) { // if the precision is greater than the number of binary digits, pad with zeros
            for (int j = i; j < precision; j++) {
                buffer[j] = '0';
            }
            buffer[precision] = '\0';
        }
    }
    int len = strlen(buffer); // get the length of the formatted string
    if (len < width) { // if the length of the formatted string is less than the width, pad with spaces
        for (int i = 0; i < width - len; i++) {
            putchar(' ');
        }
    }
    fputs(buffer, stdout); // print the formatted string to stdout
    return len; // return the number of characters printed
}
