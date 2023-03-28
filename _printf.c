#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/*
 * case_c - function prints character.
 * @args: input arguments.
 *
 * Return: number of characters printed
 */
int case_c(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);
	return (1);
}

/*
 * case_s - function prints sting.
 * @args: input agruments.
 *
 * Return: number of characters printed.
 */
int case_s(va_list args)
{
	char *str = va_arg(args, char*);
	int counter = 0;

	for (; *str; str++, counter++)
		putchar(*str);
	return (counter);
}

/*
 * case_mod - function prints modulus(%).
 * @args: input arguments.
 *
 * Return: number of characters printed.
 */
int case_mod(va_list __attribute__((unused)) args)
{
	putchar('%');
	return (1);
}

/*
 * _printf - function that produces output according to a format.
 * @format: a character string. The format string is composed of
 * zero or more directives.
 * @...: arguments
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, counter = 0;
	va_list args;
	format_t formats[] = {
		{'c', case_c}, {'s', case_s}, {'%', case_mod}, {0, NULL}
	};

	if (!format)
		return (-1);

	va_start(args, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			putchar(*format);
			counter++;
			continue;
		}
		format++;
		for (i = 0; formats[i].fcase; i++)
			if (formats[i].fcase == *format)
				counter += formats[i].fun(args);
	}

	va_end(args);
	return (counter);
}
