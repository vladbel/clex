#include "../../utests/acutest.h"
#include "../appInterface.h"
void test_app(void)
{
	appInstance_t appInstance;
	appInterface_t appInterface;

	appInstance_getInterface((void *)&appInstance, &appInterface);
	appInterface_execute(&appInterface);

	printf("app instance.result = %d\n", appInstance.result);
}

TEST_LIST = {
	{"test app", test_app},
	{NULL, NULL}};