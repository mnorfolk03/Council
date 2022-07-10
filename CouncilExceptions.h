#pragma once

#include <iostream>


// A class for throwing exceptions while traversing the parse tree
class ParsingException : public std::exception {

	public:
		const char * what() {
			std::string msg = "An exception occurred while traversing the parse tree. This was caused by: ";
			return (msg + cause).c_str();
		}

		ParsingException(const std::string & cause) : cause(cause) {}

	private:
		const std::string& cause;
};

class NameAlreadyDeclaredException : public std::exception {

	public:
		const char* what() {
			std::string msg = "An exception occurred while attempting to declare variable: ";
				return (msg + cause).c_str();
		}

		NameAlreadyDeclaredException(const std::string & cause) : cause(cause) {}

	private:
		const std::string& cause;
};
