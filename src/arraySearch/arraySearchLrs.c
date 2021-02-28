
#include "arraySearchInterface.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

static bool _match (int16_t* array, int16_t i, int16_t j, int16_t length)
{
    for( int16_t ii = 0; ii < length; ii++)
    {
        if(array[i - ii] != array[j - ii])
        {
            return false;
        }
    }
    return true;
}

static void _search(void *context)
{
    arraySearchLrsInstance_t *self = (arraySearchLrsInstance_t *)context;
    self->result = 6;

    int16_t currentSequence[8] = {0};
    int16_t currentSequenceLength = 0;

    int16_t longestSequence[8] = {0};
    int16_t longestSequenceLength = 0;

    int16_t blank[8] = {0};

    for (uint16_t i = 0; i < self->length; i++)
    {
        bool match = false;
        for (uint16_t j = i + 1; j < self->length; j++)
        {
            if (_match(self->array, i, j, currentSequenceLength + 1))
            {
                currentSequence[currentSequenceLength] = self->array[i];
                currentSequenceLength++;
                if (currentSequenceLength > longestSequenceLength)
                {
                    longestSequenceLength = currentSequenceLength;
                    // copy array
                    memcpy(longestSequence, currentSequence, sizeof(longestSequence));
                }
                match = true;
                break;
            }
        }
        if (!match)
        {
            currentSequenceLength = 0;
            memcpy(currentSequence, blank, sizeof(currentSequence));
        }
    }
    memcpy(self->resultLrs, longestSequence, sizeof(longestSequence));
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
