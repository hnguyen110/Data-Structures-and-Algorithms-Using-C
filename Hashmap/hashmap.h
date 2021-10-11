#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H

#include <string>
#include "pair.h"

template<typename Type>
class Hashmap {
private:
    Pair<Type> **_data;
    int _capacity;
    int _size;

public:
    explicit Hashmap(int capacity) {
        _size = 0;
        _capacity = capacity;
        _data = new Pair<Type> *[_capacity];
        for (auto index = 0; index < _capacity; index++)
            _data[index] = nullptr;
    }

    ~Hashmap() {
        for (auto index = 0; index < _capacity; ++index)
            if (_data[index] != nullptr) delete _data[index];
        delete[] _data;
    }

    void Add(const std::string &key, Type *value) {
        auto position = GetNextIndex(key);
        if (position == -1) {
            auto copy = _data;
            _data = new Pair<Type> *[_capacity * 2];
            for (auto index = 0; index < _capacity * 2; index++)
                _data[index] = nullptr;
            for (auto index = 0; index < _capacity; index++)
                _data[index] = copy[index];
            _capacity = _capacity * 2;
            delete[] copy;
        }
        position = GetNextIndex(key);
        _data[position] = new Pair<Type>(key, value);
        _size++;
    }

    Type *Get(const std::string &key) {
        auto position = FindKey(key);
        return position == -1 ? nullptr : _data[position]->GetValue();
    }

    void Remove(const std::string &key) {
        auto position = FindKey(key);
        if (position != -1) {
            delete _data[position];
            _data[position] = nullptr;
            _size--;
        }
    }

    void Clear() {
        for (auto index = 0; index < _capacity; ++index)
            if (_data[index] != nullptr) delete _data[index];
        delete[] _data;
        _size = 0;
        _data = new Pair<Type> *[_capacity];
        for (auto index = 0; index < _capacity; index++)
            _data[index] = nullptr;
    }

    int Size() {
        return _size;
    }

private:
    int HashKey(const std::string &key) {
        return key.length() % _capacity;
    }

    bool Occupied(int index) {
        return _data[index] != nullptr;
    }

    int FindKey(const std::string &key) {
        auto position = HashKey(key);
        if (_data[position] != nullptr && _data[position]->GetKey() == key) return position;
        auto stopIndex = position;
        position = position != _capacity - 1 ? position + 1 : 0;
        while (position != stopIndex && _data[position] != nullptr && _data[position]->GetKey() != key)
            position = (position + 1) % _capacity;
        return _data[position] != nullptr && _data[position]->GetKey() == key ? position : -1;
    }

    int GetNextIndex(const std::string &key) {
        auto position = HashKey(key);
        if (!Occupied(position)) return position;
        auto stopIndex = position;
        position = position != _capacity - 1 ? position + 1 : 0;
        while (position != stopIndex && Occupied(position))
            position = (position + 1) % _capacity;
        return !Occupied(position) ? position : -1;
    }
};


#endif //HASHMAP_HASHMAP_H
