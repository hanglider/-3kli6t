project(tests)

add_library(${TESTS_LIB} "")

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_SUPPRESS_REGENERATION true)