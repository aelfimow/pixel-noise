#include <Windows.h>

#include "WndProcHandler.h"
#include "WM_COMMAND_Handler.h"
#include "PixelNoise.h"
#include "main.h"


WM_COMMAND_Handler::WM_COMMAND_Handler() :
    WndProcHandler {}
{
}

WM_COMMAND_Handler::~WM_COMMAND_Handler()
{
}

LRESULT WM_COMMAND_Handler::operator()(HWND hwnd, WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    auto cmd = LOWORD(wParam);

    if (IDM_APP_START == cmd)
    {
        PixelNoise::Start();
        return 0;
    }

    if (IDM_APP_STOP == cmd)
    {
        PixelNoise::Stop();
        return 0;
    }

    if (IDM_APP_CLEAR == cmd)
    {
        ::InvalidateRect(hwnd, nullptr, TRUE);
        return 0;
    }

    if (IDM_RNG_RAND == cmd)
    {
        return 0;
    }

    if (IDM_RNG_XORSHIFT == cmd)
    {
        return 0;
    }

    if (IDM_APP_EXIT == cmd)
    {
        ::PostMessage(hwnd, WM_CLOSE, 0, 0);
        return 0;
    }

    return 0;
}
