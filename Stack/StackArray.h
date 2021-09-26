#ifndef DSA_STACKARRAY_H
#define DSA_STACKARRAY_H

template<typename Type>
class StackArray {
private:
    Type **stack;
    int size;
    int _lastIndex;

public:
    StackArray() {
        size = 1;
        stack = new Type*[size];
        _lastIndex = -1;
    }

    bool empty() {
        return _lastIndex == -1;
    }

    Type* peek() {
        if (empty()) return nullptr;
        return stack[_lastIndex];
    }

    Type* pop() {
        if (!empty()) {
            auto lastElement = peek();
            stack[_lastIndex] = nullptr;
            --_lastIndex;
            return lastElement;
        }
        return nullptr;
    }

    Type* push(Type* element) {
        if (_lastIndex == size - 1) {
            auto copy = stack;
            stack = new Type*[size * 2];
            for (auto index = 0; index < size; ++index) {
                stack[index] = copy[index];
            }
            size = size * 2;
        }
        ++_lastIndex;
        stack[_lastIndex] = element;
        return peek();
    }

    Type* search(Type value) {
        for (auto index = 0; index < _lastIndex + 1; ++index)
            if (value == *stack[index])
                return stack[index];
        return nullptr;
    }

    ~StackArray() {
        delete[] stack;
        stack = nullptr;
    }
};


#endif //DSA_STACKARRAY_H
