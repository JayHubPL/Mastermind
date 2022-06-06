#pragma once

#include "Parameters.hpp"
#include "Score.hpp"
#include <array>
#include <string>

class Code {
protected:
    std::array<int, Parameters::codeLength> code;
    Score score;
    inline int& operator[](std::size_t idx) { return code[idx]; }
    inline const int& operator[](std::size_t idx) const { return code[idx]; }
public:
    Code();
    Code(std::string code);
    Code(std::array<int, Parameters::codeLength> code);

    Score getScore() const;
    void setScore(const Score& score);

    static Code getRandomCode();
    static std::array<int, Parameters::codeLength> getRandomCodeArray();
    static Score compareCodes(const Code& code1, const Code& code2);
};