#include <Windows.h>
#include <map>

#include "main.h"
#include "MainWindow.h"
#include "WndProcParam.h"
#include "WndProcHandler.h"
#include "WM_SIZE_Handler.h"
#include "WM_CREATE_Handler.h"
#include "WM_COMMAND_Handler.h"
#include "WM_DESTROY_Handler.h"
#include "WM_PAINT_Handler.h"
#include "PixelNoise.h"


MainWindow *MainWindow::Inst = nullptr;

const TCHAR MainWindow::MainWindowName[] = TEXT("Pixel Noise");


MainWindow::MainWindow(HINSTANCE hInstance, int iCmdShow) :
    m_hInstance { hInstance },
    m_CmdShow { iCmdShow },
    m_WndProcMap { },
    m_Wndclass { },
    m_hWindow { nullptr }
{
}

MainWindow::~MainWindow()
{
    for (auto &elem: m_WndProcMap)
    {
        delete elem.second;
    }
}

HMENU MainWindow::MainWindowMenu()
{
    auto hCtrlMenu = ::CreateMenu();
    {
        ::AppendMenu(hCtrlMenu, MF_STRING, IDM_APP_START, TEXT("Start"));
        ::AppendMenu(hCtrlMenu, MF_STRING, IDM_APP_STOP, TEXT("Stop"));
        ::AppendMenu(hCtrlMenu, MF_STRING, IDM_APP_CLEAR, TEXT("Clear"));
        ::AppendMenu(hCtrlMenu, MF_SEPARATOR, 0, nullptr);
        ::AppendMenu(hCtrlMenu, MF_STRING, IDM_APP_EXIT, TEXT("&Exit"));
    }

    auto hRNGMenu = ::CreateMenu();
    {
        ::AppendMenu(hRNGMenu, MF_STRING, IDM_RNG_RAND, TEXT("rand()"));
        ::AppendMenu(hRNGMenu, MF_STRING, IDM_RNG_XORSHIFT, TEXT("xorshift()"));
    }

    auto hMenu = ::CreateMenu();
    {
        ::AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hCtrlMenu, TEXT("&Control"));
        ::AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hRNGMenu, TEXT("&RNG"));
    }

    return hMenu;
}

void MainWindow::MessageBox_Error(const TCHAR *errStr)
{
    (void)::MessageBox(nullptr, errStr, MainWindowName, MB_ICONERROR);
}

void MainWindow::Create(HINSTANCE hInstance, int iCmdShow)
{
    delete Inst;
    Inst = new MainWindow { hInstance, iCmdShow };
}

void MainWindow::Show()
{
    Inst->m_WndProcMap[WM_SIZE]    = new WM_SIZE_Handler;
    Inst->m_WndProcMap[WM_CREATE]  = new WM_CREATE_Handler;
    Inst->m_WndProcMap[WM_COMMAND] = new WM_COMMAND_Handler;
    Inst->m_WndProcMap[WM_DESTROY] = new WM_DESTROY_Handler;
    Inst->m_WndProcMap[WM_PAINT]   = new WM_PAINT_Handler;

    Inst->m_Wndclass.style         = (CS_HREDRAW | CS_VREDRAW);
    Inst->m_Wndclass.lpfnWndProc   = WndProc;
    Inst->m_Wndclass.cbClsExtra    = 0;
    Inst->m_Wndclass.cbWndExtra    = 0;
    Inst->m_Wndclass.hInstance     = Inst->m_hInstance;
    Inst->m_Wndclass.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    Inst->m_Wndclass.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    Inst->m_Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    Inst->m_Wndclass.lpszMenuName  = nullptr;
    Inst->m_Wndclass.lpszClassName = MainWindowName;

    auto RegisterClassResult = ::RegisterClass(&Inst->m_Wndclass);

    if (0 == RegisterClassResult)
    {
        MessageBox_Error(TEXT("Error in RegisterClass"));
        return;
    }

    Inst->m_hWindow = ::CreateWindow(
            MainWindowName,
            MainWindowName,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            500,
            400,
            nullptr,
            MainWindowMenu(),
            Inst->m_hInstance,
            nullptr);

    if (Inst->m_hWindow == nullptr)
    {
        MessageBox_Error(TEXT("Error in CreateWindow"));
        return;
    }

    ShowWindow(Inst->m_hWindow, Inst->m_CmdShow);

    auto UpdateWindowResult = ::UpdateWindow(Inst->m_hWindow);

    if (UpdateWindowResult == FALSE)
    {
        MessageBox_Error(TEXT("Error in UpdateWindow"));
        return;
    }
}

void MainWindow::Run()
{
    bool done = false;

    while (!done)
    {
        MSG msg;

        auto peekres = ::PeekMessage(&msg, NULL, 0u, 0u, PM_REMOVE);

        bool isMsg = (peekres != 0);

        if (isMsg)
        {
            done = (WM_QUIT == msg.message);

            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        else
        {
            PixelNoise::Draw(Inst->m_hWindow);
        }
    }
}

void MainWindow::Destroy()
{
    delete Inst;
    Inst = nullptr;
}

LRESULT CALLBACK MainWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (auto it = Inst->m_WndProcMap.find(message); it != Inst->m_WndProcMap.end())
    {
        WndProcHandler &handler { *it->second };

        const WndProcParam param(hwnd, wParam, lParam);

        auto result = handler(param);

        return result;
    }
    else
    {
        return ::DefWindowProc(hwnd, message, wParam, lParam);
    }
}
