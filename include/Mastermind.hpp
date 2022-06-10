#pragma once

#include "GeneticAlgorithm.hpp"
#include "CodeKeeper.hpp"
#include "Statistics.hpp"

class Mastermind {
    GeneticAlgorithm geneticAlgorithm;
    CodeKeeper codeKeeper;
public:
    void startGameLoop();
    Statistics getStatistics() const;
private:
    bool isGameFinished() const;
    Score guess(const Code& guess);
};