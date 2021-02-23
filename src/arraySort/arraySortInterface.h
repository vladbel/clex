#include <stdio.h>
#include <stdint.h>

typedef void (*init_fn_t)(void *context,
                          int16_t *array,
                          int16_t length);
typedef void (*sort_fn_t)(void *context);

typedef struct arraySortInterface_s
{
    void *context;
    init_fn_t init_fn;
    sort_fn_t sort_fn;
} arraySortInterface_t;

void arraySortInterface_init(arraySortInterface_t *interface, int16_t *array,
                             int16_t length);
void arraySortInterface_sort(arraySortInterface_t *interface);
