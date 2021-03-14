#ifndef _HOLBERTON_H_
#define _HOLBERTON H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct _format - Struct for formats
 *
 * @n: The format
 * @func: The function associated
 * function pointer
 */
typedef struct _format
{
	char *n;
	int (*func)();
} _format;
/* its int because number of arguments */
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list print);
int print_s(va_list print);
int Percent_sign(__attribute__((unused)) va_list print);
int print_i(va_list print);

#endif /* _HOLBERTON_H_ */
