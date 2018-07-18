#include <Windows.h>

#include "WndProcParam.h"
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

LRESULT WM_COMMAND_Handler::operator()(const WndProcParam &param)
{
    auto cmd = LOWORD(param.wParam());

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
        ::InvalidateRect(param.hwnd(), nullptr, TRUE);
        return 0;
    }

    if (IDM_RNG_RAND == cmd)
    {
        ::InvalidateRect(param.hwnd(), nullptr, TRUE);
        PixelNoise::RNG_rand();
        return 0;
    }

    if (IDM_RNG_XORSHIFT == cmd)
    {
        ::InvalidateRect(param.hwnd(), nullptr, TRUE);
        PixelNoise::RNG_xorshift();
        return 0;
    }

    if (IDM_APP_EXIT == cmd)
    {
        ::PostMessage(param.hwnd(), WM_CLOSE, 0, 0);
        return 0;
    }

    return 0;
}
