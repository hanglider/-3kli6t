set(This LongNumberTests)

set(Sources
        LongNumberTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This}
        gtest_main
        gmock_main
        LongNumber_lib
)

add_test(NAME ${This} COMMAND ${Sources})