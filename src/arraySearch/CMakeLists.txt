set(TARGET_LIB_ARRAY_SEARCH  arraySearch)
set(TARGET_TEST_MAX_SUBARRAY_SEARCH testSearchMaxSubarray)
set(TARGET_TEST_LRS_SEARCH testLrs)
set(TARGET_TEST_DEBUG testSearchDebug)
set(CMAKE_BUILD_TYPE Debug)
set(BLOCK_SEPARATOR "------------------------")

# project name and language
cmake_minimum_required(VERSION 3.18)
project( arraySearch LANGUAGES C)
list(APPEND flags "-fPIC" "-Wall")

message(${BLOCK_SEPARATOR})
message("CMake ${TARGET_LIB_ARRAY_SEARCH} library")

add_library(${TARGET_LIB_ARRAY_SEARCH}
  STATIC
    arraySearchInterface.c
    arraySearchMaxSubarrayInstance.c
    arraySearchLrs.c
  )

target_compile_options(${TARGET_LIB_ARRAY_SEARCH}
  PRIVATE
  ${flags}
)

message(${BLOCK_SEPARATOR})

add_executable(${TARGET_TEST_MAX_SUBARRAY_SEARCH}
    test/testArraySearch.c
)

target_compile_options(${TARGET_TEST_MAX_SUBARRAY_SEARCH}
  PRIVATE
  "-fPIC"
)

target_link_libraries(${TARGET_TEST_MAX_SUBARRAY_SEARCH} ${TARGET_LIB_ARRAY_SEARCH})

message(${BLOCK_SEPARATOR})

add_executable(${TARGET_TEST_LRS_SEARCH} test/testLrsArraySearch.c)

target_compile_options(${TARGET_TEST_LRS_SEARCH}
  PRIVATE
  "-fPIC"
)

target_link_libraries(${TARGET_TEST_LRS_SEARCH} ${TARGET_LIB_ARRAY_SEARCH})

message(${BLOCK_SEPARATOR})

add_executable(${TARGET_TEST_DEBUG} test/testArraySearchDebug.c)

target_compile_options(${TARGET_TEST_DEBUG}
  PRIVATE
  "-fPIC"
)

target_link_libraries(${TARGET_TEST_DEBUG} ${TARGET_LIB_ARRAY_SEARCH})