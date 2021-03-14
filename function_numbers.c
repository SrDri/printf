#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_i - print an integer and decimal
 * @print: list of arguments
 * Return: 
 */
<<<<<<< HEAD
int print_i(va_list arg)
{
	int a, i = 0, temp;
	int factor = 1;

	a = va_arg(arg, int);
	if (a <= INT_MAX && a >= INT_MIN - 1)
	{
		if (a < 0)
		{
			a = a * (-1);
			_putchar('-');
			i++;
		}
		temp = a;
		i = 0;
		while (temp)
		{
			temp = temp / 10;
			factor = factor * 10;
		}
		while (factor > 1)
		{
			factor = factor / 10;
			_putchar((a / factor) + '0');
			a = a % factor;
			i++;
		}
		return (i);
	}
	else
	{
		return (-1);
	}
=======
int print_i(va_list print)
{
>>>>>>> 6e11183cfda9eb1f34b58d09c1b0ab7f6a9c217f
}
