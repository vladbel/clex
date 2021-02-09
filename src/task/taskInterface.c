
#include "taskInterface.h"


void taskInterface_execute(taskInterface_t* interface)
{
	if(interface != NULL 
	&& interface->context != NULL 
	&& interface->execute_fn != NULL)
	{
		interface->execute_fn(interface->context);
	}
}
