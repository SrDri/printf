#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * print_c - print a char
 * @_print: list of arguments
 * Return: 1
 */
int print_c(va_list _print)
{
	_putchar(va_arg(_print, int));
	return (1);
}

/**
 * print_s - prints the string, char by char
 * @_print: list of arguments, va_list
 * Return: the number of printed chars, int
 */
int print_s(va_list _print)
{
	unsigned int i;
	char *str = va_arg(_print, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}
/**
 * Percent_sign - print a percent a percent sign
 * @_print: list of arguments
 * Return: expected a variable to be unused
 */
int Percent_sign(__attribute__((unused)) va_list _print)
{
	_putchar(37);
	return (1);
}
