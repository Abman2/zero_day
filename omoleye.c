#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int i = 0;
    int printed_chars = 0;
    va_list vl;

    va_start(vl, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    printf("%c", va_arg(vl, int));
                    printed_chars++;
                    break;
                case 's':
                    printf("%s", va_arg(vl, char*));
                    printed_chars += strlen(va_arg(vl, char*));
                    break;
                case '%':
                    printf("%%");
                    printed_chars++;
                    break;
                case 'i':  // For signed integers
                case 'd':
                    printf("%d", va_arg(vl, int));
                    printed_chars += snprintf(NULL, 0, "%d", va_arg(vl, int));
                    break;
                case 'p':
                    printf("%p", va_arg(vl, void*));
                    printed_chars += snprintf(NULL, 0, "%p", va_arg(vl, void*));
                    break;
                case 'x':
                    printf("%x", va_arg(vl, unsigned int));
                    printed_chars += snprintf(NULL, 0, "%x", va_arg(vl, unsigned int));
                    break;
                case 'X':
                    printf("%X", va_arg(vl, unsigned int));
                    printed_chars += snprintf(NULL, 0, "%X", va_arg(vl, unsigned int));
                    break;
                case 'u':
                    printf("%u", va_arg(vl, unsigned int));
                    printed_chars += snprintf(NULL, 0, "%u", va_arg(vl, unsigned int));
                    break;
                case 'o':
                    printf("%o", va_arg(vl, unsigned int));
                    printed_chars += snprintf(NULL, 0, "%o", va_arg(vl, unsigned int));
                    break;
                default:
                    printf("%c", format[i]);
                    printed_chars++;
                    break;
            }
        }
        else
        {
            printf("%c", format[i]);
            printed_chars++;
        }
        i++;
    }
    va_end(vl);
    return printed_chars;
}

