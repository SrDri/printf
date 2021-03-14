#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "holberton.h"

/**
 * print_i - print an integer and decimal
 * @print: list of arguments
 * Return: i int
 */
int print_i(va_list print)
{
	int a, i = 0, aux;
	int factor = 1;

	a = va_arg(print, int);
	if (a <= INT_MAX && a >= INT_MIN - 1)
	{
		if (a < 0)
		{
			a = a * (-1);
			_putchar('-');
			i++;
		}
		aux = a;
		i = 0;
		while (aux)
		{
			aux = aux / 10;
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
}
