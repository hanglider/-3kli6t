target_sources(${TESTS_LIB}
        PRIVATE

        PUBLIC
        double_linked_list.h
        double_linked_list.cpp
)

target_include_directories(${TESTS_LIB} PUBLIC
        ${PROJECT_SOURCE_DIR}/src/list
)