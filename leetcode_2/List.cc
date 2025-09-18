#include "List.hh"

Node::Node(int value)
:_value(value), _next(nullptr){}

List::List()
:_size(0), _head(nullptr), _cur(nullptr){}

List::List(initializer_list<int> initList)
:_size(0), _head(nullptr), _cur(nullptr)
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
        // ��鲢���� _cur ָ��
        if (otherCur == other._cur) {
            _cur = newNode;
        }
        otherCur = otherCur->_next;
        _size++;
    }
    // ȷ�����ƺ��������ȷ�ս�
    if (tail != nullptr) {
        tail->_next = nullptr;
    }
    // ��� other._cur Ϊ nullptr��ȷ�� this->_cur ҲΪ nullptr
    if (other._cur == nullptr) {
        _cur = nullptr;
    }
}

// List �� swap ��Ա��������
void List::swap(List& other) noexcept {
    using std::swap;         // ���� ADL�������������ң�
    swap(_head, other._head); // ����ͷָ��
    swap(_cur, other._cur);   // ������ǰָ��
    swap(_size, other._size); // ������С
}

List& List::operator=(const List& other) {
    if (this != &other) { // ��ֹ�Ը�ֵ
        List temp(other); // �ÿ������캯����������
        swap(temp);       // ���� *this �� temp ������
    }                     // temp �������ͷ�ԭ��Դ
    return *this;
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

List List::operator++(int) {
    List temp = *this; // ����ԭ״̬
    ++(*this);         // ʹ��ǰ��++������������
    return temp;       // ����ԭ״̬
}

int List::printList(void) {
    Node* current = _head;
    while (current != nullptr) {
        printf("%d->", current->_value);
        current = current->_next;
    }
    printf("NULL\n"); // ��ȷ��ʾ�������
    return 0;
}
