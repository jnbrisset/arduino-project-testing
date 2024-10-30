#include <stdio.h>
#include <stdint.h>

#include "tools.h"

void print_binary(byte nb) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (nb >> i) & 1);
    }
}

