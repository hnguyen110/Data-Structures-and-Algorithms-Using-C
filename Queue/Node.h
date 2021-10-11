#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

template<typename Type>
class Node {
    Node *previous;
    Node *next;
    Type *value;

public:
    Node(Type *value) {
        this->value = value;
        previous = nullptr;
        next = nullptr;
    }

    Node *getPrevious() const {
        return previous;
    }

    void setPrevious(Node *previous) {
        Node::previous = previous;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    Type *getValue() const {
        return value;
    }

    void setValue(Type *value) {
        Node::value = value;
    }

    ~Node() {
        delete value;
    }
};


#endif //QUEUE_NODE_H
