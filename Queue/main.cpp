#include <iostream>

#include "Queue.h"

int main() {
    auto queue = new Queue<int>();
    queue->push_front(new Node(new int (1)));
    queue->push_front(new Node(new int (1)));
    queue->push_front(new Node(new int (1)));
    queue->push_back(new Node(new int (1)));
    queue->push_back(new Node(new int (1)));
    queue->push_back(new Node(new int (1)));
    queue->pop_front();
    queue->pop_front();
    queue->pop_front();
    queue->pop_back();
    queue->pop_back();
    queue->pop_back();
    queue->pop_back();
    delete queue;
    return 0;
}
