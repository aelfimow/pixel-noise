#include <Windows.h>

#include "WndProcParam.h"
#include "WndProcHandler.h"
#include "WM_CREATE_Handler.h"
#include "PixelNoise.h"


WM_CREATE_Handler::WM_CREATE_Handler() :
    WndProcHandler {}
{
}

WM_CREATE_Handler::~WM_CREATE_Handler()
{
}

LRESULT WM_CREATE_Handler::operator()([[maybe_unused]] const WndProcParam &param)
{
    PixelNoise::Create();
    return 0;
}
