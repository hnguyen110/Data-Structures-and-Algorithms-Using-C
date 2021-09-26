#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include "Node.h"

template<class Type>
class LinkedList {
    Node<Type> *_firstNode;
    Node<Type> *_lastNode;

public:
    LinkedList() {
        _firstNode = nullptr;
        _lastNode = _firstNode;
    }

    void addFirst(Node<Type> *element) {
        if (element != nullptr) {
            if (_firstNode == nullptr) {
                _firstNode = element;
            } else {
                element->setNextNode(_firstNode);
                _firstNode = element;
            }
        }
    }

    Node<Type> *removeFirst() {

    }

    void addLast(Node<Type> *element) {
        if (_lastNode == nullptr) {
            _lastNode = element;
            
        }
    }

    Node<Type> *removeLast() {

    }

    Node<Type> *getFirstNode() const {
        return _firstNode;
    }

    void setFirstNode(Node<Type> *firstNode) {
        _firstNode = firstNode;
    }

    Node<Type> *getLastNode() const {
        return _lastNode;
    }

    void setLastNode(Node<Type> *lastNode) {
        _lastNode = lastNode;
    }
};


#endif //LINKED_LIST_LINKED_LIST_H
