#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);

/**
 * struct format_s - A new type defining a format struct.
 * @fcase: checked cases.
 * @fun: function pointer to checked cases.
 */
typedef struct format_s
{
	char fcase;
	int (*fun)(va_list);
} format_t;

#endif
