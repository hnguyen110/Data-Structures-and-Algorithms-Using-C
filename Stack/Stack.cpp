#include "Stack.h"

Stack::Stack() {}

bool Stack::empty() {
    return stack.size() == 0;
//    return stack.empty();
}

int Stack::peek() {
    return stack.back();
}

int Stack::pop() {
    // Get a copy of the last element
    auto element = stack.back();
    // Remove the last element from the stack
    stack.pop_back();
    // Return the last element to the main function
    return element;
}

int Stack::push(int element) {
    stack.push_back(element);
    return stack.back();
}

bool Stack::search(int value) {
    for (auto iterator = stack.begin(); iterator != stack.end(); ++iterator) {
        if (*iterator == value) {
            return true;
        }
    }
    return false;
}
