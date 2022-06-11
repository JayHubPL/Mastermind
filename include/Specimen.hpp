#pragma once

#include "Code.hpp"

class Specimen : public Code {
    int fitness;
public:
    Specimen();
    Specimen(Code code);
    void mutate();
    Specimen crossWith(const Specimen& other);
    void setFitness(int fitness);
    inline bool operator<(const Specimen& rhs) const { return fitness > rhs.fitness; };
};