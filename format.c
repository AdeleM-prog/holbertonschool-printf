#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - produces output according to a format
 * @format: char to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
  va_list args;
  int i;
  int j = 0; /*compteur final, nb de caracteres retournes*/
  char *str;
  int len;
  va_start (args, format);
    for (i = 0; format[i] != '\0'; i++)
      {
        if (format[i] != '%')
          {write(1, &format[i], 1);
    j++;
          }
        else if (format[i] == '%' && format[i + 1] == 'c')
          {char character = (char) va_arg(args, int);
            write(1, &character, 1);
            j++;
            i++; /* incrementer i pour ne pas compter le caractere 2x*/
          }
        else if (format[i] == '%' && format[i + 1] == 's')
          {str = va_arg(args, char *);
	    if (str == NULL) /* pour eviter un crash en cas de string NULL*/
		Str = "(null)";
            len = 0;
            while (str[len] != 0)
              {len++;
              }
            write(1, str, len);
            j+= len; /* pour bien compter tous les caracteres de la string dans le compte final*/
            i++;
	  }
        else if (format[i] == '%' && format[i + 1] == '%')
          { write(1, &format[i], 1);
            j++;
            i++;
          }
      }
        va_end(args);
  return (j);
      }
