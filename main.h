#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);


/**
 * struct format_specifier - structure defining data type of format specifier
 * and the corresponding function
 * @type: the format character
 * @func: function pointer of thr corresponfing function
 *
 * Description:this helps to select the function
 * that matches the provided specifier
 */
typedef struct format_specifier
{
	char type;
	int (*func)(va_list);
} specifier;

int _putchar(char c);
int print_c(va_list arg);
int print_s(va_list arg);


#endif
