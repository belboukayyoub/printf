#include "main.h"
#include <stdarg.h>
#include <stddef.h>

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
* Return:  nbr of char printed
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
