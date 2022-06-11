#include "Code.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"

using namespace std;
using namespace Parameters;

Code::Code() {
    for (int i = 0; i < codeLength; ++i)
        code[i] = RNG::uniformRandom(0, noOfColors - 1);
}

Code::Code(string code) {
    for (int i = 0; i < noOfColors; ++i)
        this->code[i] = code[i] - '0';
}

Code::Code(array<int, codeLength> code) : code(code) {}

Score Code::getScore() const {
    return score;
}

void Code::setScore(const Score& score) {
    this->score = score;
}

Score Code::compareCodes(const Code& code1, const Code& code2) {
    int black = 0, white = 0;
    array<bool, codeLength> matched = { false };
    array<int, noOfColors> colors1 = { 0 };
    for (const int& color : code1.code)
        colors1[color]++;
    for (int i = 0; i < codeLength; ++i)
        if (code1[i] == code2[i]) {
            matched[i] = true;
            colors1[code1[i]]--;
            black++;
        }
    for (int i = 0; i < codeLength; ++i)
        if (not matched[i] and colors1[code2[i]] > 0) {
            colors1[code2[i]]--;
            white++;
        }
    return Score(white, black);
}