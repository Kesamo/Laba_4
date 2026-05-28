#pragma once
#include <exception>
#include <string>
#include <format>
#include <source_location>

class Exception : public std::exception {
private:
    std::string full_msg;
public:
    Exception(std::string msg, const char* file, const char* func)
        : full_msg(std::format("{}() {}: {}", func, file, msg)) {}

    ~Exception() noexcept override = default;

    const char* what() const noexcept override {
        return full_msg.c_str();
    }
};

class OptionException : public Exception {
public:
    OptionException(std::source_location loc = std::source_location::current())
        : Exception("Option пуст", loc.file_name(), loc.function_name()) {}
};