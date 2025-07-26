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
//first row
HWND escButton = CreateWindowA("Button","ESC",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,15,30,30,hwnd,(HMENU)26,window.hInstance,NULL);
HWND F1Button = CreateWindowA("Button","F1",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,15,30,30,hwnd,(HMENU)27,window.hInstance,NULL);
HWND F2Button = CreateWindowA("Button","F2",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 115,15,30,30,hwnd,(HMENU)28,window.hInstance,NULL);
HWND F3Button = CreateWindowA("Button","F3",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 145,15,30,30,hwnd,(HMENU)29,window.hInstance,NULL);
HWND F4Button = CreateWindowA("Button","F4",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 175,15,30,30,hwnd,(HMENU)30,window.hInstance,NULL);
HWND F5Button = CreateWindowA("Button","F5",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 225,15,30,30,hwnd,(HMENU)31,window.hInstance,NULL);
HWND F6Button = CreateWindowA("Button","F6",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 255,15,30,30,hwnd,(HMENU)32,window.hInstance,NULL);
HWND F7Button = CreateWindowA("Button","F7",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 285,15,30,30,hwnd,(HMENU)32,window.hInstance,NULL);
HWND F8Button = CreateWindowA("Button","F8",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 315,15,30,30,hwnd,(HMENU)33,window.hInstance,NULL);
HWND F9Button = CreateWindowA("Button","F9",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 365,15,30,30,hwnd,(HMENU)34,window.hInstance,NULL);
HWND F10Button = CreateWindowA("Button","F10",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 395,15,30,30,hwnd,(HMENU)35,window.hInstance,NULL);
HWND F11Button = CreateWindowA("Button","F11",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 425,15,30,30,hwnd,(HMENU)36,window.hInstance,NULL);
HWND F12Button = CreateWindowA("Button","F12",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 455,15,30,30,hwnd,(HMENU)37,window.hInstance,NULL);
//second row
HWND tildeButton = CreateWindowA("Button","²",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,50,30,30,hwnd,(HMENU)38,window.hInstance,NULL);
HWND oneButton = CreateWindowA("Button","1",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50,50,30,30,hwnd,(HMENU)39,window.hInstance,NULL);
HWND twoButton = CreateWindowA("Button","2",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,50,30,30,hwnd,(HMENU)40,window.hInstance,NULL);
HWND threeButton = CreateWindowA("Button","3",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120,50,30,30,hwnd,(HMENU)41,window.hInstance,NULL);
HWND fourButton = CreateWindowA("Button","4",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 155,50,30,30,hwnd,(HMENU)42,window.hInstance,NULL);
HWND fiveButton = CreateWindowA("Button","5",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 190,50,30,30,hwnd,(HMENU)43,window.hInstance,NULL);
HWND sixButton = CreateWindowA("Button","6",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 225,50,30,30,hwnd,(HMENU)44,window.hInstance,NULL);
HWND sevenButton = CreateWindowA("Button","7",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 260,50,30,30,hwnd,(HMENU)45,window.hInstance,NULL);
HWND eightButton = CreateWindowA("Button","8",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 295,50,30,30,hwnd,(HMENU)46,window.hInstance,NULL);
HWND nineButton = CreateWindowA("Button","9",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 330,50,30,30,hwnd,(HMENU)47,window.hInstance,NULL);
HWND zeroButton = CreateWindowA("Button","0",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 365,50,30,30,hwnd,(HMENU)48,window.hInstance,NULL);
HWND smalloButton = CreateWindowA("Button","°",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,50,30,30,hwnd,(HMENU)49,window.hInstance,NULL);
HWND equalsButton = CreateWindowA("Button","=",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 435,50,30,30,hwnd,(HMENU)50,window.hInstance,NULL);
//third row
HWND tabButton=CreateWindowA("Button","Tab",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,85,30,30,hwnd,(HMENU)25,window.hInstance,NULL);
HWND aButton = CreateWindowA(
    "BUTTON",//button class
    "a",//Button label
    WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,//styles: child of window, visible,pushbutton
    50,85,//x y position inside window
    30,30,//width & height
    hwnd,
    (HMENU)1, //control ID(used later to identify the button)
    window.hInstance,
    NULL
);
HWND zButton = CreateWindowA("Button","z",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,85,30,30,hwnd,(HMENU)2,window.hInstance,NULL);
HWND eButton = CreateWindowA("Button","e",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,120,85,30,30,hwnd,(HMENU)3,window.hInstance,NULL);
HWND rButton = CreateWindowA("Button","r",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,155,85,30,30,hwnd,(HMENU)4,window.hInstance,NULL);
HWND tButton = CreateWindowA("Button","t",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,190,85,30,30,hwnd,(HMENU)5,window.hInstance,NULL);
HWND yButton = CreateWindowA("Button","y",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,225,85,30,30,hwnd,(HMENU)6,window.hInstance,NULL);
HWND uButton = CreateWindowA("Button","u",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,260,85,30,30,hwnd,(HMENU)7,window.hInstance,NULL);
HWND iButton = CreateWindowA("Button","i",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,295,85,30,30,hwnd,(HMENU)8,window.hInstance,NULL);
HWND oButton = CreateWindowA("Button","o",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,330,85,30,30,hwnd,(HMENU)9,window.hInstance,NULL);
HWND pButton = CreateWindowA("Button","p",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,365,85,30,30,hwnd,(HMENU)10,window.hInstance,NULL);
HWND caretButton = CreateWindowA("Button","^",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,400,85,30,30,hwnd,(HMENU)11,window.hInstance,NULL);
HWND dollarButton = CreateWindowA("Button","$",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,435,85,30,30,hwnd,(HMENU)12,window.hInstance,NULL);
//fourth row
HWND CapsButton = CreateWindowA("Button","CAPS",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,120,40,30,hwnd,(HMENU)51,window.hInstance,NULL);
HWND qButton = CreateWindowA("Button","q",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,55,120,30,30,hwnd,(HMENU)13,window.hInstance,NULL);
HWND sButton = CreateWindowA("Button","s",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,90,120,30,30,hwnd,(HMENU)14,window.hInstance,NULL);
HWND dButton = CreateWindowA("Button","d",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,125,120,30,30,hwnd,(HMENU)15,window.hInstance,NULL);
HWND fButton = CreateWindowA("Button","f",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,160,120,30,30,hwnd,(HMENU)16,window.hInstance,NULL);
HWND gButton = CreateWindowA("Button","g",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,195,120,30,30,hwnd,(HMENU)17,window.hInstance,NULL);
HWND hButton = CreateWindowA("Button","h",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,230,120,30,30,hwnd,(HMENU)18,window.hInstance,NULL);
HWND jButton = CreateWindowA("Button","j",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,265,120,30,30,hwnd,(HMENU)19,window.hInstance,NULL);
HWND kButton = CreateWindowA("Button","k",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,300,120,30,30,hwnd,(HMENU)20,window.hInstance,NULL);
HWND lButton = CreateWindowA("Button","l",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,335,120,30,30,hwnd,(HMENU)21,window.hInstance,NULL);
HWND mButton = CreateWindowA("Button","m",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,370,120,30,30,hwnd,(HMENU)22,window.hInstance,NULL);
HWND ùButton = CreateWindowA("Button","ù",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,405,120,30,30,hwnd,(HMENU)23,window.hInstance,NULL);//fix this 
HWND starButton = CreateWindowA("Button","*",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,440,120,30,30,hwnd,(HMENU)24,window.hInstance,NULL);
//fifth row
HWND shiftButton = CreateWindowA("Button","Shift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,155,30,30,hwnd,(HMENU)52,window.hInstance,NULL);
HWND compareButton = CreateWindowA("Button","<",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50,155,30,30,hwnd,(HMENU)53,window.hInstance,NULL);
HWND wButton = CreateWindowA("Button","w",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,155,30,30,hwnd,(HMENU)54,window.hInstance,NULL);
HWND xButton = CreateWindowA("Button","x",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120,155,30,30,hwnd,(HMENU)55,window.hInstance,NULL);
HWND cButton = CreateWindowA("Button","c",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 155,155,30,30,hwnd,(HMENU)56,window.hInstance,NULL);
HWND vButton = CreateWindowA("Button","v",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 190,155,30,30,hwnd,(HMENU)57,window.hInstance,NULL);
HWND bButton = CreateWindowA("Button","b",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 225,155,30,30,hwnd,(HMENU)58,window.hInstance,NULL);
HWND nButton = CreateWindowA("Button","n",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 260,155,30,30,hwnd,(HMENU)59,window.hInstance,NULL);
HWND commaButton = CreateWindowA("Button",",",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 295,155,30,30,hwnd,(HMENU)60,window.hInstance,NULL);
HWND semicolonButton = CreateWindowA("Button",";",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 330,155,30,30,hwnd,(HMENU)61,window.hInstance,NULL);
HWND colonButton = CreateWindowA("Button",":",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 365,155,30,30,hwnd,(HMENU)62,window.hInstance,NULL);
HWND exclamationButton = CreateWindowA("Button","!",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,155,30,30,hwnd,(HMENU)63,window.hInstance,NULL);
HWND RshiftButton = CreateWindowA("Button","Shift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 435,155,70,30,hwnd,(HMENU)64,window.hInstance,NULL);
//sixth row
HWND CtrlButton = CreateWindowA("Button","Ctrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,190,45,30,hwnd,(HMENU)65,window.hInstance,NULL);
HWND WindowsButton = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 55,190,30,30,hwnd,(HMENU)66,window.hInstance,NULL);
HWND AltButton = CreateWindowA("Button","Alt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,190,30,30,hwnd,(HMENU)67,window.hInstance,NULL);
HWND SpaceButton = CreateWindowA("Button","Space",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120,190,210,30,hwnd,(HMENU)68,window.hInstance,NULL);
HWND RightAltButton = CreateWindowA("Button","R Alt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 335,190,45,30,hwnd,(HMENU)69,window.hInstance,NULL);
HWND Windows2Button = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 380,190,30,30,hwnd,(HMENU)70,window.hInstance,NULL);
HWND Ctrl2Button = CreateWindowA("Button","Ctrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 410,190,45,30,hwnd,(HMENU)71,window.hInstance,NULL);
MSG msg;

ShowWindow(hwnd,SW_SHOW);
UpdateWindow(hwnd);
while(GetMessage(&msg,NULL,0,0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}
//okay so it works now, i cant use ai anymore, i will have to add the rest of the buttons and adjust the window size to better fit