#pragma once

#include "Code.hpp"
#include <string>

class CodeKeeper {
    Code secretCode;
    bool codeBroken;
public:
    CodeKeeper();
    CodeKeeper(Code code);
    void checkTheGuess(Code& guess);
    bool wasCodeBroken() const;
};