#include "../../utests/acutest.h"
#include "../arraySortInterface.h"
void test_arraySortInstance_01(void)
{
    int16_t array[3] = {3, 2, 1};
    arraySortInstance_t arraySortInstance;
    arraySortInterface_t arraySortInterface;

    arrayHeapSortInstance_getInterface((void *)&arraySortInstance, &arraySortInterface);

    arraySortInterface_init(&arraySortInterface, array, /* length = */ 3);
    arraySortInterface_sort(&arraySortInterface);

    TEST_CHECK(array[0] == 1);
    TEST_CHECK(array[2] == 3);
}

TEST_LIST = {
    {"Test heap sort on { 3, 2, 1}", test_arraySortInstance_01},
    {NULL, NULL}};