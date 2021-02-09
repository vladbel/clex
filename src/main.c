
#include "task/taskInterface.h"

 int main()
{
	taskInstance_t taskInstance;
	taskInterface_t taskInterface;

	taskInstance_getInterface((void*)&taskInstance, &taskInterface);
	taskInterface_execute(&taskInterface);

	printf("app instance.result = %d\n", taskInstance.result);

}