#include <windows.h>
#include <iostream>
using namespace std;
LRESULT CALLBACK AnsiWndProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_CHAR://checks for keyboard button pressed
        //wParam is value of the key
        //lParam -(not used here)
        //if(lstrcmpA("Q",(LPCSTR)wParam)){ this fucntion compares 2 strings which are passed as the functions params, like strcmp in c
        if((char)wParam == 'Q' || (char)wParam == 'q'){
            MessageBoxA(hWnd,"Q was pressed","info",MB_OK);
        }else{
            MessageBoxA(hWnd,"Another button was pressed","info",MB_OK);
        }
        break;
        case WM_COMMAND://checks for a button click
        /* this is for later, to write capital letters
        // Press Shift
input[0].type = INPUT_KEYBOARD;
input[0].ki.wVk = VK_SHIFT;

// Press A
input[1].type = INPUT_KEYBOARD;
input[1].ki.wVk = 'A';

// Release A
input[2].type = INPUT_KEYBOARD;
input[2].ki.wVk = 'A';
input[2].ki.dwFlags = KEYEVENTF_KEYUP;

// Release Shift
input[3].type = INPUT_KEYBOARD;
input[3].ki.wVk = VK_SHIFT;
input[3].ki.dwFlags = KEYEVENTF_KEYUP;

// Send all inputs
SendInput(4, input, sizeof(INPUT));*/
            if(LOWORD(wParam) == 1){
                INPUT input[2] = {};
                input[0].type = INPUT_KEYBOARD;
                input[0].ki.wVk = 'A';
                input[0].ki.dwFlags = 0;//key down
                input[1].type = INPUT_KEYBOARD;
                input[1].ki.wVk = 'A';
                input[1].ki.dwFlags = KEYEVENTF_KEYUP;//key up
                //ShowWindow(hWnd,SW_MINIMIZE);
                SendInput(2,input,sizeof(INPUT));
            }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
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
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int windowWidth = 1024;
int windowHeight = 768;
int x = (screenWidth - windowWidth) / 2;
int y = (screenHeight - windowHeight) / 2;
HWND hwnd = CreateWindowExA(
    WS_EX_TOPMOST | WS_EX_NOACTIVATE,
    "testwin",
    "myWindow",
    WS_OVERLAPPEDWINDOW,
    x,y,windowWidth,windowHeight,
    NULL,NULL,
    window.hInstance,
    NULL
);
//SetWindowPos(hwnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);//makes the window always on top
HWND hButton = CreateWindowA(
    "BUTTON",//button class
    "A",//Button label
    WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,//styles: child of window, visible,pushbutton
    50,50,//x y position inside window
    40,40,//width & height
    hwnd,
    (HMENU)1, //control ID(used later to identify the button)
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
//okay so it works now, i cant use ai anymore, i will have to add the rest of the buttons and adjust the window size to better fit