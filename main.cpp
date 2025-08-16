#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <iostream>
/*
full list https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/
using namespace std;
//main function used to send key inputs using their virtual key codes
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
//main function used to send key inputs using their unicode
void unicodeInput(int keyHexVal){
    INPUT ip  = {};
    ip.type = INPUT_KEYBOARD;//specifies that the input is a keyboard event
                ip.ki.wScan = keyHexVal;//sets the unicode character to send
                ip.ki.wVk = 0;//sets virtual key code to 0, this is required because we're sending a character
                ip.ki.dwFlags = KEYEVENTF_UNICODE;//tells windows we're sending a unicode char not a normal key,
                //                                (unicode is just a software level symbol(text output) while a key is a hardware-ish event(button up/down))
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam){
    switch(message){
        case WM_COMMAND://checks for a button click
            if(LOWORD(wParam) == 1){BTNINPUT(0x1B);}//esc
            if(LOWORD(wParam) == 2){BTNINPUT(0x70);}//f1
            if(LOWORD(wParam) == 3){BTNINPUT(0x71);}//f2
            if(LOWORD(wParam) == 4){BTNINPUT(0x72);}//f3
            if(LOWORD(wParam) == 5){BTNINPUT(0x73);}//f4
            if(LOWORD(wParam) == 6){BTNINPUT(0x74);}//f5
            if(LOWORD(wParam) == 7){BTNINPUT(0x75);}//f6
            if(LOWORD(wParam) == 8){BTNINPUT(0x76);}//f7
            if(LOWORD(wParam) == 9){BTNINPUT(0x77);}//f8
            if(LOWORD(wParam) == 10){BTNINPUT(0x78);}//f9
            if(LOWORD(wParam) == 11){BTNINPUT(0x79);}//f10
            if(LOWORD(wParam) == 12){BTNINPUT(0x7A);}//f11
            if(LOWORD(wParam) == 13){BTNINPUT(0x7B);}//f12
            if(LOWORD(wParam) == 14){unicodeInput(0x00B2);}//²
            if(LOWORD(wParam) == 15){unicodeInput(0x00B0);}//°
            if(LOWORD(wParam) == 16){
                keybd_event(VK_OEM_PLUS,0,0,0);
                keybd_event(VK_OEM_PLUS,0,KEYEVENTF_KEYUP,0);
            }//=
            if(LOWORD(wParam) == 17){BTNINPUT(0x08);}//backspace
            if(LOWORD(wParam) == 18){BTNINPUT(0x09);}//tab
            if(LOWORD(wParam) == 19){unicodeInput(0x00A3);}//£
            
            if(LOWORD(wParam) == 20){unicodeInput(0x0024);}//$
            if(LOWORD(wParam) == 21){unicodeInput(0x005E);}//^
            if(LOWORD(wParam) == 22){unicodeInput(0x00F9);}//ù
            if(LOWORD(wParam) == 23){unicodeInput(0x002A);}//*
            if(LOWORD(wParam) == 24){unicodeInput(0x0026);}//&
            if(LOWORD(wParam) == 25){BTNINPUT(0xA0);}//leftshift
            if(LOWORD(wParam) == 26){unicodeInput(0x003C);}//< DONT FORGET TO ADD >
            if(LOWORD(wParam) == 27){unicodeInput(0x002C);}//,
            if(LOWORD(wParam) == 28){unicodeInput(0x003B);}//;
            if(LOWORD(wParam) == 29){unicodeInput(0x003A);}//:
            if(LOWORD(wParam) == 30){unicodeInput(0x0021);}//!
            if(LOWORD(wParam) == 31){unicodeInput(0x00E9);}//é
            if(LOWORD(wParam) == 32){BTNINPUT(0xA1);}//rshift
            if(LOWORD(wParam) == 33){unicodeInput(0x0022);}//""
            if(LOWORD(wParam) == 34){unicodeInput(0x0027);}//'
            if(LOWORD(wParam) == 35){unicodeInput(0x0028);}//(
            if(LOWORD(wParam) == 36){unicodeInput(0x002D);}//-
            if(LOWORD(wParam) == 37){unicodeInput(0x00E8);}//è
            if(LOWORD(wParam) == 38){unicodeInput(0x005F);}//_
            if(LOWORD(wParam) == 39){unicodeInput(0x00E7);}//ç
            if(LOWORD(wParam) == 40){unicodeInput(0x00E0);}//à
            if(LOWORD(wParam) == 41){unicodeInput(0x0029);}//)
            if(LOWORD(wParam) == 42){unicodeInput(0x002B);}//+
            if(LOWORD(wParam) == 43){unicodeInput(0x007E);}//~
            if(LOWORD(wParam) == 44){unicodeInput(0x0023);}//#
            if(LOWORD(wParam) == 45){unicodeInput(0x007B);}//{
            if(LOWORD(wParam) == 46){unicodeInput(0x005B);}//[
            if(LOWORD(wParam) == 47){unicodeInput(0x007C);}//|
            if(LOWORD(wParam) == 48){unicodeInput(0x0060);}//`
            if(LOWORD(wParam) == 49){unicodeInput(0x005C);}//backslash
            if(LOWORD(wParam) == 50){unicodeInput(0x002F);}//forwardslash
            if(LOWORD(wParam) == 51){unicodeInput(0x007D);}//}
            if(LOWORD(wParam) == 52){unicodeInput(0x005D);}//]
            if(LOWORD(wParam) == 53){unicodeInput(0x003E);}//>
            if(LOWORD(wParam) == 54){unicodeInput(0x0040);}//@
            if(LOWORD(wParam) == 55){BTNINPUT(0xA2);}//ctrl
            if(LOWORD(wParam) == 56){BTNINPUT(0x5B);}//windows
            if(LOWORD(wParam) == 57){BTNINPUT(0xA4);}//alt
            if(LOWORD(wParam) == 58){BTNINPUT(0x20);}//space
            if(LOWORD(wParam) == 59){BTNINPUT(0xA5);}//ralt
            if(LOWORD(wParam) == 60){BTNINPUT(0x5C);}//rwin
            if(LOWORD(wParam) == 61){BTNINPUT(0xA3);}//rctrl
            if(LOWORD(wParam) == 62){BTNINPUT(0x26);}//up
            if(LOWORD(wParam) == 63){BTNINPUT(0x25);}//left
            if(LOWORD(wParam) == 64){BTNINPUT(0x28);}//down
            if(LOWORD(wParam) == 65){BTNINPUT(0x27);}//right
            if(LOWORD(wParam) == 66){BTNINPUT(0x0D);}//enter
            if(LOWORD(wParam) == 67){BTNINPUT(0x2E);}//delete
            if(LOWORD(wParam) == 68){BTNINPUT(0x21);}//pageup
            if(LOWORD(wParam) == 69){BTNINPUT(0x22);}//pagedown
            

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

WNDCLASS window= {};
window.style = CS_DBLCLKS | CS_PARENTDC;
window.lpfnWndProc = WndProc;
window.cbClsExtra = 0;
window.cbWndExtra = 0;
window.hInstance = GetModuleHandle(NULL);
window.hIcon = NULL;
window.hCursor = LoadCursor(NULL,IDC_IBEAM);
window.hbrBackground = NULL;
window.lpszMenuName= NULL;
window.lpszClassName = TEXT("MainWindow");
window.hbrBackground = (HBRUSH)(COLOR_WINDOW +1);
RegisterClass(&window);
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int windowWidth = screenWidth * 0.34;
int windowHeight = screenHeight * 0.25;
int x = (screenWidth - windowWidth) / 2;
int y = (screenHeight - windowHeight) / 2;
HWND hwnd = CreateWindowEx(
    WS_EX_TOPMOST | WS_EX_APPWINDOW,
    TEXT("mainWindow"),
    TEXT(
    "Specials Keyboard"),
    WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX | WS_MINIMIZEBOX,//disabled maximize & minimize buttons 
    x,y,windowWidth,windowHeight,
    NULL,NULL,
    window.hInstance,
    NULL
);
/*HWND poundButton = CreateWindowW(
    L"BUTTON",//button class
    L"£",//Button label
    WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,//styles: child of window, visible,pushbutton
    50,85,//x y position inside window
    30,30,//width & height
    hwnd,
    (HMENU)19, //control ID(used later to identify the button)
    window.hInstance,
NULL
);*/
//createwindowA is for normal letters, createWindowW is for special chars
/*need to set up button sizes to match different resolutions*/
int btnxPos, btnyPos,btnW,btnH;
//first row
HWND escButton = CreateWindowA("Button","ESC",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,15,30,30,hwnd,(HMENU)1,window.hInstance,NULL);
HWND F1Button = CreateWindowA("Button","F1",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,15,30,30,hwnd,(HMENU)2,window.hInstance,NULL);
HWND F2Button = CreateWindowA("Button","F2",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 115,15,30,30,hwnd,(HMENU)3,window.hInstance,NULL);
HWND F3Button = CreateWindowA("Button","F3",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 145,15,30,30,hwnd,(HMENU)4,window.hInstance,NULL);
HWND F4Button = CreateWindowA("Button","F4",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 175,15,30,30,hwnd,(HMENU)5,window.hInstance,NULL);
HWND F5Button = CreateWindowA("Button","F5",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 225,15,30,30,hwnd,(HMENU)6,window.hInstance,NULL);
HWND F6Button = CreateWindowA("Button","F6",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 255,15,30,30,hwnd,(HMENU)7,window.hInstance,NULL);
HWND F7Button = CreateWindowA("Button","F7",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 285,15,30,30,hwnd,(HMENU)8,window.hInstance,NULL);
HWND F8Button = CreateWindowA("Button","F8",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 315,15,30,30,hwnd,(HMENU)9,window.hInstance,NULL);
HWND F9Button = CreateWindowA("Button","F9",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 365,15,30,30,hwnd,(HMENU)10,window.hInstance,NULL);
HWND F10Button = CreateWindowA("Button","F10",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 395,15,30,30,hwnd,(HMENU)11,window.hInstance,NULL);
HWND F11Button = CreateWindowA("Button","F11",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 425,15,30,30,hwnd,(HMENU)12,window.hInstance,NULL);
HWND F12Button = CreateWindowA("Button","F12",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 455,15,30,30,hwnd,(HMENU)13,window.hInstance,NULL);
//second row
HWND subscript2Button = CreateWindowW(L"Button",L"²",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,50,30,30,hwnd,(HMENU)14,window.hInstance,NULL);
HWND smalloButton = CreateWindowW(L"Button",L"°",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,50,30,30,hwnd,(HMENU)15,window.hInstance,NULL);
HWND equalsButton = CreateWindowA("Button","=",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 435,50,30,30,hwnd,(HMENU)16,window.hInstance,NULL);
HWND backspaceButton = CreateWindowA("Button","backspace",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 470,50,90,30,hwnd,(HMENU)17,window.hInstance,NULL);
//third row
HWND tabButton=CreateWindowA("Button","Tab",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,85,30,30,hwnd,(HMENU)18,window.hInstance,NULL);
HWND poundButton = CreateWindowW(L"BUTTON",L"£",WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,50,85,30,30,hwnd,(HMENU)19,window.hInstance,NULL);
HWND dollarButton = CreateWindowW(L"Button",L"$",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,85,85,30,30,hwnd,(HMENU)20,window.hInstance,NULL);
HWND caretButton = CreateWindowW(L"Button",L"^",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,120,85,30,30,hwnd,(HMENU)21,window.hInstance,NULL);
HWND ùButton = CreateWindowW(L"Button",L"ù",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,155,85,30,30,hwnd,(HMENU)22,window.hInstance,NULL); 
HWND starButton = CreateWindowA("Button","*",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,190,85,30,30,hwnd,(HMENU)23,window.hInstance,NULL);
HWND ampersandButton = CreateWindowA("Button","&&",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,225,85,30,30,hwnd,(HMENU)24,window.hInstance,NULL);
HWND smallerthanButton = CreateWindowA("Button","<",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 260,85,30,30,hwnd,(HMENU)26,window.hInstance,NULL);
HWND biggerthanButton = CreateWindowA("Button",">",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,295,85,30,30,hwnd,(HMENU)53,window.hInstance,NULL);
HWND semicolonButton = CreateWindowA("Button",";",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 330,85,30,30,hwnd,(HMENU)28,window.hInstance,NULL);
HWND colonButton = CreateWindowA("Button",":",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 365,85,30,30,hwnd,(HMENU)29,window.hInstance,NULL);
HWND exclamationButton = CreateWindowW(L"Button",L"!",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,85,30,30,hwnd,(HMENU)30,window.hInstance,NULL);
HWND accentButton = CreateWindowW(L"Button",L"é",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,435,85,30,30,hwnd,(HMENU)31,window.hInstance,NULL);
//fourth row
HWND LshiftButton = CreateWindowA("Button","LShift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,120,65,30,hwnd,(HMENU)32,window.hInstance,NULL);
HWND doubleQuoteButton = CreateWindowA("Button","\"",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,85,120,30,30,hwnd,(HMENU)33,window.hInstance,NULL);
HWND singleQuoteButton = CreateWindowA("Button","\'",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,120,120,30,30,hwnd,(HMENU)34,window.hInstance,NULL);
HWND openingParenthesisButton = CreateWindowA("Button","(",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,155,120,30,30,hwnd,(HMENU)35,window.hInstance,NULL);
HWND closingParenthesisButton = CreateWindowA("Button",")",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,190,120,30,30,hwnd,(HMENU)41,window.hInstance,NULL);
HWND otheraccentButton = CreateWindowW(L"Button",L"è",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,225,120,30,30,hwnd,(HMENU)37,window.hInstance,NULL);
HWND underScoreButton = CreateWindowA("Button","_",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,260,120,30,30,hwnd,(HMENU)38,window.hInstance,NULL);
HWND çButton = CreateWindowW(L"Button",L"ç",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,295,120,30,30,hwnd,(HMENU)39,window.hInstance,NULL);
HWND àButton = CreateWindowW(L"Button",L"à",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,330,120,30,30,hwnd,(HMENU)40,window.hInstance,NULL);
HWND hyphonButton = CreateWindowA("Button","-",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,365,120,30,30,hwnd,(HMENU)36,window.hInstance,NULL);
HWND RshiftButton = CreateWindowA("Button","RShift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,120,65,30,hwnd,(HMENU)25,window.hInstance,NULL);
//fifth
HWND plusButton = CreateWindowA("Button","+",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,15,155,30,30,hwnd,(HMENU)42,window.hInstance,NULL);
HWND tildeButton = CreateWindowA("Button","~",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,50,155,30,30,hwnd,(HMENU)43,window.hInstance,NULL);
HWND hashTagButton = CreateWindowA("Button","#",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,85,155,30,30,hwnd,(HMENU)44,window.hInstance,NULL);
HWND openingbracesButton = CreateWindowA("Button","{",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,120,155,30,30,hwnd,(HMENU)45,window.hInstance,NULL);
HWND closingBraceButton = CreateWindowA("Button","}",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,155,155,30,30,hwnd,(HMENU)51,window.hInstance,NULL);
HWND orButton = CreateWindowA("Button","|",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,190,155,30,30,hwnd,(HMENU)47,window.hInstance,NULL);
HWND backTickButton = CreateWindowA("Button","`",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,225,155,30,30,hwnd,(HMENU)48,window.hInstance,NULL);
HWND backSlashButton = CreateWindowA("Button","\\",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,260,155,30,30,hwnd,(HMENU)49,window.hInstance,NULL);
HWND forwardSlashButton = CreateWindowA("Button","/",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,295,155,30,30,hwnd,(HMENU)50,window.hInstance,NULL);
HWND openingbracketButton = CreateWindowA("Button","[",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,330,155,30,30,hwnd,(HMENU)46,window.hInstance,NULL);
HWND closingBracketButton = CreateWindowA("Button","]",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,365,155,30,30,hwnd,(HMENU)52,window.hInstance,NULL);
HWND commaButton = CreateWindowA("Button",",",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400,155,30,30,hwnd,(HMENU)27,window.hInstance,NULL);
HWND atButton = CreateWindowA("Button","@",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,435,155,30,30,hwnd,(HMENU)54,window.hInstance,NULL);
//sixth
HWND CtrlButton = CreateWindowA("Button","Ctrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 15,190,45,30,hwnd,(HMENU)55,window.hInstance,NULL);
HWND WindowsButton = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 55,190,30,30,hwnd,(HMENU)56,window.hInstance,NULL);
HWND AltButton = CreateWindowA("Button","Alt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 85,190,30,30,hwnd,(HMENU)57,window.hInstance,NULL);
HWND SpaceButton = CreateWindowA("Button","Space",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 120,190,210,30,hwnd,(HMENU)58,window.hInstance,NULL);
HWND RightAltButton = CreateWindowA("Button","R Alt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 335,190,45,30,hwnd,(HMENU)59,window.hInstance,NULL);
HWND Windows2Button = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 380,190,30,30,hwnd,(HMENU)60,window.hInstance,NULL);
HWND RCtrlButton = CreateWindowA("Button","RCtrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 410,190,45,30,hwnd,(HMENU)61,window.hInstance,NULL);
//arrows keys
HWND upButton = CreateWindowW(L"Button",L"↑",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,540,155,40,30,hwnd,(HMENU)62,window.hInstance,NULL);
HWND leftButton = CreateWindowW(L"Button",L"←",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 505,190,40,30,hwnd,(HMENU)63,window.hInstance,NULL);
HWND downButton = CreateWindowW(L"Button",L"↓",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 540,190,40,30,hwnd,(HMENU)64,window.hInstance,NULL);
HWND rightButton = CreateWindowW(L"Button",L"→",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 580,190,40,30,hwnd,(HMENU)65,window.hInstance,NULL);
/*delete, enter(return) fin?, pageup/down, numpad to switch between numbers & special chars(i guess shift btn can do that)*/
HWND EnterButton = CreateWindowA("Button","Enter",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 470,80,90,70,hwnd,(HMENU)66,window.hInstance,NULL);
HWND DeleteButton = CreateWindowA("Button","Del",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 455,190,45,30,hwnd,(HMENU)67,window.hInstance,NULL);
HWND PageupButton = CreateWindowA("Button","PgUp",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 560,85,60,30,hwnd,(HMENU)68,window.hInstance,NULL);
HWND PageDownButton = CreateWindowA("Button","PgDown",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 560,120,60,30,hwnd,(HMENU)69,window.hInstance,NULL);
MSG msg;
ShowWindow(hwnd,SW_SHOW);
UpdateWindow(hwnd);
while(GetMessage(&msg,NULL,0,0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}
//okay so it works now, i cant use ai anymore, i will have to add the rest of the buttons and adjust the window size to better fit