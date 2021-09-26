#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template<class Type>
class Node {
    Node<Type> *_previousNode;
    Node<Type> *_nextNode;
    Type *_node;

public:
    Node(Type *node) {
        _node = node;
        _previousNode = nullptr;
        _nextNode = nullptr;
    }

    Node<Type> *getPreviousNode() const {
        return _previousNode;
    }

    void setPreviousNode(Node<Type> *previousNode) {
        _previousNode = previousNode;
    }

    Node<Type> *getNextNode() const {
        return _nextNode;
    }

    void setNextNode(Node<Type> *nextNode) {
        _nextNode = nextNode;
    }

    Type *getNode() const {
        return _node;
    }

    void setNode(Type *node) {
        _node = node;
    }

    ~Node() {
        delete _node;
        _node = nullptr;
    }
};


#endif //LINKED_LIST_NODE_H
