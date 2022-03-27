./*
@filename: BlackEngineException.cpp
@purpose:
*/

#include "blackengine/misc/blackengineException.h"

namespace blackengine::misc {
    blackengineException::blackengineException(const char* msg) : msg(msg) {}

    const char* blackengineException::what() const throw() {
        return msg;
    }
}
