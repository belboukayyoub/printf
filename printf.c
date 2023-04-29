#include "main.h"

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

	switch (format[*i + 1])
	{
		case 'c':
			printed_char += _putchar(va_arg(args, int));
			break;
		case 's':
			printed_char += print_string(va_arg(args, char *));
		break;
		case 'S':
			printed_char += print_unprintable(va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			printed_char += print_integer(va_arg(args, int));
			break;
		case 'b':
		case 'o':
		case 'u':
			printed_char += print_base(va_arg(args, unsigned int),
					(format[*i + 1] == 'b') ? 2 : (format[*i + 1] == 'o') ? 8 : 10);
			break;
		case 'x':
		case 'X':
			printed_char += print_hexadecimal(va_arg(args, unsigned int),
					(format[*i + 1] == 'x') ? 'a' : 'A');
			break;
		case '%':
			_putchar('%');
			printed_char++;
			break;
		default:
			_putchar(format[*i]);
			printed_char++;
			*i -= 1;
	}
	*i += 1;
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
