#include "CodeKeeper.hpp"

CodeKeeper::CodeKeeper() : codeBroken(false), secretCode(Code::getRandomCode()) {}

CodeKeeper::CodeKeeper(Code code) : codeBroken(false), secretCode(code) {}

void CodeKeeper::checkTheGuess(Code& guess) {
    guess.setScore(Code::compareCodes(secretCode, guess));
    if (guess.getScore().isFullMatch())
        codeBroken = true;
}

bool CodeKeeper::wasCodeBroken() const {
    return codeBroken;
}

