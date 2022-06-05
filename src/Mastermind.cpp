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

int Mastermind::getGenerationCount() const {
    return geneticAlgorithm.getGenerationNo();
}