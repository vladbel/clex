#include "../../utests/acutest.h"
#include "../arraySortInterface.h"
#include <time.h>

static void _validate(int16_t *array, int16_t length)
{
    for (int16_t i = 1; i < length; i++)
    {
        TEST_CHECK(array[i - 1] <= array[i]);
    }
}

static void _runTest(int16_t *array, int16_t length)
{
    arraySortInstance_t arraySortInstance;
    arraySortInterface_t arraySortInterface;

    arrayHeapSortInstance_getInterface((void *)&arraySortInstance, &arraySortInterface);

    arraySortInterface_init(&arraySortInterface, array, length);
    arraySortInterface_sort(&arraySortInterface);

    _validate(array, length);
}

void test_arraySortInstance_01(void)
{
    int16_t array[3] = {3, 2, 1};
    _runTest(array, 3);
}

/*
VS Code debugger does not step into test
when more then ont test case in list
*/
TEST_LIST = {
    {"Test heap sort 01", test_arraySortInstance_01},
    {NULL, NULL}};