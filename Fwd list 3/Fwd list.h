#pragma once
#include <stdexcept>
#include <initializer_list>
#include <iostream>

template <class T>
class ForwardList {
public:
    ForwardList(std::size_t size = 0);
    ForwardList(std::size_t size, T filler);
    bool empty();
    T& front();
    void push_front(T value);
    void pop_front();

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head;
    std::size_t size;
};

template<class T>
ForwardList<T>::ForwardList(std::size_t size) : size(size), head(nullptr) {
    Node** current = &head;
    for (std::size_t i = 0; i < size; ++i) {
        *current = new Node();
        current = &((*current)->next);
    }
}

template<class T>
ForwardList<T>::ForwardList(std::size_t size, T filler) : size(size), head(nullptr) {
    Node** current = &head;
    for (std::size_t i = 0; i < size; ++i) {
        *current = new Node();
        (*current)->value = filler;
        current = &((*current)->next);
    }
}

template<class T>
bool ForwardList<T>::empty() {
    return size == 0;
}

template<class T>
T& ForwardList<T>::front() {
    return head->value;
}

template<class T>
void ForwardList<T>::push_front(T value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    size++;
}

template<class T>
void ForwardList<T>::pop_front() {
    Node* temp = head->next;
    delete head;
    head = temp;
    size--;
}
