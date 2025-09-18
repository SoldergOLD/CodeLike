#include "List.hh"

Node::Node(int value, Node* node)
:_value(value), _next(node){}

List::List(int size, Node* head)
:_size(size), _head(head), _cur(nullptr){}

int List::push(Node* node)
{
    if(!node)
    {
        return -1;
    }
    return 0;
}

List& List::operator++()
{
    return *this;
}
