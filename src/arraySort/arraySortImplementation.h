#include <stdint.h>
#include "arraySortInterface.h"

typedef struct arraySortImpl_s
{
    int16_t *array;
    int16_t length;
    uint8_t result;
} arraySortImpl_t;

void arrayHeapSortImpl_getInterface(void *instance, arraySortInterface_t *interface);