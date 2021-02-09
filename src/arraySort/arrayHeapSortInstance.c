
#include "arraySortInterface.h"


void _sort ( void* context)
{
	arraySortInstance_t* self = (arraySortInstance_t*) context;
	self->result = 6;
}

void arrayHeapSortInstance_getInterface( void* instance, arraySortInterface_t* interface)
{
	interface->context = instance;
	interface->sort_fn = _sort;
}
