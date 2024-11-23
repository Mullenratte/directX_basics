#include <string>
#include <sstream>
#include "../headers/Window.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd( 800, 300, "First Window");

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
