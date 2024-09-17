cmake_minimum_required(VERSION 3.29)
project(sample_cpp_project)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_Declare(
        googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.7.1
)

FetchContent_MakeAvailable(googletest googlebenchmark)

# Главный исполняемый файл main
add_executable(main
        main.cpp          # Обычный main
        src/my_add.cpp
)

target_link_libraries(main PRIVATE pthread)

enable_testing()

# Тесты
add_executable(tests
        tests/test_add.cpp
        src/my_add.cpp
)

target_link_libraries(tests PRIVATE gtest gtest_main benchmark::benchmark pthread)

include(GoogleTest)
gtest_discover_tests(tests)

# Бенчмарки
add_executable(bench
        src/benchmark.cpp
        src/my_add.cpp
)

target_link_libraries(bench PRIVATE benchmark::benchmark benchmark::benchmark_main pthread)

include_directories(${googlebenchmark_SOURCE_DIR}/include)
