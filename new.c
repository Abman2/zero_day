#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _my_printf(const char *format, ...) {
  int lp = 0;
  int i;
  va_list args;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      int ret = print_format(format, args);
      if (ret == -1) {
        return -1;
      }
    } else {
      lp += printf("%c", *format);
    }
    format++;
  }
  va_end(args);
  return lp;
}

int print_format(const char *format, va_list args) {
  switch (*format) {
    case 'b': {
      unsigned int num = va_arg(args, unsigned int);
      char buffer[32];
      int index = 0;

      if (num == 0) {
        return printf("0");
      } else {
        while (num > 0) {
          buffer[index++] = num % 2;
          num /= 2;
        }
        for (i = index - 1; i >= 0; i--) {
          printf("%d", buffer[i]);
        }
      }
      break;
    }
    case 'c':
      printf("%c", va_arg(args, int));
      break;
    case 's':
      printf("%s", va_arg(args, char *));
      break;
    case 'd':
    case 'i':
      printf("%d", va_arg(args, int));
      break;
    case 'u':
      printf("%u", va_arg(args, unsigned int));
      break;
    case 'o':
      printf("%o", va_arg(args, unsigned int));
      break;
    case 'x':
      printf("%x", va_arg(args, int *));
      break;
    case 'X':
      printf("%X", va_arg(args, int *));
      break;
    case 'p':
      printf("%p", va_arg(args, void *));
      break;
    case '%':
      printf("%%");
      break;
    default:
      return -1;
  }

  return 1;
}

