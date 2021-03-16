#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * print_i - print an integer and decimal
 * @_print: list of arguments
 * Return: i - len
 */
int print_i(va_list _print)
{
	int n, aux, i;
	int count = 0;
	char arg;

	n = va_arg(_print, int);

	if (n < 0)
	{
		aux = -n;
		write(1, "-", 1);
		count++;
	}
	else
		aux = n;
	for (i = 1; i <= cifras(aux); i++)
	{
		arg = ((aux / (_pow(10, cifras(aux) - i))) % 10) + 48;
		write(1, &arg, 1);
		count++;
	}
	return (count);
}
/**
 * cifras - numero de cifras
 * @n: number
 * Return: count
 */
int cifras(int n)
{
	int count = 1;
	int control = 10;

	if (n < 0)
	{
		n = -n;
	}
	while (control <= n)
	{
		count++;
		control = control * 10;
	}
	return (count);
}
/**
 * _pow - potentiation
 * @x: num x
 * @y: num y
 * Return: function
 */
int _pow(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	return (x * _pow(x, y - 1));
}
