#include <windows.h>

LPCSTR classname = "Win";
LPCSTR caption = "my windows";

int x=200, y=200;
int width = 666, height = 666;

long long WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
    switch (msg)
    {
    case /* constant-expression */
        /* code */
        WM_CLOSE:case WM_DESTROY:case WM_QUIT:
        exit(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}
int WINAPI WinMain(HINSTANCE hInst,
            HINSTANCE hPrev,
            LPSTR lpCmdLine,
            int nCmdShow)
            {
                WNDCLASSA wc;
                memset(&wc, 0, sizeof(wc));
                wc.lpszClassName = classname;
                wc.hInstance = hInst;
                wc.lpfnWndProc = WndProc;
                RegisterClassA(&wc);
                HWND hwnd = CreateWindowA(classname, caption, WS_VISIBLE|WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, hInst, NULL); 
                if(hwnd == NULL) return -1;
                MSG msg;
                while(true) if(GetMessage(&msg, NULL, 0, 0))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
