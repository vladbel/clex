set(TARGET_LIB_ARRAY_SORT arraySort)
set(TARGET_TEST_HEAP_SORT testHeapSort)
set(TARGET_TEST_HEAP_SORT_DEBUG testHeapSortDebug)
set(CMAKE_BUILD_TYPE Debug)
set(BLOCK_SEPARATOR "------------------------")

# project name and language
cmake_minimum_required(VERSION 3.18)
project(arraySort LANGUAGES C)
list(APPEND flags "-fPIC" "-Wall")

message(${BLOCK_SEPARATOR})
message("CMake ${TARGET_LIB_ARRAY_SORT} library")

add_library(${TARGET_LIB_ARRAY_SORT}
  STATIC
    arraySortInterface.c
    arrayHeapSortInstance.c
  )

target_compile_options(${TARGET_LIB_ARRAY_SORT}
  PRIVATE
  ${flags}
)

message(${BLOCK_SEPARATOR})

add_executable(${TARGET_TEST_HEAP_SORT} test/testArraySort.c)

target_compile_options(${TARGET_TEST_HEAP_SORT}
  PRIVATE
  "-fPIC"
)

target_link_libraries(${TARGET_TEST_HEAP_SORT} ${TARGET_LIB_ARRAY_SORT})

message(${BLOCK_SEPARATOR})

add_executable(${TARGET_TEST_HEAP_SORT_DEBUG} test/testArraySortDebug.c)

target_compile_options(${TARGET_TEST_HEAP_SORT_DEBUG}
  PRIVATE
  "-fPIC"
)

target_link_libraries(${TARGET_TEST_HEAP_SORT_DEBUG} ${TARGET_LIB_ARRAY_SORT})