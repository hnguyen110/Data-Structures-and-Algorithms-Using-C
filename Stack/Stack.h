#ifndef DSA_STACK_H
#define DSA_STACK_H

#include <list>

class Stack {
private:
    std::list<int> stack;
public:
    Stack();

    bool empty();

    int peek();

    int pop();

    int push(int element);

    bool search(int value);
};


#endif //DSA_STACK_H
