#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
int handle_spec(char spec, va_list args);

/**
 * _printf - prints characters
 * @format: char format
 *
 * Return: printed_char if success fail otherwise
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	const char *current_char;
	int printed_chars_for_spec;

	/* start list */
	va_start(args, format);
	current_char = format;
	while (*current_char)
	{
		if (*current_char == '%')
		{
			current_char++;
			printed_chars_for_spec = handle_spec(*current_char, args);
			printed_chars += printed_chars_for_spec;
		} else
		{
			printed_chars += write(1, current_char, 1);
		}
		current_char++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * handle_spec - handle each specific case
 * @spec: specific case
 * @args: argument passed
 *
 * Return: Printed chars if success
 */
int handle_spec(char spec, va_list args)
{
	int printed_chars = 0;
	int len = 0;

	switch (spec)
	{
		case 'c':
		{
			char c = va_arg(args, int);

			printed_chars += write(1, &c, 1);
			break;
		}
		case 's':
		{
			char *s = va_arg(args, char *);

			if (s == NULL)
			{
				printed_chars += write(1, "(nil)", 6);
			} else
			{
				while (s[len])
					(len)++;
				printed_chars += write(1, s, len);
			}
			break;
		}
		case '%':
		{
			char percent = '%';

			printed_chars += write(1, &percent, 1);
			break;
		}
		default: {
			printed_chars += write(1, &spec, 1);
			break;
		}
	}
	return (printed_chars);
}
