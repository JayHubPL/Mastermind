#pragma once

class Score {
    int white;
    int black;
public:
    Score(int white = 0, int black = 0);
    bool isFullMatch() const;
    int distance(const Score& other) const;
};