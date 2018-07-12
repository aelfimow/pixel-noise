#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_SIZE_Handler.h"
#include "PixelNoise.h"


WM_SIZE_Handler::WM_SIZE_Handler() :
    WndProcHandler {}
{
}

WM_SIZE_Handler::~WM_SIZE_Handler()
{
}

LRESULT WM_SIZE_Handler::operator()([[maybe_unused]] HWND hwnd, [[maybe_unused]] WPARAM wParam, LPARAM lParam)
{
    int max_x = LOWORD(lParam);
    int max_y = HIWORD(lParam);

    PixelNoise::SetLimit(max_x, max_y);

    return 0;
}
