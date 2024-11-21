#include <Windows.h>

INT CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const auto pClassName = L"DirectX Game";
    
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx( &wc );

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
    while(true);
    
    return 0;
}
