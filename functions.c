#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

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

/**
 * print_s - prints the string, char by char
 * @print: list of arguments, va_list
 * Return: the number of printed chars, int
 */
int print_s(va_list print)
{
	size_t i;
	char *str = va_arg(print, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; i < str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}
