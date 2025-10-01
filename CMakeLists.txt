cmake_minimum_required(VERSION 3.12)
project(Task1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/replacer.cpp)
target_include_directories(main PUBLIC include)

enable_testing()

find_package(GTest REQUIRED)

add_executable(run_tests test/tester.cpp src/replacer.cpp)
target_include_directories(run_tests PUBLIC include)
target_link_libraries(run_tests GTest::gtest GTest::gtest_main)

add_test(NAME Task1Tests COMMAND run_tests)