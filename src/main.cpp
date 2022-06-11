#include "Mastermind.hpp"
#include "Parameters.hpp"
#include <iostream>
#include <sstream>

struct SimulationInfo {
    int terminatedCount;
    int finishedCount;
    double averageOfTries;
    double percentOfTerminated;
};
SimulationInfo simulate(int simulations);
void displayInfo(SimulationInfo si);

int main(int argc, char** argv) {
    int simulations = 1000;
    if (argc > 1) {
        std::istringstream ss(argv[1]);
        if (not(ss >> simulations)) {
            std::cerr << "Invalid number: " << argv[1] << '\n';
            return 1;
        }
        else if (not ss.eof()) {
            std::cerr << "Trailing characters after number: " << argv[1] << '\n';
            return 2;
        }
    }
    displayInfo(simulate(simulations));
    return 0;
}

SimulationInfo simulate(int simulations) {
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
    int finished = simulations - terminated;
    double average = (double)sum / finished;
    double percentOfTerminated = 100 * (double)terminated / simulations;
    return { terminated, finished, average, percentOfTerminated };
}

void displayInfo(SimulationInfo si) {
    std::cout << "TERMINATED:\n"
        << "count:\t\t" << si.terminatedCount << '\n'
        << "percent:\t" << si.percentOfTerminated << "%\n"
        << "\nSUCCESS:\n"
        << "count:\t\t" << si.finishedCount << '\n'
        << "average:\t" << si.averageOfTries << "\n";
}