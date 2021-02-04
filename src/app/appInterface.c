
#include "appInterface.h"


void appInterface_execute(appInterface_t* interface)
{
	if(interface != NULL 
	&& interface->context != NULL 
	&& interface->execute_fn != NULL)
	{
		interface->execute_fn(interface->context);
	}
}
