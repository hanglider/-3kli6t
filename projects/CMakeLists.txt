#[[
cmake_minimum_required(VERSION 3.2...3.27.5)

project(-3kli6t)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(Sorting)
add_subdirectory(Fibonacci_numbers)
add_subdirectory(Diff_enviroments)
add_subdirectory(OOP_console)
add_subdirectory(tests)
add_subdirectory(BigInteger)
add_subdirectory(Dynamic)

set(CMAKE_SUPPRESS_REGENERATION true)]]

cmake_minimum_required(VERSION 3.26)
project(projects)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Dynamic)


