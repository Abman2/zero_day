#include <stdarg.h>
#include <stdio.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _printf(const char *format, ...) {
    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    _putchar(c);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    for (int i = 0; str[i] != '\0'; i++) {
                        _putchar(str[i]);
                        printed_chars++;
                    }
                    break;
                }
                case 'd': {
                    int num = va_arg(args, int);
                    printed_chars += printf("%d", num);
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    printed_chars += printf("%f", num);
                    break;
                }
                case '%': {
                    _putchar('%');
                    printed_chars++;
                    break;
                }
                default: {
                    _putchar('%');
                    _putchar(*format);
                    printed_chars += 2;
                    break;
                }
            }
        } else {
            _putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
