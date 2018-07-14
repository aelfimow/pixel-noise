#include <Windows.h>

#include "PixelNoise.h"

#include "RNG.h"
#include "RNG_rand.h"
#include "RNG_xorshift.h"


PixelNoise *PixelNoise::Inst = nullptr;

PixelNoise::PixelNoise() :
    m_RNG { new ::RNG_rand },
    m_is_started { true },
    m_max_x { 0 },
    m_max_y { 0 }
{
}

PixelNoise::~PixelNoise()
{
    delete m_RNG;
}

void PixelNoise::Create()
{
    delete Inst;
    Inst = new PixelNoise;
}

void PixelNoise::Start()
{
    Inst->m_is_started = true;
}

void PixelNoise::Stop()
{
    Inst->m_is_started = false;
}

void PixelNoise::SetLimit(int max_x, int max_y)
{
    Inst->m_RNG->limit_x(0, max_x);
    Inst->m_RNG->limit_y(0, max_y);
    Inst->m_max_x = max_x;
    Inst->m_max_y = max_y;
}

void PixelNoise::Draw(HWND hwnd)
{
    if (!Inst->m_is_started)
    {
        return;
    }

    RNG *pRNG = Inst->m_RNG;

    pRNG->calc();

    auto hdc = ::GetDC(hwnd);
    {
        int x = pRNG->x();
        int y = pRNG->y();

        int red   = pRNG->red();
        int green = pRNG->green();
        int blue  = pRNG->blue();

        COLORREF rgb = RGB(red, green, blue);

        ::SetPixel(hdc, x, y, rgb);
    }
    ::ReleaseDC(hwnd, hdc);
}

void PixelNoise::Destroy()
{
    delete Inst;
    Inst = nullptr;
}

void PixelNoise::RNG_rand()
{
    delete Inst->m_RNG;
    Inst->m_RNG = new ::RNG_rand;
    SetLimit(Inst->m_max_x, Inst->m_max_y);
}

void PixelNoise::RNG_xorshift()
{
    delete Inst->m_RNG;
    Inst->m_RNG = new ::RNG_xorshift;
    SetLimit(Inst->m_max_x, Inst->m_max_y);
}
