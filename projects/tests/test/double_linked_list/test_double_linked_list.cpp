#include "double_linked_list.h"
#include <gtest/gtest.h>

using namespace ITrofimov;

TEST(DoubleLinkedListTest, DefaultConstructor) {
    DoubleLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}

TEST(DoubleLinkedListTest, PushBackAndSize) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
}

TEST(DoubleLinkedListTest, HasItem) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.has_item(2));
    EXPECT_FALSE(list.has_item(4));
}

TEST(DoubleLinkedListTest, RemoveFirst) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.has_item(2));
}

TEST(DoubleLinkedListTest, Print) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3");
}