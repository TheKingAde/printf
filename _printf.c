#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
int handle_spec(char spec, va_list args);
int int_to_binary(va_list types);
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
 * int_to_string - convert integer to  string
 * @spec: specific case
 * @args: argument passed
 *
 * Return: Printed chars if success
 */
int handle_spec(char spec, va_list args)
{
	int len = 0;
	int printed_chars;

	switch (spec)
	{
		case 'c':
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			break;
		}
		case 's':
		{
			char *s = va_arg(args, char *);

			if (s == NULL)
			{
				write(1, "(nil)", 5);
				return (5);
			}

			len = 0;
			while (s[len])
				len++;
			write(1, s, len);
			return (len);
		}
		case 'd':
		case 'i':
		{
			int num = va_arg(args, int);
			char buffer[20];
			int num_len = int_to_string(num, buffer);

			write(1, buffer, num_len);
			return (num_len);
		}
		case 'b':
		{
			printed_chars = int_to_binary(args);
			return (printed_chars);
		}
		case '%':
		{
			char percent = '%';

			write(1, &percent, 1);
			return (1);
		}
		default:
		{
			char c = spec;

			write(1, &c, 1);
			return (1);
		}
	}
	return (1);
}
/**
 * int_to_string - turn integer to string
 * @num: integer
 * @buffer: pointer
 *
 * Return: integer
 */
int int_to_string(int num, char *buffer)
{
			int num_len = 0;
			int is_negative = 0;
			char temp_buffer[20];
			int i = 0;
			int j;

			if (num == 0)
			{
				buffer[i++] = '0';
				num_len++;
			}
			else
			{
				if (num < 0)
				{
					is_negative = 1;
					num = -num;
				}
				while (num > 0)
				{
					temp_buffer[i++] = num % 10 + '0';
					num /= 10;
					num_len++;
				}
				if (is_negative)
					temp_buffer[i++] = '-';
			}

			for (j = 0; j < i; j++)
				buffer[j] = temp_buffer[i - j - 1];
			return (num_len + is_negative);
}
/**
 * int_to_binary - turns an integer to binary
 * @types: char types
 *
 * Return: number
 */
int int_to_binary(va_list types)
{
	unsigned int m;
	unsigned int show = 1 << 31;
	int i, number = 0;
	int important_bit_found = 0;

	m = va_arg(types, unsigned int);

	for (i = 0; i < 32; i++)
	{
		char z = (m & show) ? '1' : '0';

		if (z == '1')
			important_bit_found = 1;

		if (important_bit_found)
		{
			write(1, &z, 1);
			number++;
		}
		m <<= 1;
	}
	if (!important_bit_found)
	{
		write(1, "0", 1);
		number++;
	}
	return (number);
}
