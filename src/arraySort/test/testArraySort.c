#include "../../utests/acutest.h"
#include "../arraySortInterface.h"
void test_arraySortInstance(void)
{
	arraySortInstance_t arraySortInstance;
	arraySortInterface_t arraySortInterface;

	arrayHeapSortInstance_getInterface((void *)&arraySortInstance, &arraySortInterface);
	arraySortInterface_sort(&arraySortInterface);

	printf("arraySortInstancenstance.result = %d\n", arraySortInstance.result);
}

TEST_LIST = {
	{"test task instance", test_arraySortInstance},
	{NULL, NULL}};