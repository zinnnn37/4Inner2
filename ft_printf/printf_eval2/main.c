#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define test(...) \
    do { \
    int res1 = printf(__VA_ARGS__); \
    int res2 = ft_printf(__VA_ARGS__); \
    printf("printf: %d, ft: %d\n", res1, res2); \
    } while (0);

int main() {
    test("%x%x%x\n", 17,17,17);
}