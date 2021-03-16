#include "holberton.h"
#include <stdlib.h>
/**
 * specifier - valid a specifier
 * @format: format
 * Return: valid function or NULL
 */
int (*specifier(const char *format))(va_list)
{
	unsigned int i;

	_format sformat[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_i},
		{"i", print_i},
		{NULL, NULL}};

	for (i = 0; sformat[i].n != '\0'; i++)
	{
		if (*(sformat[i].n) == *format)
		{
			return (sformat[i].func);
		}
	}
	return (NULL);
}
/**
 * _printf - print function
 * @format: format
 * Return: num of chars
 */
int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		unsigned int i = 0;
		unsigned int j = 0;

		va_list _print;

		int (*func)(va_list);

		va_start(_print, format);
		while (format[i])
		{
			while (format[i] != '%' && format[i])
			{
				_putchar(format[i]);
				i++;
				j++;
			}
			if (format[i] == 0)
				return (j);

			func = specifier(&format[i + 1]);

			if (func != NULL)
			{
				j += func(_print);
				i = i + 2;
				continue;
			}

			if (!format[i + 1])
				return (-1);

			_putchar(format[i]);

			j++;

			if (format[i + 1] == '%')
				i = i + 2;
			else
				i++;
		}
		va_end(_print);
		return (j);
	}
	else
	{
		return (-1);
	}
}