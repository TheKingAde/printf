#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_unsigned - prints unsigned integer
 * @args: list of arguments
 * @buffer:pointer
 *
 * Return: number of printed chars
 */


int print_unsigned(va_list args, char *buffer)
{
	int i;
	unsigned int num;
	int count = 0;

	for (i = 0; i < 32; i++)
	{

	va_arg(args, unsigned int);

	if (num == 0)
	{
		buffer[i++] = '0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	va_end(args);
	}
}
return (count);

}
/**
 * unsigned_to_octal - turns unsigned int to octal
 * @args: list of arguments
 * @buffer: pointer
 *
 * Return: printed chars
 */

int unsigned_to_octal(va_list args, char *buffer)
{
	int i;
	unsigned int num;
	int printed = 0;


	va_arg(args, unsigned int);

	for (i = 0; i < 15; i++)
	{
	if (num == 0)
	{
		buffer[i--] = '0';
	while (num > 0)
		{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
		}
	if (num != 0)
	{
		buffer[i--] = '0';

	}
	va_end(args);
	}
	}
	return (printed);
}
/**
 * unsignd_to_hexa - turns unsigned to hexadecimal
 * print_hexa - prints hexadecimal
 * @args: list of arguments
 * @buffer: pointer
 *
 * Return: printed chars
 */

int unsignd_to_hexa(va_list args, char *buffer)
{
	int i = 12;
	int j = 0;
	unsigned int num;
	int base = 0;
	
	int printed = 0;

	va_arg(args, unsigned int);

	do {

	buffer[i] = "0123456789abcdef"[num % base];
	i--;
	num = num / base;
	}
	while (num > 0);
	{
		if (num != 0)
		{
			buffer[0] = num;
			++j;
		}
		while (++i < 13)
		{
			buffer[j++] = buffer[i];
		}

		buffer[j] = 0;
	}

return (printed);
}
/**
 * unsignd_to_hexa_upper - prints an unsigned number in upper hexadecimal 
 * @args: list of arguments
 * @buffer: pointer
 *
 * Return; printed chars
 */

int unisgnd_to_hexa_upper(va_list args, char *buffer)
{
	int i = 12;
	int j = 0;
	unsigned int num;
	int base = 0;

	int printed = 0;

	va_arg(args, unsigned int);

	do{
		buffer[i] = "0123456789ABCDEFGHIJ"[num % base];
		i--;
		num = num / base;
	}
	while (num > 0);
	{
		if (num != 0)
		{
			buffer[0] = num;
			++j;
		}
		while (++i <13)
		{
			buffer[j++] = buffer[i];
		}
		buffer[j] = 0;
	}
	return (printed);
}
