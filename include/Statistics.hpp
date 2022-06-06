#pragma once

#include "Code.hpp"
#include <vector>

class Statistics {
public:
    int tries;
    std::vector<Code> guesses;
    bool terminated;

    Statistics(std::vector<Code> guesses);
};