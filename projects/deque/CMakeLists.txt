target_sources(${TESTS_LIB}
        PRIVATE

        PUBLIC
        list_deque.h
        static_array_deque.h
        vector_deque.h
)

target_include_directories(${TESTS_LIB} PUBLIC
        ${PROJECT_SOURCE_DIR}/src/deque
)