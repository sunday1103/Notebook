#include <stdio.h>

extern int my_printf(const char *my_format, ...)
    __attribute__((format(printf, 1, 2)));

int my_printf(const char *my_format, ...) { return 0; }

#define MY_PRINT(format, args...) printf(format, args)

int main(int args, char **argv) {
  char *s = "This is a c string";
  int a = 0;

  my_printf("%s\n", s);

  MY_PRINT("%s\n", a);

  return 0;
}
