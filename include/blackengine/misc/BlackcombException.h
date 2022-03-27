#ifndef blackengine_ENGINEEXCEPTION_H
#define blackengine_ENGINEEXCEPTION_H

#include <exception>

namespace blackengine::misc {
    /**
     * A general exception caused by the engine.
     * Allows for a customizable error message.
     */
    class blackengineException : public std::exception {
    public:
        blackengineException(const char* msg);
        virtual const char* what() const throw();
    private:
        const char* msg;
    };
}

#endif //blackengine_ENGINEEXCEPTION_H
