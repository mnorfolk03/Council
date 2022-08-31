#pragma once

#include <iostream>
#include <vector>

std::vector<std::exception> errors;

void logError(std::exception ex) {
    errors.push_back(ex);
}

void printErrors() {
    for (auto &error: errors) {
        std::cout << error.what() << std::endl;
    }
}

// A class for throwing exceptions while traversing the parse tree
class ParsingException : public std::exception {

public:
    const char *what() {
        std::string msg = "An exception occurred while traversing the parse tree. This was caused by: ";
        return (msg + cause).c_str();
    }

    ParsingException(const std::string &cause) : cause(cause) {}

private:
    const std::string &cause;
};

class NameAlreadyDeclaredException : public std::exception {

public:
    const char *what() {
        std::string msg = "An exception occurred while attempting to declare variable: ";
        return (msg + cause).c_str();
    }

    NameAlreadyDeclaredException(const std::string &cause) : cause(cause) {}

private:
    const std::string &cause;
};

class MisMatchTypeException : public std::exception {
public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return exception::what();
    }
};

class IllegalStateException : public std::exception {

public:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Reached an illegal state";
    }
};
