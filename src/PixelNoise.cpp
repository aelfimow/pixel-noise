#include <Windows.h>

#include "PixelNoise.h"


PixelNoise::~PixelNoise()
{
}

void PixelNoise::Create()
{
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
}
