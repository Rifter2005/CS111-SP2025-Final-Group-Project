/**
 * Exceptions.h
 *
 * Defines custom exceptions used in the vehicle database system.
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class InvalidIndexException : public std::runtime_error {
public:
    InvalidIndexException() : std::runtime_error("Invalid index entered!") {}
};

#endif
