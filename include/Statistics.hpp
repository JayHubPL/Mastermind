#pragma once

#include "Code.hpp"
#include <vector>

class Statistics {
public:
    int tries;
    bool terminated;

    Statistics(int tries, bool terminated);
};