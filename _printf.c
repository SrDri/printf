#include "holberton.h"
#include <stdlib.h>
/**
 * specifier - valid a specifier
 * @format: format
 * Return: valid function or NULL
 */
int (*specifier(const char *format))(va_list)
{
	unsigned int i, j;

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
	/* while format exist */
	if (format != NULL)
	{
		unsigned int i = 0;
		unsigned int j = 0;

		va_list _print;
		/* function pointer in the .h file */
		int (*func)(va_list);

		va_start(_print, format);
		/*format[i] exist?*/
		while (format[i])
		{
			/* formar != % & != NULL*/
			while (format[i] != '%' && format[i])
			{
				_putchar(format[i]);
				i++;
				j++;
			}
			if (format[i] == 0)
				/* if dont exist, return counter*/
				return (j);
			/*function pointer*/
			func = specifier(&format[i + 1]);
			if (func != NULL)
			{
				j += func(_print);
				i = i + 2;
				/* i+2 para que suba en el fomato del main*/
				/* continue para que cambie de posición*/
				continue;
			}
			/* si format no contiene %*/
			if (format[i + 1] == 0)
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
