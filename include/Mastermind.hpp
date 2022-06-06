#pragma once

#include "GeneticAlgorithm.hpp"
#include "CodeKeeper.hpp"
#include "Statistics.hpp"

class Mastermind {
    GeneticAlgorithm geneticAlgorithm;
    CodeKeeper codeKeeper;
public:
    void nextRound();
    void startGameLoop();
    bool isGameFinished() const;
    Statistics getStatistics() const;
private:
    Score guess(const Code& guess);
};