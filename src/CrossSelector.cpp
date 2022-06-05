#include "CrossSelector.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"
#include <queue>
#include <math.h>

using namespace std;
using namespace Parameters;

CrossSelector::CrossSelector() : crossingMask(populationSize) {
    generateMask();
}

struct PQElem {
    double rating;
    int index;
    bool operator<(const PQElem& rhs) const { return rating > rhs.rating; }
};

double ratingFunction(int x) {
    return pow(RNG::uniformRandom(), 1 / pow(0.8, (double)(x - 5) * 0.6));
}

void CrossSelector::generateMask() {
    int toCross = (double)populationSize * percentOfPopulationToCross;
    priority_queue<PQElem> pq;
    for (int i = 0; i < populationSize; ++i) {
        double rating = ratingFunction(i);
        if (pq.size() < toCross)
            pq.push({ rating, i });
        else if (rating > pq.top().rating) {
            pq.pop();
            pq.push({ rating, i });
        }
    }
    while (not pq.empty()) {
        crossingMask[pq.top().index] = true;
        pq.pop();
    }
}

vector<Specimen> CrossSelector::applyMaskToPopulation(vector<Specimen>& specimens) {
    vector<Specimen> selected;
    for (int i = 0; i < populationSize; ++i)
        if (crossingMask[i])
            selected.push_back(specimens[i]);
    return selected;
}