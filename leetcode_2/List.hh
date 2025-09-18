#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <utility>

using std::swap;
using std::initializer_list;

class Node
{
    public:
        Node(int value);
        int _value;
        Node* _next;
};

class List
{
    public:
        List();
        List(initializer_list<int> initList);
        int printList(void);
        List& operator++();
        List operator++(int);
        List(const List& other);
        List& operator=(const List& other);
        void swap(List& other) noexcept;
        ~List();
    private:
        int _size;
        Node* _head;
        Node* _cur;
};