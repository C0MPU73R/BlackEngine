#ifndef CRAFTCLONE_ENGINEEXCEPTION_H
#define CRAFTCLONE_ENGINEEXCEPTION_H

#include <exception>

/**
 * A general exception caused by the engine.
 * Allows for a customizable error message.
 */
class BlackcombException: public std::exception {
public:
    BlackcombException(const char* msg);
    virtual const char* what() const throw();
private:
    const char* msg;
};


#endif //CRAFTCLONE_ENGINEEXCEPTION_H