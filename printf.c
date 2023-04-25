#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer void
 * @old_size: unsigned int
 * @new_size: unsigned int
 *
 * Return: the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, tp = new_size;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size > old_size)
		tp = old_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);

	for (i = 0; i < tp; i++)
	{
		p[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (p);
}

/**
 * print_integer - prints an integer
 * @num: intut int
 *
 * Return: nbr of chart printed
 */

unsigned int print_integer(int num)
{
	unsigned int i = 0, printed_char = 0, n;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);

	if (num < 0)
	{
		_putchar('-');
		printed_char++;
		n = num * (-1);
	}
	else
		n = num;

	while (n > 0)
	{
		digits[i++] = n % 10 + '0';
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / 10;
	}
	while (i > 0)
	{
		_putchar(digits[--i]);
		printed_char++;
	}
	free(digits);
	return (printed_char);
}

/**
 * print_string - print a static string
 *
 * @s: input string
 *
 * Return: nbr of char printed
 */
unsigned int print_string(char *s)
{
	unsigned int i, printed_char = 0;

	if (s == NULL)
	{
		return (print_string("(null)"));
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		printed_char++;
	}

	return (printed_char);
}

/**
 * format_printf - format string
 * @args: input va_list
 * @format: input string
 * @i: input int
 *
 * Return: nbr of char printed
 */
unsigned int format_printf(va_list args, const char *format, unsigned int *i)
{
	unsigned int printed_char = 0;

	if (format[*i + 1] == 'c')
	{
		_putchar(va_arg(args, int));
		printed_char++;
		*i += 1;
	}
	else if (format[*i + 1] == 's')
	{
		printed_char += print_string(va_arg(args, char *));
		*i += 1;
	}
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
	{
		printed_char += print_integer(va_arg(args, int));
		*i += 1;
	}
	else if (format[*i + 1] == '%')
	{
		_putchar('%');
		printed_char++;
		*i += 1;
	}
	else
	{
		_putchar(format[*i]);
		printed_char++;
	}
	return (printed_char);
}

/**
 * _printf - clone of printf
 *
 * @format: input string
 *
 * Return: nbr of char printed
 */

int _printf(const char *format, ...)
{
	unsigned int i, printed_char = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			printed_char += format_printf(args, format, &i);

		}
		else
		{
			_putchar(format[i]);
			printed_char++;
		}
	}
	va_end(args);
	return (printed_char);
}
