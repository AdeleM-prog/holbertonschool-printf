#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * format_d_i - Produces output according to a format
 * @format: the format string containing the specifiers
 *
 * Return: the number of caracters
 */
int format_d_i(const char *format,...)
{
	int i = 0;
	int nbChar = 0;
	int num;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (format[i] != '\0')
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			num = va_arg(args, int);
			write(1, &num, 1);
			i++;
			nbChar++;
		}
		else
		{
			write(1, &nup, 1);
			nbChar++;
		}
	va_end(args);
	return (nbChar);
}
