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

List::List(const List& other) : _size(0), _head(nullptr), _cur(nullptr) {
    Node* otherCur = other._head;
    Node* tail = nullptr;
    while (otherCur != nullptr) {
        Node* newNode = new Node(otherCur->_value);
        if (_head == nullptr) {
            _head = newNode;
        } else {
            tail->_next = newNode;
        }
        tail = newNode;
        // 如果 other._cur 指向当前节点，设置 this->_cur
        if (otherCur == other._cur) {
            _cur = newNode;
        }
        otherCur = otherCur->_next;
        _size++;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) { // 防止自赋值
        List temp(other); // 用拷贝构造函数创建副本
        my_swap(temp);       // 交换 *this 和 temp 的内容
    }                     // temp 析构，释放原资源
    return *this;
}
// 需要实现 swap 成员函数
void List::my_swap(List& other) noexcept {
    using std::swap;
    swap(_head, other._head);
    swap(_cur, other._cur);
    swap(_size, other._size);
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
