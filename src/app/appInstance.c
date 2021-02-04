
#include "appInterface.h"


void _execute ( void* context)
{
	appInstance_t* self = (appInstance_t*) context;
	self->result = 6;
}

void appInstance_getInterface( void* instance, appInterface_t* interface)
{
	interface->context = instance;
	interface->execute_fn = _execute;
}
