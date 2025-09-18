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
        // ��� other._cur ָ��ǰ�ڵ㣬���� this->_cur
        if (otherCur == other._cur) {
            _cur = newNode;
        }
        otherCur = otherCur->_next;
        _size++;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) { // ��ֹ�Ը�ֵ
        List temp(other); // �ÿ������캯����������
        my_swap(temp);       // ���� *this �� temp ������
    }                     // temp �������ͷ�ԭ��Դ
    return *this;
}
// ��Ҫʵ�� swap ��Ա����
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
