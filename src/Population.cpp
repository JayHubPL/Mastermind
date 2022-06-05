#include "Population.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"
#include <algorithm>

using namespace std;
using namespace Parameters;

void Population::initialize() {
    generateRandomPopulation();
}

void Population::nextGeneration() {
    vector<Specimen> nextPopulation;
    vector<Specimen> specimensToCross = crossSelector.applyMaskToPopulation(population);
    int offspringCount = populationSize - specimensToCross.size();
    vector<Specimen> offsprings = makeOffsprings(specimensToCross, offspringCount);
    vector<Specimen> specimensToMutate(offsprings);
    if (survivorsMutate)
        specimensToMutate.insert(specimensToMutate.end(), specimensToCross.begin(), specimensToCross.end());
    else
        nextPopulation.insert(nextPopulation.end(), specimensToCross.begin(), specimensToCross.end());
    applyMutation(specimensToMutate);
    nextPopulation.insert(nextPopulation.end(), specimensToMutate.begin(), specimensToMutate.end());
    population = nextPopulation;

}

Specimen& Population::getBestSpecimen() {
    return population.front();
}

void Population::calculateFitness(const vector<Code>& prevGuesses) {
    for (auto& specimen : population) {
        int fitness = 0;
        for (const auto& guess : prevGuesses)
            fitness += Code::compareCodes(guess, specimen).distance(guess.getScore());
        specimen.setFitness(fitness);
    }
    sort(population.begin(), population.end());
}

void Population::applyMutation(vector<Specimen>& specimensToMutate) {
    for (auto& specimen : specimensToMutate)
        if (RNG::testEvent(mutationChance))
            specimen.mutate();
}

void Population::generateRandomPopulation() {
    population.clear();
    for (int i = 0; i < populationSize; ++i)
        population.push_back(Specimen());
}

vector<Specimen> Population::makeOffsprings(vector<Specimen>& specimensToCross, int offspringCount) {
    vector<Specimen> offsprings;
    while (offspringCount--) {
        int first, second;
        first = RNG::uniformRandom(0, specimensToCross.size() - 1);
        do {
            second = RNG::uniformRandom(0, specimensToCross.size() - 1);
        } while (first == second);
        offsprings.push_back(specimensToCross[first].crossWith(specimensToCross[second]));
    }
    return offsprings;
}