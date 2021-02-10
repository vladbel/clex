
#include "arraySortInterface.h"

void arraySortInterface_init(arraySortInterface_t *interface,
							 int16_t *array,
							 int16_t length)
{
	if (interface != NULL && interface->context != NULL && interface->init_fn != NULL)
	{
		interface->init_fn(interface->context, array, length);
	}
}

void arraySortInterface_sort(arraySortInterface_t *interface)
{
	if (interface != NULL && interface->context != NULL && interface->sort_fn != NULL)
	{
		interface->sort_fn(interface->context);
	}
}
