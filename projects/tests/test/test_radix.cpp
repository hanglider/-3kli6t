#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "radix_sort.h"

TEST(ArraysEqual, AnyElementsCount) {
	int actual[] = {1, 8, 2, 5, 3, 11};
    const int actual_size = sizeof(actual) / sizeof(actual[0]);
	RadixSort::sort_by_radix(actual, actual_size);
	int expected[] = {1, 4, 3, 5, 8, 11};
    const int expected_size = sizeof(expected) / sizeof(expected[0]);
	ASSERT_EQ(expected_size, actual_size)
		<< "Разные размеры ожидаемого и отсортированного массивов";
	
	for (int i = 0; i < actual_size; i++) {
		ASSERT_EQ(expected[i], actual[i]) 
			<< "Массив ожидаемый и отсортировнный отличаются в элементе с индексом "
			<< i;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}