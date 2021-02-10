#include "../../utests/acutest.h"
#include "../arraySortInterface.h"
void test_arraySortInstance(void)
{
	int16_t array[3] = { 3, 2, 1};
	arraySortInstance_t arraySortInstance;
	arraySortInstance.array = array;
	arraySortInstance.length = 3;
	arraySortInterface_t arraySortInterface;

	arrayHeapSortInstance_getInterface((void *)&arraySortInstance, &arraySortInterface);
	arraySortInterface_sort(&arraySortInterface);

	TEST_CHECK(array[0] == 1);
	TEST_CHECK(array[2] == 3);
}

TEST_LIST = {
	{"test task instance", test_arraySortInstance},
	{NULL, NULL}};