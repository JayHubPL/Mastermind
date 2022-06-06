#include "Mastermind.hpp"

void Mastermind::nextRound() {
    codeKeeper.checkTheGuess(geneticAlgorithm.getNextGuess());
    if (codeKeeper.wasCodeBroken() or geneticAlgorithm.generationLimitReached())
        return;
    geneticAlgorithm.nextStep();
}

void Mastermind::startGameLoop() {
    codeKeeper.checkTheGuess(geneticAlgorithm.getNextGuess());
    while (not isGameFinished()) {
        geneticAlgorithm.nextStep();
        codeKeeper.checkTheGuess(geneticAlgorithm.getNextGuess());
    }
}

bool Mastermind::isGameFinished() const {
    return (codeKeeper.wasCodeBroken() or geneticAlgorithm.generationLimitReached());
}

Statistics Mastermind::getStatistics() const {
    bool terminated = geneticAlgorithm.generationLimitReached() and not codeKeeper.wasCodeBroken();
    return Statistics(geneticAlgorithm.getGenerationNo(), terminated);
}