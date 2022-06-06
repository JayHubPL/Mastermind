#pragma once

#include "Population.hpp"
#include "CodeKeeper.hpp"
#include "CrossSelector.hpp"
#include "Statistics.hpp"
#include <string>
#include <vector>

class GeneticAlgorithm {
    Code firstGuess;
    std::vector<Code> guesses;
    Population population;
    int generationNo;
public:
    GeneticAlgorithm(std::string firstGuess = "0011");
    Code& getNextGuess();
    void nextStep();
    bool generationLimitReached() const;
    int getGenerationNo() const;
};