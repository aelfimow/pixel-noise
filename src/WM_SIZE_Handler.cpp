#include <Windows.h>

#include "WndProcParam.h"
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

LRESULT WM_SIZE_Handler::operator()(const WndProcParam &param)
{
    int max_x = LOWORD(param.lParam());
    int max_y = HIWORD(param.lParam());

    PixelNoise::SetLimit(max_x, max_y);

    return 0;
}
