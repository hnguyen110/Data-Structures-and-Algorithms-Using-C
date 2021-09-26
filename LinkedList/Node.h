#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template<class Type>
class Node {
    Type *_previousNode;
    Type *_nextNode;
    Type *_node;

public:
    Node(Type *value) {
        _node = value;
        _previousNode = nullptr;
        _nextNode = nullptr;
    }

    Type *getPreviousNode() const {
        return _previousNode;
    }

    void setPreviousNode(Type *previousNode) {
        _previousNode = previousNode;
    }

    Type *getNextNode() const {
        return _nextNode;
    }

    void setNextNode(Type *nextNode) {
        _nextNode = nextNode;
    }

    Type *getNode() const {
        return _node;
    }

    void setNode(Type *node) {
        _node = node;
    }
};


#endif //LINKED_LIST_NODE_H
