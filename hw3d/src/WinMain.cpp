#include <string>
#include <sstream>
#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    // enables the application to quit properly when closing the window
    // this is needed because DefWindowProc allows closing window but is not quitting the underlying application
    case WM_CLOSE:
        PostQuitMessage(10);
        break;
    case WM_KEYDOWN:
        if (wParam == 'F')
        {
            SetWindowText(hWnd, L"Key [F] pressed!");
        }
        break;
    case WM_KEYUP:
        if (wParam == 'F')
        {
            SetWindowText(hWnd, L"Key [F] released!");
        }
        break;
    // reacts to keystrokes with corresponding text characters (e.g. does not get called if F1/F2/... is pressed)
    // also distinguishes between capital and lower case letters
    case WM_CHAR:
        {
            static std::string title;
            title.push_back((char)wParam);
            SetWindowTextA(hWnd, title.c_str());
        }
        break;
    case WM_LBUTTONDOWN:
        POINTS pt = MAKEPOINTS(lParam);
        std::ostringstream oss;
        oss << "(" << pt.x << ", " << pt.y << ")";
        SetWindowTextA(hWnd, oss.str().c_str());

        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const auto pClassName = L"DirectX Game";

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(
        0,
        pClassName,
        L"Boring Window",
        (WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION),
        600,
        400,
        640,
        480,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    ShowWindow(hWnd, SW_SHOW);

    // message pump

    // if wMsgFilterMin and -Max are both 0, GetMessage takes in ALL message numbers
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        // generates WM_CHAR messages
        TranslateMessage(&msg);

        DispatchMessage(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }
    else
    {
        return msg.wParam;
    }
}
