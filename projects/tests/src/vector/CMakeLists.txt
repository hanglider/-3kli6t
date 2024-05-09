target_sources(${TESTS_LIB}
        PRIVATE

        PUBLIC
        vector.h
        vector.cpp
)

target_include_directories(${TESTS_LIB} PUBLIC
        ${PROJECT_SOURCE_DIR}/src/vector
)