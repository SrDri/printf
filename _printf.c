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
	unsigned int i = 0;
	unsigned int j = 0;
	va_list _print;
	int (*func)(va_list);

	va_start(_print, format);
	i = 0;
	if (format == NULL)
		return (-1);
	while (format)
	{
		while (format[i] && format[i] != '\0')
		{
			_putchar(format[i]);
			i++;
			j++;
		}
		if (format[i] == 0)
			return (j);
		/* se manda la direccion de i + 1 porque */
		/* va despues del especificador % */
		/* func es el puntero a la función de la estrecutura */
		func = specifier(&format[i + 1]);
		if (func != NULL)
		{
			/* se suma para sumar la lista */
			j = j + func(_print);
			/* se incrementa porque despues hay otro */
			/* otro especifiador en el main */
			i = i + 2;
			continue;
			/* necesita avanzar posiciones */
			if (format[i + 1] == 0)
				return (-1);
			_putchar(format[i]);
			j++;
			if (format[i + 1] == '%')
				i = i + 2;
			else
				i++;
		}
	}
	va_end(_print);
	return (j);
}
