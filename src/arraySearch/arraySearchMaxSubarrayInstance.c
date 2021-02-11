
#include "arraySearchInterface.h"

static inline uint16_t _left(uint16_t index)
{
    return (index * 2) + 1;
}

static inline uint16_t _right(uint16_t index)
{
    return (index + 1) * 2;
}

static void _setMaxHeapProperty( arraySearchInstance_t *self, uint16_t head)
{
    int16_t largest = head;
    if (_left(head) < self->length && self->array[_left(head)] > self->array[largest])
    {
        largest = _left(head);
    }

    if (_right(head) < self->length && self->array[_right(head)] > self->array[largest])
    {
        largest = _right(head);
    }

    if (largest != head)
    {
        int16_t tmp = self->array[head];
        self->array[head] = self->array[largest];
        self->array[largest] = tmp;
        _setMaxHeapProperty(self, largest);
    }
}

static void _sort(void *context)
{
     arraySearchInstance_t *self = ( arraySearchInstance_t *)context;
    self->result = 6;

    for (int16_t i = self->length / 2; i >= 0; i--)
    {
        _setMaxHeapProperty(self, i);
    }

    int16_t length = self->length;

    for (; self->length > 0;)
    {
        int16_t tmp = self->array[self->length - 1];
        self->array[self->length - 1] = self->array[0];
        self->array[0] = tmp;
        self->length--;
        _setMaxHeapProperty(self, 0);
    }
    self->length = length;
}

static void _init(void *context, int16_t *array, int16_t length)
{
     arraySearchInstance_t *self = ( arraySearchInstance_t *)context;
    self->array = array;
    self->length = length;
}

void arraySearchMaxSubarrayInstance_getInterface(void *instance,  arraySearchInterface_t *interface)
{
    interface->context = instance;
    interface->init_fn = _init;
    interface-> search_fn = _sort;
}
