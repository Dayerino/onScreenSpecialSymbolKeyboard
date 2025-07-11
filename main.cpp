#include <windows.h>
using namespace std;
LRESULT CALLBACK AnsiWndProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_CHAR:
        //wParam is value of the key
        //lParam -(not used here)
        if(lstrcmpA("Q",(LPCSTR)wParam)){

        }else{

        }
        break;
        default:
        return DefWindowProc(hWnd,message,wParam,lParam);
    }
    return 0;

}
int main(){
WNDCLASSA window;
window.style = CS_DBLCLKS | CS_PARENTDC;
window.lpfnWndProc = (WNDPROC)AnsiWndProc;
window.cbClsExtra = 0;
window.cbWndExtra = 0;
window.hInstance = GetModuleHandle(NULL);
window.hIcon = NULL;
window.hCursor = LoadCursor(NULL, (LPSTR)IDC_IBEAM);
window.hbrBackground = NULL;
window.lpszMenuName= NULL;
window.lpszClassName = "testwin";
RegisterClass(&window);
HWND hwnd = CreateWindowA(
    "testwin",
    "myWindow",
    WS_OVERLAPPEDWINDOW,
    1024,768,1024,768,
    NULL,NULL,
    window.hInstance,
    NULL
);
MSG msg;

ShowWindow(hwnd,SW_SHOW);
UpdateWindow(hwnd);
while(GetMessage(&msg,NULL,0,0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}