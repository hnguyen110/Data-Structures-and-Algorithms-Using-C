#include <iostream>
#include "Stack.h"
#include "StackArray.h"

int main() {
//    Stack stack;
//    std::cout << "Stack should be empty: " << stack.empty() << std::endl;
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    stack.push(4);
//    stack.push(5);
//    std::cout << "Stack last element should be 5: " << stack.peek() << std::endl;
//    std::cout << "Remove the last element" << std::endl;
//    stack.pop();
//    std::cout << "Stack last element should be 4: " << stack.peek() << std::endl;
//    std::cout << "Search for element 1 should be true: " << stack.search(1);
//    std::cout << "Search for element 10 should be false: " << stack.search(10);

    StackArray<int> stackArray;
    if (stackArray.empty()) std::cout << "EMPTY() ==> PASSED" << std::endl;
    else std::cout << "EMPTY() ==> PASSED" << std::endl;

    if (stackArray.peek() == nullptr) std::cout << "PEEK with no element ==> PASSED" << std::endl;
    else std::cout << "PEEK with no element ==> FAILED" << std::endl;

    stackArray.push(new int(1));
    if (*stackArray.peek() == 1) std::cout << "PUSH function with element 1 ==> PASSED" << std::endl;
    else std::cout << "PUSH function with element 1 ==> FAILED" << std::endl;

    stackArray.push(new int(2));
    if (*stackArray.peek() == 2) std::cout << "PUSH function with element 2 and resize ==> PASSED" << std::endl;
    else std::cout << "PUSH function with element 2 and resize ==> FAILED" << std::endl;

    auto removedElement = stackArray.pop();
    if (*removedElement == 2) std::cout << "POP function ==> PASSED" << std::endl;
    else std::cout << "POP function ==> FAILED" << std::endl;

    if (stackArray.search(1) != nullptr) std::cout << "SEARCH function ==> PASSED" << std::endl;
    else  std::cout << "SEARCH function ==> FAILED" << std::endl;

    if (stackArray.search(10) == nullptr) std::cout << "SEARCH function ==> PASSED" << std::endl;
    else  std::cout << "SEARCH function ==> FAILED" << std::endl;

    return 0;
}
