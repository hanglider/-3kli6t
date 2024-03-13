target_sources(LongNumber_lib
    PRIVATE
        LongNumber.cpp
    PUBLIC
        LongNumber.h
)

target_include_directories(LongNumber_lib PUBLIC
        "${PROJECT_SOURCE_DIR}/got"
)