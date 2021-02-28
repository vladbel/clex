#include "../../utests/acutest.h"
#include "../arraySearchInterface.h"
#include <time.h>

void test_arraySearchInstance_01(void)
{
    int16_t array[8] = {-1, 1, -1, 3, -1, -1, 1, -1};
    int16_t result[8];

    arraySearchLrsInstance_t arraySearchLrsInstance;
    arraySearchLrsInstance.array = array;
    arraySearchLrsInstance.length = 8;
    arraySearchLrsInstance.resultLrs = result;
    arraySearchLrsInstance.resultLrsLength = 8;
    arraySearchInterface_t arraySearchInterface;

    arraySearchLrs_getInterface((void *)&arraySearchLrsInstance, &arraySearchInterface);
    arraySearchInterface_search(&arraySearchInterface);

    TEST_CHECK(arraySearchLrsInstance.result == 6);
    TEST_CHECK(arraySearchLrsInstance.resultLrs[0] == -1);
    TEST_CHECK(arraySearchLrsInstance.resultLrs[1] == 1);
    TEST_CHECK(arraySearchLrsInstance.resultLrs[2] == -1);
}

/*
VS Code debugger does not step into test
when more then ont test case in list
*/
TEST_LIST = {
    {"Test debug 01", test_arraySearchInstance_01},
    {NULL, NULL}};