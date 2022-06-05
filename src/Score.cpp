#include "Score.hpp"
#include "Parameters.hpp"
#include <algorithm>

Score::Score(int white, int black) : white(white), black(black) {}

bool Score::isFullMatch() const {
    return black == Parameters::codeLength;
}

int Score::distance(const Score& other) const {
    int s1white = white, s1black = black;
    int s2white = other.white, s2black = other.black;
    while (s1white > 0) {
        if (s2white == 0)
            break;
        s1white--;
        s2white--;
    }
    while (s1black > 0 and s2black > 0) {
        s1black--;
        s2black--;
    }
    return -1 * std::max(s1white + s1black, s2white + s2black);
}
