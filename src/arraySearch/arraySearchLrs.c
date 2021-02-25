
#include "arraySearchInterface.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

static void _search(void *context)
{
    arraySearchLrsInstance_t *self = (arraySearchLrsInstance_t *)context;
    self->result = 6;

    int16_t currentSequence[16] = {0};
    int16_t currentSequenceLength = 0;

    int16_t longestSequence[16] = {0};
    int16_t longestSequenceLength = 0;

    int16_t blank[16] = {0};

    for (uint16_t i = 0; i < self->length; i++)
    {
        for (uint16_t j = i + 1; j < self->length; j++)
        {
            bool match = true;
            for (uint16_t k = 0; k < currentSequenceLength; k++)
            {
                if (self->array[j - k] != self->array[i - k])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                currentSequence[currentSequenceLength] = self->array[i];
                currentSequenceLength++;
                if (currentSequenceLength > longestSequenceLength)
                {
                    longestSequenceLength = currentSequenceLength;
                    // copy array
                    memcpy(longestSequence, currentSequence, sizeof(longestSequence));
                }
            }
            else
            {
                memcpy(currentSequence, blank, sizeof(currentSequence));
                currentSequenceLength = 1;
                currentSequence[0] = self->array[i];
            }
        }
        currentSequence[currentSequenceLength] = self->array[i];
        currentSequenceLength++;
    }
    memcpy(self->resultLrs, longestSequence, sizeof(longestSequenceLength));
    self->resultLrsLength = longestSequenceLength;
}

static void _init(void *context, int16_t *array, int16_t length)
{
    arraySearchLrsInstance_t *self = (arraySearchLrsInstance_t *)context;
    self->array = array;
    self->length = length;
    self->result = 0;
}

void arraySearchLrs_getInterface(void *instance, arraySearchInterface_t *interface)
{
    interface->context = instance;
    interface->init_fn = _init;
    interface->search_fn = _search;
}
