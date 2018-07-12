#include <Windows.h>

#include "PixelNoise.h"

#include "RNG.h"
#include "RNG_rand.h"


PixelNoise *PixelNoise::Inst = nullptr;

PixelNoise::PixelNoise() :
    m_RNG { new RNG_rand }
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

void PixelNoise::SetLimit(int max_x, int max_y)
{
    Inst->m_RNG->limit_x(0, max_x);
    Inst->m_RNG->limit_y(0, max_y);
}

void PixelNoise::Draw(HWND hwnd)
{
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
