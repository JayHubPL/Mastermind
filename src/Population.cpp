#include "Population.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"
#include <algorithm>

using namespace std;
using namespace Parameters;

Population::Population() {
    for (int i = 0; i < populationSize; ++i)
        population.push_back(Specimen());
}

void Population::nextGeneration() {
    vector<Specimen> parents = crossSelector.applyMaskToPopulation(population);
    vector<Specimen> nextGen = makeOffsprings(parents, populationSize - parents.size());
    applyMutation(nextGen);
    if (parentsMutate)
        applyMutation(parents);
    nextGen.insert(nextGen.end(), parents.begin(), parents.end());
    population = nextGen;
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