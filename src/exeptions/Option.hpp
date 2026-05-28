#pragma once
#include <cstddef>

template<class T>
class Option
{
private:
    union {
        std::byte data_[sizeof(T)];
        T value_;
    } stor;

    bool has_;
public:
    Option() : has_(false);

    Option(T value) : has_(true){
        new (stor.data_) T(value);
    }

    ~Option() {
        if(has_){
            data_.~T();
        }
    }

    bool has_value() const {
        return has_;
    }

    T& get_value() {
        if (!has_value_()) {
            throw OptionException();
        }
        return stor.value_;
    }

    const T& get_value() const {
        if (!has_value_()) {
            throw OptionException();
        }
        return stor.value_;
    }
};