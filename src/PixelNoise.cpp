#include <Windows.h>

#include "PixelNoise.h"

PixelNoise *PixelNoise::Inst = nullptr;

PixelNoise::PixelNoise() :
    m_WindowX { 0 },
    m_WindowY { 0 }
{
}

PixelNoise::~PixelNoise()
{
}

void PixelNoise::Create()
{
    delete Inst;
    Inst = new PixelNoise;
}

void PixelNoise::Set(int x, int y)
{
    Inst->m_WindowX = x;
    Inst->m_WindowY = y;
}

void PixelNoise::Draw(HWND hwnd)
{
    auto hdc = ::GetDC(hwnd);

    bool xLimitValid = (Inst->m_WindowX != 0);
    int x = xLimitValid ? (rand() % Inst->m_WindowX) : 0;

    bool yLimitValid = (Inst->m_WindowY != 0);
    int y = yLimitValid ? (rand() % Inst->m_WindowY) : 0;

    COLORREF rgb = RGB((rand() % 256u), (rand() % 256u), (rand() % 256u));

    ::SetPixel(hdc, x, y, rgb);

    ReleaseDC(hwnd, hdc);
}

void PixelNoise::Destroy()
{
    delete Inst;
    Inst = nullptr;
}
