target_sources(${TESTS_LIB}
        PRIVATE

        PUBLIC
        doubly_linked_list.h
        doubly_linked_list.cpp
)

target_include_directories(${TESTS_LIB} PUBLIC
        ${PROJECT_SOURCE_DIR}/src/list
)