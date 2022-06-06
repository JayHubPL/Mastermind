#include "Statistics.hpp"
#include "Parameters.hpp"

Statistics::Statistics(std::vector<Code> guesses) : guesses(guesses), terminated(false), tries(guesses.size()) {
    if (tries == Parameters::maxGenerations)
        terminated = true;
}