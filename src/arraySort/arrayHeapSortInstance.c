
#include "arraySortInterface.h"

static inline uint8_t _left(uint8_t index)
{
    return (index * 2) + 1;
}

static inline uint8_t _right(uint8_t index)
{
    return (index + 1) * 2;
}

static void _setMaxHeapProperty(arraySortInstance_t *self, uint8_t head)
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
    arraySortInstance_t *self = (arraySortInstance_t *)context;
    self->result = 6;

    for (int16_t i = self->length / 2; i != 0; i--)
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
    arraySortInstance_t *self = (arraySortInstance_t *)context;
    self->array = array;
    self->length = length;
}

void arrayHeapSortInstance_getInterface(void *instance, arraySortInterface_t *interface)
{
    interface->context = instance;
    interface->init_fn = _init;
    interface->sort_fn = _sort;
}
