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
        // 检查并设置 _cur 指针
        if (otherCur == other._cur) {
            _cur = newNode;
        }
        otherCur = otherCur->_next;
        _size++;
    }
    // 确保复制后的链表正确终结
    if (tail != nullptr) {
        tail->_next = nullptr;
    }
    // 如果 other._cur 为 nullptr，确保 this->_cur 也为 nullptr
    if (other._cur == nullptr) {
        _cur = nullptr;
    }
}

// List 的 swap 成员函数定义
void List::swap(List& other) noexcept {
    using std::swap;         // 允许 ADL（参数依赖查找）
    swap(_head, other._head); // 交换头指针
    swap(_cur, other._cur);   // 交换当前指针
    swap(_size, other._size); // 交换大小
}

List& List::operator=(const List& other) {
    if (this != &other) { // 防止自赋值
        List temp(other); // 用拷贝构造函数创建副本
        swap(temp);       // 交换 *this 和 temp 的内容
    }                     // temp 析构，释放原资源
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
    List temp = *this; // 保存原状态
    ++(*this);         // 使用前置++来递增本对象
    return temp;       // 返回原状态
}

int List::printList(void) {
    Node* current = _head;
    while (current != nullptr) {
        printf("%d->", current->_value);
        current = current->_next;
    }
    printf("NULL\n"); // 明确表示链表结束
    return 0;
}
