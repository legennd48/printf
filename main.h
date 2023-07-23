#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

/**
 * struct format_specifier - structure defining data type of format specifier
 * and the corresponding function
 * @type: the format character
 * @func: function pointer of the corresponfing function
 *
 * Description:this helps to select the function
 * that matches the provided specifier
 */
typedef struct format_specifier
{
	char type;
	int (*func)(va_list);
} specifier;
int print_R(va_list args);
int _strlen(char *s);
int _putchar(char c);
int print_b(va_list args);
int print_c(va_list args);
int print_s(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_S(va_list args);
int print_num(int num);
int print_i(va_list args);
int print_d(va_list args);
int print_u(va_list args);
int print_o(va_list arg);
int print_non_printable(unsigned char ascii);
char *make_buffer(void);
void putstring(char *buffer, int lent);
#endif
