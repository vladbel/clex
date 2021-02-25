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
void arraySearchInterface_search(arraySearchInterface_t *interface);

typedef struct arraySearchInstance_s
{
    int16_t *array;
    int16_t length;
    int16_t result;
    int16_t subarrayStartIndex;
    int16_t subarrayEndIndex;
    int16_t subarraySum;
} arraySearchInstance_t;

typedef struct arraySearchLrsInstance_s
{
    /*LRS - longest repeated sequence*/
    int16_t *array;
    int16_t length;
    int16_t result;
    int16_t *resultLrs; // array shall be allocated by `Init()` caller
    int16_t resultLrsLength;
} arraySearchLrsInstance_t;

void arraySearchMaxSubarrayInstance_getInterface(void *instance, arraySearchInterface_t *interface);
void arraySearchLrs_getInterface(void *instance, arraySearchInterface_t *interface);
