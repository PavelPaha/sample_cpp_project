cmake_minimum_required(VERSION 3.29)
project(sample_cpp_project)

set(CMAKE_CXX_STANDARD 17)

# Основной исполняемый файл, без тестов
add_executable(main main.cpp my_add.cpp)

# FetchContent для GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

# Включить тестирование
enable_testing()

# Указываем путь к заголовочным файлам Google Test
include_directories(${CMAKE_BINARY_DIR}/_deps/googletest-src/googletest/include)

# Создаем исполняемый файл для тестов
add_executable(tests test_add.cpp my_add.cpp)

# Линкуем тесты с библиотеками Google Test
target_link_libraries(tests gtest gtest_main)

# Добавляем тесты
include(GoogleTest)
gtest_discover_tests(tests)
