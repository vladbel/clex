#include "../../utests/acutest.h"
#include "../taskInterface.h"
void test_taskInstance(void)
{
	taskInstance_t taskInstance;
	taskInterface_t taskInterface;

	taskInstance_getInterface((void *)&taskInstance, &taskInterface);
	taskInterface_execute(&taskInterface);

	printf("taskInstancenstance.result = %d\n", taskInstance.result);
}

TEST_LIST = {
	{"test task instance", test_taskInstance},
	{NULL, NULL}};