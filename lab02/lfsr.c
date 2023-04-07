#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

#define var __auto_type

void lfsr_calculate(uint16_t *reg) {
    var zero = (*reg) & 1;
    var two = ((*reg) >> 2) & 1;
    var three = ((*reg) >> 3) & 1;
    var five = ((*reg) >> 5) & 1;
    var msb = zero ^ two ^ three ^ five;
    *reg = ((*reg) >> 1) | (msb << 15);
}
