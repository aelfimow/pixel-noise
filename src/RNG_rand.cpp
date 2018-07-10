#include "RNG.h"
#include "RNG_rand.h"

RNG_rand::RNG_rand() :
    m_min_x { 0 },
    m_max_x { 1 },
    m_min_y { 0 },
    m_max_y { 1 }
{
}

RNG_rand::~RNG_rand()
{
}

int RNG_rand::x() const
{
    auto diff = (m_max_x - m_min_x) + 1;

    auto r = rand() % diff;

    return (m_min_x + r);
}

int RNG_rand::y() const
{
    auto diff = (m_max_y - m_min_y) + 1;

    auto r = rand() % diff;

    return (m_min_y + r);
}

uint8_t RNG_rand::red() const
{
    auto r = rand() % 256;
    return r;
}

uint8_t RNG_rand::green() const
{
    auto r = rand() % 256;
    return r;
}

uint8_t RNG_rand::blue() const
{
    auto r = rand() % 256;
    return r;
}
