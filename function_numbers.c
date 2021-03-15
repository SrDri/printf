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
	int a, expo = 1, len = 0;
	unsigned int n;
	char ar;

	a = va_arg(print, int);

	if (a < 0)
	{
		ar = '-';
		len = len + write(1, &ar, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		ar = n / expo + '0';
		len = len + write(1, &ar, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
