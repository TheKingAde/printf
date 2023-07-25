#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_spec(char spec, va_list args);
int int_to_string(int num, char *buffer);
int int_to_binary(va_list types);
#endif
