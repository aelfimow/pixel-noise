#include <Windows.h>

#include "WndProcParam.h"
#include "WndProcHandler.h"
#include "WM_DESTROY_Handler.h"
#include "PixelNoise.h"


WM_DESTROY_Handler::WM_DESTROY_Handler() :
    WndProcHandler {}
{
}

WM_DESTROY_Handler::~WM_DESTROY_Handler()
{
}

LRESULT WM_DESTROY_Handler::operator()([[maybe_unused]] const WndProcParam &param)
{
    PixelNoise::Destroy();
    PostQuitMessage(0);
    return 0;
}
