#ifndef _MAIN_H_
#define _MAIN_H_

int _printf(const char *format, ...);
int _putchar(char c);

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
	void (*func)(va_list);
} specifier;


int print_s(va_list args);

#endif
