#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_spec(char spec, va_list args);
int int_to_string(int num, char *buffer);
int int_to_binary(va_list types);
int print_unsigned(va_list args, char buffer[]);
int unsigned_to_octal(va_list args, char *buffer);
int unsignd_to_hexa(va_list args, char *buffer);
int unisgnd_to_hexa_upper(va_list args, char *buffer);
#endif
