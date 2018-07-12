#include <cstdlib>

#include "RNG.h"
#include "RNG_rand.h"


RNG_rand::RNG_rand() :
    m_min_x { 0 },
    m_max_x { 1 },
    m_min_y { 0 },
    m_max_y { 1 },
    m_x { 0 },
    m_y { 0 },
    m_red { 0 },
    m_green { 0 },
    m_blue { 0 }
{
}

RNG_rand::~RNG_rand()
{
}

void RNG_rand::calc()
{
    // Compute x
    {
        auto dx = (m_max_x - m_min_x) + 1;

        auto r = rand() % dx;

        m_x = (m_min_x + r);
    }

    // Compute y
    {
        auto dy = (m_max_y - m_min_y) + 1;

        auto r = rand() % dy;

        m_y = (m_min_y + r);
    }

    // Compute red, green and blue components
    m_red   = rand() % 256;
    m_green = rand() % 256;
    m_blue  = rand() % 256;
}

void RNG_rand::limit_x(int min, int max)
{
    if (!is_range_valid(min, max))
    {
        return;
    }

    m_min_x = min;
    m_max_x = max;
}

void RNG_rand::limit_y(int min, int max)
{
    if (!is_range_valid(min, max))
    {
        return;
    }

    m_min_y = min;
    m_max_y = max;
}

int RNG_rand::x() const
{
    return m_x;
}

int RNG_rand::y() const
{
    return m_y;
}

int RNG_rand::red() const
{
    return m_red;
}

int RNG_rand::green() const
{
    return m_green;
}

int RNG_rand::blue() const
{
    return m_blue;
}

bool RNG_rand::is_range_valid(int min, int max) const
{
    return (min < max);
}
