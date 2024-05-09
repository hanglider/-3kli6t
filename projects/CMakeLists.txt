cmake_minimum_required(VERSION 3.2...3.27.5)

project(-3kli6t)

set(tests "tests_lib")

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(BigInteger)
add_subdirectory(Diff_enviroments)
add_subdirectory(Fibonacci_numbers)
add_subdirectory(OOP_console)
add_subdirectory(Sorting)
add_subdirectory(tests)

set(CMAKE_SUPPRESS_REGENERATION true)