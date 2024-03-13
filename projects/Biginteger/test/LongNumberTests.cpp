#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <windows.h>

#include "LongNumber.h"

class EqualityFixture : public testing::Test {
public:
    LongNumber one_v1 = ::LongNumber("1");
    LongNumber one_v2 = ::LongNumber("1");
    LongNumber seven = ::LongNumber("7");
    LongNumber eleven = ::LongNumber("11");
    LongNumber twelve = ::LongNumber("12");
    LongNumber hundred = ::LongNumber("1000");
    LongNumber num_1 = ::LongNumber("143043646467550005435000");
    LongNumber num_2 = ::LongNumber("143043646467550005435000000");
    LongNumber num_3 = ::LongNumber("143043646467267836806260550005435000");
};

TEST_F(EqualityFixture, equal) {
    ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
    ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, less) {
    EXPECT_LT(one_v1 , twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(EqualityFixture, great) {
    EXPECT_GT(twelve, one_v1) << "Проверка " << twelve << " > " << one_v1;
}

TEST_F(EqualityFixture, sum) {
    LongNumber result = one_v1 + eleven;
    EXPECT_EQ(result , twelve) << "Проверка " << one_v1 << " + " << eleven << " = " << twelve;
}

TEST_F(EqualityFixture, diff) {
    LongNumber result = twelve - one_v1;
    EXPECT_EQ(result , eleven) << "Проверка " << twelve << " - " << eleven << " = " << eleven;
}

TEST_F(EqualityFixture, multiplie) {
    LongNumber result = hundred * num_1;
    EXPECT_EQ(result , num_2) << "Проверка " << hundred << " * " << num_1 << " = " << num_2;
}

TEST_F(EqualityFixture, module) {
    LongNumber result = num_3 % eleven;
    EXPECT_EQ(result , seven) << "Проверка " << num_3 << " - " << eleven << " = " << seven;
}

int main(int argc, char **argv) {
    SetConsoleOutputCP(CP_UTF8);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}