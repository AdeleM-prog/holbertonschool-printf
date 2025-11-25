#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format format to print
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int nbChar = 0;
	char *str;
	char c;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args,int);
				write(1, &c, 1);
				nbChar++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "(null)";
				}
				while (*str != '\0')
				{
					write (1, str, 1);
					str++;
					nbChar++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				nbChar++;
			}
			else
			{
				write(1, &format[i - 1], 1);
				if (format[i] != '\0')
				{
					write(1, &format[i], 1);
					nbChar += 2;
				}
				else
				{
					nbChar++;
				}
			}
		}
		else
		{
			write(1, &format[i], 1);
			nbChar++;
		}
		i++;
	}
	va_end(args);
	return (nbChar);
}
