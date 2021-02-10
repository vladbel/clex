#include <stdio.h>
#include <stdint.h>

typedef   void (*sort_fn_t)(void *context);

typedef struct arraySortInterface_s
{
    void *context;
    sort_fn_t sort_fn;
} arraySortInterface_t;

void arraySortInterface_sort ( arraySortInterface_t* interface);

typedef struct arraySortInstance_s
{
    int16_t* array;
    int16_t length;
    uint8_t result;
} arraySortInstance_t;

void arrayHeapSortInstance_getInterface( void* instance, arraySortInterface_t* interface);

