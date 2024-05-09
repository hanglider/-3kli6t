cmake_minimum_required(VERSION 3.2...3.27.5)

project(-3kli6t)

set(TESTS_LIB "tests_lib")

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(tests)

set(CMAKE_SUPPRESS_REGENERATION true)