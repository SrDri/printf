#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - printf function
 * @format: is a %argument
 * Return: int number of arguments
 */
int _printf(const char *format, ...)
{
	int i, j;
	int a = 0;
	_format sformat[] = {
		{"c", print_c},
		{"i", print_i},
		{"s", print_s},
		{"d", print_i},
		{"%", Percent_sign},
		{NULL, NULL}};
	va_list print;

	va_start(print, format);
	i = 0;
	if (format == NULL)
		return (-1);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			j = 0;
			while (sformat[j].n != '\0')
			{
				if (format[i] == sformat[j].n[0])
				{
				}
			}
		}
		j++;
		i++;
	}
	va_end(print);
	return ();
}
