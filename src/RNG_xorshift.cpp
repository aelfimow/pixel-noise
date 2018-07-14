#include <cstdlib>

#include "RNG.h"
#include "RNG_xorshift.h"


RNG_xorshift::RNG_xorshift() :
    m_state { 1 },
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

RNG_xorshift::~RNG_xorshift()
{
}

void RNG_xorshift::calc()
{
    // Compute x
    m_state = xorshift(m_state);
    {
        auto dx = (m_max_x - m_min_x) + 1;

        auto r = m_state % dx;

        m_x = (m_min_x + r);
    }

    // Compute y
    m_state = xorshift(m_state);
    {
        auto dy = (m_max_y - m_min_y) + 1;

        auto r = m_state % dy;

        m_y = (m_min_y + r);
    }

    // Compute red, green and blue components
    m_state = xorshift(m_state);
    m_red   = m_state % 256;

    m_state = xorshift(m_state);
    m_green = m_state % 256;

    m_state = xorshift(m_state);
    m_blue  = m_state % 256;
}

void RNG_xorshift::limit_x(int min, int max)
{
    if (!is_range_valid(min, max))
    {
        return;
    }

    m_min_x = min;
    m_max_x = max;
}

void RNG_xorshift::limit_y(int min, int max)
{
    if (!is_range_valid(min, max))
    {
        return;
    }

    m_min_y = min;
    m_max_y = max;
}

int RNG_xorshift::x() const
{
    return m_x;
}

int RNG_xorshift::y() const
{
    return m_y;
}

int RNG_xorshift::red() const
{
    return m_red;
}

int RNG_xorshift::green() const
{
    return m_green;
}

int RNG_xorshift::blue() const
{
    return m_blue;
}

bool RNG_xorshift::is_range_valid(int min, int max) const
{
    return (min < max);
}

size_t RNG_xorshift::xorshift(size_t value) const
{
    value ^= (value << 17);
    value ^= (value >> 15);
    value ^= (value << 58);

    return value;
}
