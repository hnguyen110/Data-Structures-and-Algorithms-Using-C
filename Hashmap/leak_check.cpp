#include <iostream>
#include "hashmap.h"

int main() {
    auto _hashmap = new Hashmap<int>(3);
    std::cout << _hashmap->Size() << std::endl;
    if (_hashmap->Get("some_key") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    _hashmap->Add("one", new int(1));
    _hashmap->Add("two", new int(2));
    _hashmap->Add("three", new int(3));
    _hashmap->Add("four", new int(4));
    _hashmap->Add("five", new int(5));
    std::cout << *_hashmap->Get("one") << std::endl;
    std::cout << *_hashmap->Get("two") << std::endl;
    std::cout << *_hashmap->Get("three") << std::endl;
    std::cout << *_hashmap->Get("four") << std::endl;
    std::cout << *_hashmap->Get("five") << std::endl;
    std::cout << _hashmap->Size() << std::endl;
    if (_hashmap->Get("one") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    std::cout << *_hashmap->Get("two") << std::endl;
    std::cout << *_hashmap->Get("three") << std::endl;
    std::cout << *_hashmap->Get("four") << std::endl;
    std::cout << *_hashmap->Get("five") << std::endl;
    _hashmap->Remove("one");
    _hashmap->Remove("two");
    if (_hashmap->Get("one") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    if (_hashmap->Get("two") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    std::cout << _hashmap->Size() << std::endl;
    _hashmap->Clear();
    if (_hashmap->Get("one") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    if (_hashmap->Get("two") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    if (_hashmap->Get("three") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    if (_hashmap->Get("four") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    if (_hashmap->Get("five") == nullptr) std::cout << "NULL CHECK PASSED" << std::endl;
    std::cout << _hashmap->Size() << std::endl;
    delete _hashmap;
    return 0;
}