#include <Windows.h>

#include "PixelNoise.h"

PixelNoise *PixelNoise::Inst = nullptr;

PixelNoise::PixelNoise()
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

void PixelNoise::Draw(HWND hwnd)
{
    auto hdc = ::GetDC(hwnd);

    int x = (rand() % 100);
    int y = (rand() % 100);

    COLORREF rgb = RGB((rand() % 256u), (rand() % 256u), (rand() % 256u));

    ::SetPixel(hdc, x, y, rgb);

    ReleaseDC(hwnd, hdc);
}

void PixelNoise::Destroy()
{
    delete Inst;
}
