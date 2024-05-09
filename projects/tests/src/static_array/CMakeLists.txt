target_sources(${TESTS_LIB}
        PRIVATE
        static_array.cpp
        PUBLIC
        static_array.h
)

target_include_directories(${TESTS_LIB} PUBLIC
        ${PROJECT_SOURCE_DIR}/src/static_array
)