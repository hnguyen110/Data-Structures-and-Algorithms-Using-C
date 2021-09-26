#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Testing Node module" << std::endl;
    Node<int> node(new int(1));

    std::cout << "Node value should be 1 ==> ";
    if (*node.getNode() == 1) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "Last node value should be null ==> ";
    if (node.getPreviousNode() == nullptr) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "Next node value should be null ==> ";
    if (node.getPreviousNode() == nullptr) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    Node<int> secondNode(new int(2));
    Node<int> thirdNode(new int(3));
    node.setPreviousNode(&secondNode);
    node.setNextNode(&thirdNode);
    std::cout << "Last node value should be 2 ==> ";
    if (*node.getPreviousNode()->getNode() == 2) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "Next node value should be 3 ==> ";
    if (*node.getNextNode()->getNode() == 3) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    node.setNode(new int(10));
    std::cout << "Current node value should be 10 ==> ";
    if (*node.getNode() == 10) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "\nTesting LinkedList module" << std::endl;
    LinkedList<int> list;
    std::cout << "The list should be empty ==> ";
    if (list.empty()) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "First node value should be nullptr ==> ";
    if (list.getFirstNode() == nullptr) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    std::cout << "Last node value should be nullptr ==> ";
    if (list.getLastNode() == nullptr) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    list.addLast(new Node(new int(2)));
    list.addLast(new Node(new int(3)));
    list.addFirst(new Node(new int(1)));
    std::cout << "First node value should be 1 ==> ";
    if (*list.getFirstNode()->getNode() == 1) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;
    std::cout << "Middle node value should be 2 ==> ";
    if (*list.getFirstNode()->getNextNode()->getNode() == 2) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;
    std::cout << "First node value should be 3 ==> ";
    if (*list.getLastNode()->getNode() == 3) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    list.removeFirst();
    std::cout << "First node value should be 2 ==> ";
    if (*list.getFirstNode()->getNode() == 2) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;
    list.removeLast();
    std::cout << "Last node value should be 2 ==> ";
    if (*list.getLastNode()->getNode() == 2) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    list.removeFirst();
    list.removeLast();
    return 0;
}
