#include <stdio.h>
#include <stdint.h>

typedef void (*init_fn_t)(void *context,
                          int16_t *array,
                          int16_t length);
typedef void (*search_fn_t)(void *context);

typedef struct arraySearchInterface_s
{
    void *context;
    init_fn_t init_fn;
    search_fn_t search_fn;
} arraySearchInterface_t;

void arraySearchInterface_init(arraySearchInterface_t *interface, int16_t *array,
                               int16_t length);
void arraySearchInterface_sort(arraySearchInterface_t *interface);

typedef struct arraySearchInstance_s
{
    int16_t *array;
    int16_t length;
    int16_t result;
} arraySearchInstance_t;

void arraySearchMaxSubarrayInstance_getInterface(void *instance, arraySearchInterface_t *interface);
