#include "holberton.h"
#include <stdlib.h>

/**
 * _structure - verify a specifier
 * @format: format
 * Return: valid function or NULL
 */
int (*_structure(const char *format))(va_list)
{
	size_t i;

	_format sformat[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_i},
		{"i", print_i},
		{"%", Percent_sign},
		{NULL, NULL}};

	for (i = 0; sformat[i].n != NULL; i++)
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
		size_t i = 0, j = 0;

		va_list _print;

		int (*f)(va_list);

		va_start(_print, format);
		while (format[i])
		{
			while (format[i] != '%' && format[i])
			{
				_putchar(format[i]);
				i++;
				j++;
			}
			if (!format[i])
				return (j);
			f = _structure(&format[i + 1]);

			if (f != NULL)
			{
				j += f(_print);
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
