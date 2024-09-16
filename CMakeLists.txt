cmake_minimum_required(VERSION 3.29)
project(sample_cpp_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp my_add.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${CMAKE_BINARY_DIR}/_deps/googletest-src/googletest/include)

add_executable(tests test_add.cpp my_add.cpp)

target_link_libraries(tests gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
