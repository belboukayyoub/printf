#include "main.h"

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
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

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
 * print_base - prints a number on base
 *
 * @n: input unsigned int
 * @base: input int
 *
 * Return: nbr of char printed
 */

unsigned int print_base(unsigned int n, int base)
{
	unsigned int i = 0, printed_char = 0;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);
	if (n == 0)
	{
		_putchar('0');
		printed_char++;
	}
	while (n > 0)
	{
		digits[i++] = n % base + '0';
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / base;
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
 * print_hexadecimal - prints a hexadecimal
 *
 * @n: input unsigned int
 * @a: input int case specifier
 *
 * Return: nbr of char printed
 */

unsigned int print_hexadecimal(unsigned int n, int a)
{
	unsigned int i = 0, printed_char = 0;
	char *digits = (char *)malloc(sizeof(char));

	if (digits == NULL)
		return (-1);
	if (n == 0)
	{
		_putchar('0');
		printed_char++;
	}
	while (n > 0)
	{
		if (n % 16 < 10)
			digits[i++] = n % 16 + '0';
		else
		{
			digits[i++] = (n % 16) - 10   + a;
		}
		digits = (char *)_realloc(digits, i, i + 1);
		n = n / 16;
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
 * print_unprintable - print a the unprintable as \x followed by the ASCII code
 * value in hexadecimal.
 *
 * @s: input string
 *
 * Return: nbr of char printed
 */
unsigned int print_unprintable(char *s)
{
	unsigned int i, printed_char = 0;

	if (s == NULL)
	{
		return (print_string("(null)"));
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 0)
			s[i] *= -1;
		if ((s[i] > 0  && s[i] < 32) || s[i] >= 127)
		{
			print_string("\\x");
			if (s[i] < 16)
				print_string("0");
			printed_char += print_hexadecimal(s[i], 'A');
		
		}
		else
		{
			_putchar(s[i]);
			printed_char++;
		}
	}
	return (printed_char);
}
