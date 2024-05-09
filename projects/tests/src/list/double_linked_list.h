#pragma once

#include <cstddef>

namespace ITrofimov {
    template <typename T>
    class DoubleLinkedList {
    private:
        class Node {
        public:
            T value;
            Node* prev = nullptr;
            Node* next = nullptr;
            Node(const T& value) : value(value) {}
            Node(const Node&) = delete;
            Node& operator = (const Node&) = delete;
        };
        Node* begin = nullptr;
        Node* end = nullptr;
    public:
        DoubleLinkedList() noexcept {};
        DoubleLinkedList(const DoubleLinkedList&) = delete;
        DoubleLinkedList& operator = (const DoubleLinkedList&) = delete;
        ~DoubleLinkedList() noexcept;

        void push_back(const T& value) noexcept;
        bool has_item(const T& value) const noexcept;
        void print() const noexcept;
        bool remove_first(const T& value) noexcept;
        std::size_t size() const noexcept;
    };
}