#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct format_s - A new type defining a format struct.
 * @fcase: checked cases.
 * @fun: function pointer to checked cases.
 */
typedef struct format_s
{
	char fcase;
	int (*fun)(va_list, char[], int, int, int, int);
} format_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_write_char(char c, char buffer[], int flags, int width,
int precision, int size);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);
int is_printable(char);
long int convert_size_number(long int num, int size);


#endif
