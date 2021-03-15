#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_i - print an integer and decimal
 * @print: list of arguments
 * Return: i - len
 */
int print_i(va_list print)
{
	int a, count = 1, len = 0;
	unsigned int n;
	char ar;

	a = va_arg(print, int);

	if (a < 0)
	{
		ar = '-';
		len = len + _putchar(ar);
		n = a * -1;
	}
	else
		n = a;
	while (n / count > 9)
		count *= 10;

	while (count != 0)
	{
		ar = n / count + '0';
		len = len + _putchar(ar);
		n = n % count;
		count = count / 10;
	}
	return (len);
}
