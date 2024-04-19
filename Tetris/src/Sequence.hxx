#pragma once

#include "tetpch.hxx"

class Sequence
{
private:
    std::array<uint8_t, 7> sequence;
    uint8_t nextNumber = sequence.size();

    std::mt19937 rng;

public:
    Sequence();

    uint8_t GetNumber();
};
