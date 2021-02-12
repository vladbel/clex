
#include "arraySearchInterface.h"
#include <stdint.h>
#include <stdlib.h>

static void _search(void *context)
{
    arraySearchInstance_t *self = (arraySearchInstance_t *)context;
    self->result = 6;

    self->subarraySum = INT16_MIN;

    int16_t maxSumLocal = 0;
    int16_t startIndexLocal = 0;
    int16_t endIndexLocal = 0;
    for (uint16_t i = 0; i < self->length; i++)
    {
        // local_maximum at index i is the maximum of A[i] and the sum of A[i] and local_maximum at index i-1.
        if (maxSumLocal + self->array[i] > self->array[i])
        {
            endIndexLocal = i;
            maxSumLocal = maxSumLocal + self->array[i];
        }
        else
        {
            maxSumLocal = self->array[i];
            endIndexLocal = i;
            startIndexLocal = i;
        }

        if (maxSumLocal > self->subarraySum)
        {
            self->subarraySum = maxSumLocal;
            self->subarrayStartIndex = startIndexLocal;
            self->subarrayEndIndex = endIndexLocal;
        }
    }
}

static void _init(void *context, int16_t *array, int16_t length)
{
    arraySearchInstance_t *self = (arraySearchInstance_t *)context;
    self->array = array;
    self->length = length;
}

void arraySearchMaxSubarrayInstance_getInterface(void *instance, arraySearchInterface_t *interface)
{
    interface->context = instance;
    interface->init_fn = _init;
    interface->search_fn = _search;
}
