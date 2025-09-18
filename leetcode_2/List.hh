#include <iostream>

class Node
{
    public:
        Node(int value, Node* next);
        int _value;
        Node* _next;
};

class List
{
    public:
        List(int size, Node* head);
        int push(Node* node);
        List& operator++();
    private:
        int _size;
        Node* _head;
        Node* _cur;
};