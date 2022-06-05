#include "Specimen.hpp"
#include "RNG.hpp"
#include "Parameters.hpp"

using namespace std;
using namespace Parameters;

Specimen::Specimen() : Code() {}

Specimen::Specimen(Code code) : Code(code) {}

void Specimen::mutate() {
    int mutationIndex = RNG::uniformRandom(0, Parameters::codeLength - 1);
    int change = (RNG::uniformRandom(0, 1) == 0 ? -1 : 1);
    code[mutationIndex] += change;
    code[mutationIndex] %= Parameters::noOfColors;
}

Specimen Specimen::crossWith(const Specimen& other) {
    array<int, codeLength> offspringCode;
    for (int i = 0; i < codeLength; ++i)
        offspringCode[i] = (i < splitIndex ? code[i] : other[i]);
    return Specimen(offspringCode); // TODO check if this works
}

bool Specimen::operator<(const Specimen& rhs) const {
    return fitness > rhs.fitness;
}

void Specimen::setFitness(int fitness) {
    this->fitness = fitness;
}