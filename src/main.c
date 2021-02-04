
#include "app/appInterface.h"

 int main()
{
	appInstance_t appInstance;
	appInterface_t appInterface;

	appInstance_getInterface((void*)&appInstance, &appInterface);
	appInterface_execute(&appInterface);

	printf("app instance.result = %d", appInstance.result);

}