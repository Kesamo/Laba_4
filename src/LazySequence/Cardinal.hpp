#pragma once
#include "Option.hpp"
#include "Exception.hpp"

class Cardinal {
private:
    Option<size_t> value_;

    Cardinal() : value_{} {}

public:
    Cardinal(size_t value) : value_{value} {}

    static Cardinal inf() {
        return Cardinal{};
    }

    bool is_infinite() const {
        return !value_.has_value();
    }

    bool is_finite() const {
        return value_.has_value();
    }

    size_t get_value() const{
        if(is_infinite()){
            throw InfiniteException();
        }
        return value_.get_value();
    }

    bool operator==(const Cardinal& other) const {
        if (is_infinite() && other.is_infinite()) return true;
        if (is_infinite() || other.is_infinite()) return false;
        return value_.get_value() == other.value_.get_value();
    }

};