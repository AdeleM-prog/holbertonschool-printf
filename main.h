#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

struct spec
{
  char spec;
  int (*f)(va_list);
};

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif
