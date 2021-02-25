
#include "arraySearchInterface.h"

void  arraySearchInterface_init( arraySearchInterface_t *interface,
                             int16_t *array,
                             int16_t length)
{
    if (interface != NULL && interface->context != NULL && interface->init_fn != NULL)
    {
        interface->init_fn(interface->context, array, length);
    }
}

void  arraySearchInterface_search( arraySearchInterface_t *interface)
{
    if (interface != NULL && interface->context != NULL && interface-> search_fn != NULL)
    {
        interface-> search_fn(interface->context);
    }
}
