#pragma once

#include "GeneticAlgorithm.hpp"
#include "CodeKeeper.hpp"

class Mastermind {
    GeneticAlgorithm geneticAlgorithm;
    CodeKeeper codeKeeper;
public:
    void nextRound();
    void startGameLoop();
    bool isGameFinished() const;
    int getGenerationCount() const; // debug
private:
    Score guess(const Code& guess);
};