#include "../../utests/acutest.h"
#include "../arraySearchInterface.h"
#include <time.h>

static arraySearchInstance_t _runTest(int16_t *array, int16_t length)
{
    arraySearchInstance_t arraySearchInstance;
    arraySearchInterface_t arraySearchInterface;

    arraySearchMaxSubarrayInstance_getInterface((void *)&arraySearchInstance, &arraySearchInterface);

    arraySearchInterface_init(&arraySearchInterface, array, length);
    arraySearchInterface_sort(&arraySearchInterface);
    return arraySearchInstance;
}

void test_arraySearchInstance_01(void)
{
    int16_t array[7] = {-1, -1, 3, -1, 1, 1, -1};
    arraySearchInstance_t arraySearchInstance = _runTest(array, 7);
    TEST_CHECK(arraySearchInstance.subarraySum == 4);
    TEST_CHECK(arraySearchInstance.subarrayStartIndex == 2);
    TEST_CHECK(arraySearchInstance.subarrayEndIndex == 5);
}

/*
VS Code debugger does not step into test
when more then ont test case in list
*/
TEST_LIST = {
    {"Test heap sort 01", test_arraySearchInstance_01},
    {NULL, NULL}};