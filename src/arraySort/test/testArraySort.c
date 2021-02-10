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

void test_arraySortInstance_02(void)
{
    int16_t array[5] = {5, 4, 3, 2, 1};
    _runTest(array, 5);
}

void test_arraySortInstance_03(void)
{
    int16_t array[2] = {2, 1};
    _runTest(array, 2);
}

void test_arraySortInstance_04(void)
{
    int16_t array[15] = {2, 1, 3, 4, 6,
                         5, 8, 7, 10, 9,
                         0, 1, 0, 1111, 0};
    _runTest(array, 15);
    _runTest(array, 15); // run on sorted array
}

void test_arraySortInstance_05(void)
{
    int16_t array[4] = {2, 1, 3, 4};
    _runTest(array, 4);
    _runTest(array, 4); // run on sorted array
}

void test_arraySortInstance_06(void)
{
    int16_t array[10] = {2, 1, 2, 1, 1,
                         2, 2, 1, 1, 2};
    _runTest(array, 10);
}

void test_arraySortInstance_07(void)
{
    int16_t array[10] = {2, 1, 2, -1, 1,
                         2, -2, 1, 1, 2};
    _runTest(array, 10);
}

void test_arraySortInstance_08(void)
{
    int16_t array[1000];
    srand(time(NULL));
    for (int16_t i = 0; i < 1000; i++)
    {
        array[i] = rand();
    }
    _runTest(array, 1000);
}

TEST_LIST = {
    {"Test heap sort 01", test_arraySortInstance_01},
    {"Test heap sort 02", test_arraySortInstance_02},
    {"Test heap sort 03", test_arraySortInstance_03},
    {"Test heap sort 04", test_arraySortInstance_04},
    {"Test heap sort 05", test_arraySortInstance_05},
    {"Test heap sort 06", test_arraySortInstance_06},
    {"Test heap sort 07", test_arraySortInstance_07},
    {"Test heap sort 08", test_arraySortInstance_08},
    {NULL, NULL}};