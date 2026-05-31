#pragma once
#include <cstddef>
#include "Exception.hpp"

template<class T>
class Option{

private:
    alignas(T) std::byte data_[sizeof(T)];
    bool has_;

    T* ptr() {
        return reinterpret_cast<T*>(data_);
    }

    const T* ptr() const {
        return reinterpret_cast<const T*>(data_);
    }

public:
    Option() : has_(false) {};

    Option(T value) : has_(true){
        new (data_) T(value);
    }

    ~Option() {
        if(has_){
            ptr()->~T();
        }
    }

    bool has_value() const {
        return has_;
    }

    T& get_value() {
        if (!has_) {
            throw OptionException();
        }
        return *ptr();
    }

    const T& get_value() const {
        if (!has_) {
            throw OptionException();
        }
        return *ptr();
    }

    Option& operator=(const Option& other) {
        if (this == &other) {
            return *this;
        }

        if (has_){
            ptr()->~T();
            has_ = false;
        }

        if (other.has_) {
            new (data_) T(*other.ptr());
            has_ = true;
        }
        return *this;
    }
};