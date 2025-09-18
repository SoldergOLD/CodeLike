#include "List.hh"

Node::Node(int value)
:_value(value), _next(nullptr){}

List::List()
:_size(0), _head(nullptr), _cur(nullptr){}

List::List(initializer_list<int> initList)
{
    Node* tail = nullptr;
    for(int value : initList)
    {
        Node* newNode = new Node(value);
        if(this->_head == nullptr)
        {
            this->_head = newNode;
            tail = newNode;
        }
        else
        {
            tail->_next = newNode;
            tail = newNode;
        }
        ++this->_size;
    }
    this->_cur = this->_head;
}

List::~List()
{
    Node* curNode = this->_head;
    Node* next = nullptr;
    while (curNode)
    {
        next = curNode->_next;
        delete curNode;
        curNode = next;
    }
    _head = nullptr;
    _cur = nullptr;
    _size = 0;
    
}

List& List::operator++()
{
    if(this->_cur != nullptr)
    {
        this->_cur = this->_cur->_next;
    }
    return *this;
}

List List::operator++(int)
{
    List temp = *this;
    if(temp._cur != nullptr)
    {
        temp._cur = temp._cur->_next;
    }
    return temp;
}

int List::printList(void)
{
    Node* head = this->_head;
    for(int i = 0; i < this->_size; ++i)
    {
        if(i == this->_size -1)
        {
            printf("%d\n",head->_value);
        }
        else
        {
            printf("%d->",head->_value);
        }
        
        head = head->_next;
    }
    return 0;
}
