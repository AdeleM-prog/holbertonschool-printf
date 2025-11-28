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
	int j;
	
struct spec table[] =
  {
    {'c', print_char},
    {'s', print_string},
    {'%', print_percent},
    {'d', print_int},
    {'i', print_int},
    {'\0', NULL}
  };
	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
		  if (format[i + 1] == '\0')
		    break;
		  else
		    {
		  for (j = 0; table[j].spec != '\0'; j++)
		    {
		      if (format[i + 1] == table[j].spec)
			{
			  i++;
			 nbChar = nbChar + table[j].f(args);
			 break;
			}
		    }
		  if (table[j].spec == '\0')
			{
		     write(1, "%", 1);
		     write(1, &format[i + 1], 1);
		     i++;
		     nbChar = nbChar + 2;
		     break;
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
