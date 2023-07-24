#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    printed_chars++;
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(args, char*));
                    break;
                case 'd':
                    printed_chars += printf("%d", va_arg(args, int));
                    break;
                case 'u':
                    printed_chars += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'o':
                    printed_chars += printf("%o", va_arg(args, unsigned int));
                    break;
                case 'x':
                    printed_chars += printf("%x", va_arg(args, unsigned int));
                    break;
                case 'X':
                    printed_chars += printf("%X", va_arg(args, unsigned int));
                    break;
                case 'p':
                    printed_chars += printf("%p", va_arg(args, void*));
                    break;
                case 'f':
                    printed_chars += printf("%f", va_arg(args, double));
                    break;
                case 'e':
                    printed_chars += printf("%e", va_arg(args, double));
                    break;
                case 'E':
                    printed_chars += printf("%E", va_arg(args, double));
                    break;
                case 'g':
                    printed_chars += printf("%g", va_arg(args, double));
                    break;
                case 'G':
                    printed_chars += printf("%G", va_arg(args, double));
                    break;
                default:
                    putchar(*format);
                    printed_chars++;
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);
    return printed_chars;
}
