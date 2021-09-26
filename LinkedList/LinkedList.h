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
        _lastNode = nullptr;
    }

    void addFirst(Node<Type> *element) {
        if (element != nullptr) {
            if (_firstNode == nullptr) {
                _firstNode = element;
                _lastNode = _firstNode;
            } else {
                element->setNextNode(_firstNode);
                _firstNode->setPreviousNode(element);
                _firstNode = element;
            }
        }
    }

    Node<Type> *removeFirst() {
        if (!empty()) {
            if (_firstNode->getNextNode() == nullptr) {
                _firstNode = nullptr;
                _lastNode = nullptr;
            } else {
                _firstNode->getNextNode()->setPreviousNode(nullptr);
                _firstNode = _firstNode->getNextNode();
            }
        }
    }

    void addLast(Node<Type> *element) {
        if (_lastNode == nullptr) {
            _lastNode = element;
            _firstNode = _lastNode;
        } else {
            _lastNode->setNextNode(element);
            element->setPreviousNode(_lastNode);
            _lastNode = element;
        }
    }

    Node<Type> *removeLast() {
        if (!empty()) {
            if (_lastNode->getPreviousNode() == nullptr) {
                _firstNode = nullptr;
                _lastNode = nullptr;
            } else {
                _lastNode->getPreviousNode()->setNextNode(nullptr);
                _lastNode = _lastNode->getPreviousNode();
            }
        }
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

    bool empty() {
        return _firstNode == nullptr;
    }

    ~LinkedList() {}
};


#endif //LINKED_LIST_LINKED_LIST_H
