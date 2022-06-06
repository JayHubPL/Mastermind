#include "GeneticAlgorithm.hpp"

#define FIRST_GEN_NUMBER 1

using namespace std;
using namespace Parameters;

GeneticAlgorithm::GeneticAlgorithm(string firstGuess) : firstGuess(firstGuess), generationNo(FIRST_GEN_NUMBER) {
    population.initialize();
}

Code& GeneticAlgorithm::getNextGuess() {
    Code nextGuess = population.getBestSpecimen();
    if (generationNo == FIRST_GEN_NUMBER)
        nextGuess = firstGuess;
    guesses.push_back(nextGuess);
    return guesses.back();
}

void GeneticAlgorithm::nextStep() {
    population.calculateFitness(guesses);
    population.nextGeneration();
    generationNo++;
}

bool GeneticAlgorithm::generationLimitReached() const {
    return (generationNo >= maxGuesses);
}

int GeneticAlgorithm::getGenerationNo() const {
    return generationNo;
}