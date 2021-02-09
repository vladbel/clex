
#include "arraySortInterface.h"


void arraySortInterface_sort(arraySortInterface_t* interface)
{
	if(interface != NULL 
	&& interface->context != NULL 
	&& interface->sort_fn != NULL)
	{
		interface->sort_fn(interface->context);
	}
}
