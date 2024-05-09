project(tests)

add_library(radix_sort_lib "")

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_SUPPRESS_REGENERATION true)