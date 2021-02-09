
#include "taskInterface.h"


void _execute ( void* context)
{
	taskInstance_t* self = (taskInstance_t*) context;
	self->result = 6;
}

void taskInstance_getInterface( void* instance, taskInterface_t* interface)
{
	interface->context = instance;
	interface->execute_fn = _execute;
}
