#include "double_linked_list.h"
#include <iostream>

using ITrofimov::DoubleLinkedList;

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() noexcept {
    Node* node;
    while(begin != end){
        if(end == nullptr) break;
        node = end;
        end = node->prev;
        delete node;
    }
    delete begin;
}

template <typename T>
void DoubleLinkedList<T>::push_back(const T& value) noexcept{
    Node* node = new Node(value);
    node->prev = end;
    if(end != nullptr){
        end->next = node;
    }else{
        begin = node;
    }
    end = node;
}

template <typename T>
void DoubleLinkedList<T>::print() const noexcept {
    Node *ptr = begin;
    while(ptr != end){
        std::cout << ptr->value << "\n";
        ptr = ptr->next;
    }
    std::cout << end->value << "\n";
}

template <typename T>
bool DoubleLinkedList<T>::remove_first(const T& value) noexcept{
    Node* node = begin;
    if (begin == nullptr)
        return false;
    if (begin->value == value){
        begin = node->next;
        delete node;
        return true;
    }
    while(true){
        if (node == end){
            if (end->value == value){
                end = node->prev;
                delete node;
                return true;
            } else{
                return false;
            }
        }
        if(node->value == value){
            Node* left = node->prev;
            Node* right = node->next;
            right->prev = left;
            left->next = right;
            delete node;
            return true;
        }
        node = node->next;
    }
}

template <typename T>
bool DoubleLinkedList<T>::has_item(const T& value) const noexcept{
    Node* node = begin;
    while(true){
        if (node == end && node->value != value)
            return false;
        if (node->value == value)
            return true;
        node = node->next;
    }
}

template <typename T>
size_t DoubleLinkedList<T>::size() const noexcept{
    if (begin == nullptr)
        return 0;
    Node* node = begin;
    size_t count = 0;
    while(true){
        count++;
        if (node == end)
            return count;
        node = node->next;
    }
}