#include "Sequence.hxx"

Sequence::Sequence()
    : rng(std::chrono::system_clock::now().time_since_epoch().count())
{
    std::iota(sequence.begin(), sequence.end(), 0);
}

uint8_t Sequence::GetNumber()
{
    if (nextNumber == sequence.size())
    {
        std::shuffle(sequence.begin(), sequence.end(), rng);
        nextNumber = 0;
    }

    return sequence[nextNumber++];
}
