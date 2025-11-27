#include <stddef.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a single character
 * @args: a list of arguments,
 * from which the character to print is extracted
 *
 * Return: 1, representing the number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: a list of arguments,
 * from which the string to print is extracted
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;
	int len = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}

/**
 * print_percent - Prints a percent symbol
 * @args: unused, as no argument
 * is needed to print '%'
 *
 * Return: 1, representing the number of characters printed
 */
int print_int(va_list args)
{
	int num;
	int len = 0;
	int divisor = 1;
	char c;
	
	num = va_arg(args, int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		len++;
	}
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		c = (num / divisor) + '0';
		write(1, &c, 1);
		len++;
		num %= divisor;
		divisor /= 10;
	}
	return (len);
}

/**
 * print_percent - Prints a single "%"
 * @args: a list of arguments from which the character to print is extracted
 *
 * Return: 1, representing the number of characters printed
 */
int print_percent(va_list args)
{
  (void) args;
        write(1, "%", 1);
        return (1);
}
