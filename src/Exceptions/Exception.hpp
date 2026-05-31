#pragma once
#include <exception>
#include <string>
#include <format>
#include <source_location>
#include "Exceptions.hpp"

class OptionException : public Exception {
public:
    OptionException(std::source_location loc = std::source_location::current())
        : Exception("Option пуст", loc.file_name(), loc.function_name()) {}
};

class InfiniteException : public Exception {
public:
    InfiniteException(std::source_location loc = std::source_location::current())
        : Exception("Нельзя получить бесконечность", loc.file_name(), loc.function_name()) {}
};

class FiniteGeneratorException : public Exception {
public:
    FiniteGeneratorException(std::source_location loc = std::source_location::current())
        : Exception("Достигнут конец последовательности", loc.file_name(), loc.function_name()) {}
};