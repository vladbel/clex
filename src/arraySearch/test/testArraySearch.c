#include "../../utests/acutest.h"
#include "../arraySearchInterface.h"
#include <time.h>

static arraySearchInstance_t _runTest(int16_t *array, int16_t length)
{
    arraySearchInstance_t arraySearchInstance;
    arraySearchInterface_t arraySearchInterface;

    arraySearchMaxSubarrayInstance_getInterface((void *)&arraySearchInstance, &arraySearchInterface);

    arraySearchInterface_init(&arraySearchInterface, array, length);
    arraySearchInterface_search(&arraySearchInterface);
    return arraySearchInstance;
}

void test_arraySearchInstance_01(void)
{
    int16_t array[3] = {3, 2, 1};
    arraySearchInstance_t arraySearchInstance = _runTest(array, 3);
    TEST_CHECK(arraySearchInstance.result == 6);
}

/*
VS Code debugger does not step into test
when more then ont test case in list
*/
TEST_LIST = {
    {"Test heap sort 01", test_arraySearchInstance_01},
    {NULL, NULL}};