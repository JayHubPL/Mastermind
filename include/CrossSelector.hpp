#pragma once

#include "Specimen.hpp"
#include <vector>

class CrossSelector {
    std::vector<bool> crossingMask;
public:
    CrossSelector();
    std::vector<Specimen> applyMaskToPopulation(std::vector<Specimen>& specimens) const;
private:
    void generateMask();
};