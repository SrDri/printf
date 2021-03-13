#include <stdarg.h>
/**
 * print_c - print a char
 * @print: list of arguments
 * Return: 1
 */
int print_c(va_list print)
{
	char c;

	c = (char)va_arg(print, int);
	_putchar(c);
	return (1);
}
