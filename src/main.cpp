#include "Mastermind.hpp"
#include "Parameters.hpp"
#include <iostream>

int main() {
    int simulations = 1000;
    int terminated = 0;
    long long sum = 0;
    for (int i = 0; i < simulations; ++i) {
        Mastermind mastermind;
        mastermind.startGameLoop();
        Statistics stats = mastermind.getStatistics();
        if (stats.terminated)
            terminated++;
        else
            sum += stats.tries;
    }
    std::cout << "Terminated:\n"
        << "count:\t\t" << terminated << '\n'
        << "percent:\t" << 100 * ((double)terminated / simulations) << "%\n"
        << "\nSuccess:\n"
        << "count:\t\t" << simulations - terminated << '\n'
        << "average:\t" << (double)sum / (simulations - terminated) << "\n";
    return 0;
}