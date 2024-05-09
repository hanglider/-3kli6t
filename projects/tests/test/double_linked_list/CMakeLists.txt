add_executable(double_linked_list_tests test_double_linked_list.cpp templates.cpp)

target_link_libraries(double_linked_list_tests
        gtest_main
        ${TESTS_LIB}
)

add_test(double_linked_list_tests double_linked_list_tests)