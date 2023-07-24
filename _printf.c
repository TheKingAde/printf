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
	/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
}
