#include <windows.h>
#include <winuser.h>
#include <iostream>
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
/*	A-Z 0x41–0x5A
    0-9 0x30–0x39
    
NumPad 0–9	0x60–0x69
Multiply	0x6A
Add	0x6B
Separator	0x6C
Subtract	0x6D
Decimal	0x6E
Divide	0x6F

Left	0x25
Up	0x26
Right	0x27
Down	0x28
Home	0x24
End	0x23
Page Up	0x21
Page Down	0x22
Insert	0x2D
Delete	0x2E

Shift	0x10
Ctrl	0x11
Alt (Menu)	0x12
Caps Lock	0x14
Tab	0x09
Enter	0x0D
Escape	0x1B
Spacebar	0x20

F1–F12	0x70–0x7B
F13–F24	0x7C–0x87

Left Button	0x01
Right Button	0x02
Middle Button	0x04
XButton1	0x05
XButton2	0x06
full list https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/
using namespace std;
void BTNINPUT(int keyHexVal){
    INPUT input[2]={};
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = keyHexVal;
    input[0].ki.dwFlags = 0;
    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = keyHexVal;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(2,input,sizeof(INPUT));
}
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
            if(LOWORD(wParam) == 1){BTNINPUT(0x41);}//a
            if(LOWORD(wParam) == 2){BTNINPUT(0x5A);}//z
            if(LOWORD(wParam) == 3){BTNINPUT(0x45);}//e
            if(LOWORD(wParam) == 4){BTNINPUT(0x52);}//r
            if(LOWORD(wParam) == 5){BTNINPUT(0x54);}//t
            if(LOWORD(wParam) == 6){BTNINPUT(0x59);}//y
            if(LOWORD(wParam) == 7){BTNINPUT(0x55);}//u
            if(LOWORD(wParam) == 8){BTNINPUT(0x49);}//i
            if(LOWORD(wParam) == 9){BTNINPUT(0x4F);}//o
            if(LOWORD(wParam) == 10){BTNINPUT(0x50);}//p
            if(LOWORD(wParam) == 11){BTNINPUT(0x5A);}//^ must add with the shift key
            if(LOWORD(wParam) ==12){BTNINPUT(0x5A);}//$ must add with the shift key
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
int windowWidth = 960;
int windowHeight = 270;
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
HWND aButton = CreateWindowA(
    "BUTTON",//button class
    "a",//Button label
    WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,//styles: child of window, visible,pushbutton
    50,50,//x y position inside window
    30,30,//width & height
    hwnd,
    (HMENU)1, //control ID(used later to identify the button)
    window.hInstance,
    NULL
);
//first row
//second row
//third row
HWND zButton = CreateWindowA("Button","z",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,50,30,30,hwnd,(HMENU)2,window.hInstance,NULL);
HWND eButton = CreateWindowA("Button","e",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,120,50,30,30,hwnd,(HMENU)3,window.hInstance,NULL);
HWND rButton = CreateWindowA("Button","r",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,155,50,30,30,hwnd,(HMENU)4,window.hInstance,NULL);
HWND tButton = CreateWindowA("Button","t",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,190,50,30,30,hwnd,(HMENU)5,window.hInstance,NULL);
HWND yButton = CreateWindowA("Button","y",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,225,50,30,30,hwnd,(HMENU)6,window.hInstance,NULL);
HWND uButton = CreateWindowA("Button","u",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,260,50,30,30,hwnd,(HMENU)7,window.hInstance,NULL);
HWND iButton = CreateWindowA("Button","i",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,295,50,30,30,hwnd,(HMENU)8,window.hInstance,NULL);
HWND oButton = CreateWindowA("Button","o",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,330,50,30,30,hwnd,(HMENU)9,window.hInstance,NULL);
HWND pButton = CreateWindowA("Button","p",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,365,50,30,30,hwnd,(HMENU)10,window.hInstance,NULL);
HWND caretButton = CreateWindowA("Button","^",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,400,50,30,30,hwnd,(HMENU)11,window.hInstance,NULL);
HWND dollarButton = CreateWindowA("Button","$",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,435,50,30,30,hwnd,(HMENU)12,window.hInstance,NULL);
//fourth row
MSG msg;

ShowWindow(hwnd,SW_SHOW);
UpdateWindow(hwnd);
while(GetMessage(&msg,NULL,0,0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}
//okay so it works now, i cant use ai anymore, i will have to add the rest of the buttons and adjust the window size to better fit