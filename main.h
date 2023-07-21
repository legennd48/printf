#ifndef _MAIN_H_
#define _MAIN_H_

int _printf(const char *format, ...);

typedef struct formats
{
	char specifier;
	void (*func)(va_list);
} form;





#endif
