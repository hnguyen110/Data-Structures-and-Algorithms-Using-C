#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include "Node.h"

template<typename Type>
class Queue {
    Node<Type> *front;
    Node<Type> *back;

    void setDefault() {
        front = nullptr;
        back = nullptr;
    }

public:
    Queue() {
        setDefault();
    }

    bool isEmpty() {
        return front == nullptr || back == nullptr;
    }

    void push_front(Node<Type> *element) {
        if (isEmpty()) {
            front = element;
            back = front;
        } else {
            front->setPrevious(element);
            element->setNext(front);
            front = element;
        }
    }

    void pop_front() {
        if (!isEmpty()) {
            auto node = front;
            front = front->getNext();
            if (front != nullptr)
                front->setPrevious(nullptr);
            else
                setDefault();
            delete node;
        }
    }

    void push_back(Node<Type> *element) {
        if (isEmpty()) {
            back = element;
            front = back;
        } else {
            back->setNext(element);
            element->setPrevious(back);
            back = element;
        }
    }

    void pop_back() {
        if (!isEmpty()) {
            auto node = back;
            back = back->getPrevious();
            if (back != nullptr)
                back->setNext(nullptr);
            else
                setDefault();
            delete node;
        }
    }

    void print() {
        auto node = front;
        while (node != nullptr) {
            std::cout << *node->getValue() << std::endl;
            node = node->getNext();
        }
    }

    ~Queue() {
        auto node = front;
        while (node != nullptr) {
            auto next = node->getNext();
            delete node;
            node = next;
        }
    }
};


#endif //QUEUE_QUEUE_H
