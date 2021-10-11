#ifndef HASHMAP_PAIR_H
#define HASHMAP_PAIR_H

#include <string>
#include <utility>

template<typename Type>
class Pair {
private:
    std::string _key;
    Type *_value;

public:
    Pair(std::string key, Type *value) {
        if (!key.empty() && value != nullptr) {
            _key = std::move(key);
            _value = value;
        } else {
            _key = "";
            _value = nullptr;
        }
    }

    [[nodiscard]] const std::string &GetKey() const {
        return _key;
    }

    void SetKey(const std::string &key) {
        _key = key;
    }

    Type *GetValue() const {
        return _value;
    }

    void SetValue(Type *value) {
        _value = value;
    }

    ~Pair() {
        delete _value;
    }
};


#endif //HASHMAP_PAIR_H
