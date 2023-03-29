#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct format_s - A new type defining a format struct.
 * @fcase: checked cases.
 * @fun: function pointer to checked cases.
 */
typedef struct format_s
{
	char fcase;
	int (*fun)(va_list, char[], int, int, int ,int);
} format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list args, char buffer[], int flags, int width, int precision, int size);

#endif
