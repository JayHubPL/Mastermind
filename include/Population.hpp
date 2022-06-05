#pragma once

#include "Specimen.hpp"
#include "CrossSelector.hpp"
#include <vector>

class Population {
    std::vector<Specimen> population;
    CrossSelector crossSelector;
public:
    void initialize();
    void nextGeneration();
    void calculateFitness(const std::vector<Code>& prevGuesses);
    Specimen& getBestSpecimen();
private:
    void generateRandomPopulation();
    std::vector<Specimen> makeOffsprings(std::vector<Specimen>& specimensToCross, int offspringCount);
    void applyMutation(std::vector<Specimen>& specimensToMutate);
};