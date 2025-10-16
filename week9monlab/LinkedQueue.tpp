#include <string>
using std::string;

template <typename T>
LinkedQueue<T>::LinkedQueue()
    : head(nullptr), last(nullptr) {            // DO NOT try to init base 'length' here
    // base class Queue<T> default ctor already set length = 0
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj)
    : head(nullptr), last(nullptr) {            // same: don't init base 'length' here
    // start empty (base length is 0), then copy
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* n = new Node(elem, nullptr);
    if (this->length == 0) {
        head = last = n;
    } else {
        last->next = n;
        last = n;
    }
    ++this->length;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("LinkedQueue::dequeue error: queue is empty");
    }
    Node* old = head;
    head = head->next;
    delete old;
    --this->length;
    if (this->length == 0) {
        last = nullptr;
    }
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("LinkedQueue::front error: queue is empty");
    }
    return head->value;      // FIX: value (not data)
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("LinkedQueue::back error: queue is empty");
    }
    return last->value;      // FIX: value (not data)
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (head != nullptr) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // start fresh (base length already 0 due to our constructors)
    head = nullptr;
    last = nullptr;
    this->length = 0;

    // enqueue each element to preserve order
    for (Node* p = copyObj.head; p != nullptr; p = p->next) {
        enqueue(p->value);   // FIX: value (not data)
    }
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
