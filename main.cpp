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
            if(LOWORD(wParam) == 14){
                INPUT ip = {};//initializes an input struct
                ip.type = INPUT_KEYBOARD;//specifies that the input is a keyboard event
                ip.ki.wScan = 0x00B2;//sets the unicode character to send
                ip.ki.wVk = 0;//sets virtual key code to 0, this is required because we're sending a character
                ip.ki.dwFlags = KEYEVENTF_UNICODE;//tells windows we're sending a unicode char not a normal key,
                //                                (unicode is just a software level symbol(text output) while a key is a hardware-ish event(button up/down))
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));//sends input, 1 is the number of events being sent, &ip is a pointer to the input structure
                //                             sizeof(input) tells windows how big the structure is
            }//²
            if(LOWORD(wParam) == 15){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00B0;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//°
            if(LOWORD(wParam) == 16){
                keybd_event(VK_OEM_PLUS,0,0,0);
                keybd_event(VK_OEM_PLUS,0,KEYEVENTF_KEYUP,0);
            }//=
            if(LOWORD(wParam) == 17){BTNINPUT(0x08);}//backspace
            if(LOWORD(wParam) == 18){BTNINPUT(0x09);}//tab
            if(LOWORD(wParam) == 19){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00A3;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//£
            /*
$    0x0024
^    0x005E
ù    0x00F9
*    0x002A
&    0x0026
<    0x003C
>    0x003E
,    0x002C
;    0x003B
:    0x003A
!    0x0021
é    0x00E9
"    0x0022
'    0x0027
(    0x0028
è    0x00E8
_    0x005F
ç    0x00E7
à    0x00E0
)    0x0029
+    0x002B
~    0x007E
#    0x0023
{    0x007B
[    0x005B
|    0x007C
`    0x0060
\    0x005C  ← backslash
/    0x002F  ← forward slash
}    0x007D
]    0x005D
@    0x0040*/
            if(LOWORD(wParam) == 20){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0024;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//$
            if(LOWORD(wParam) == 21){INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x005E;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//^
            if(LOWORD(wParam) == 22){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00F9;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//ù
            if(LOWORD(wParam) == 23){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x002A;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//*
            if(LOWORD(wParam) == 24){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0026;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//&
            if(LOWORD(wParam) == 25){BTNINPUT(0xA0);}//leftshift
            if(LOWORD(wParam) == 26){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x003C;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//< DONT FORGET TO ADD >
            if(LOWORD(wParam) == 27){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x002C;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//,
            if(LOWORD(wParam) == 28){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x003B;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//;
            if(LOWORD(wParam) == 29){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x003A;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//:
            if(LOWORD(wParam) == 30){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0021;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//!
            if(LOWORD(wParam) == 31){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00E9;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//é
            if(LOWORD(wParam) == 32){BTNINPUT(0xA1);}//rshift
            if(LOWORD(wParam) == 33){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0022;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//""
            if(LOWORD(wParam) == 34){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0027;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//'
            if(LOWORD(wParam) == 35){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0028;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//(
            if(LOWORD(wParam) == 36){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x002D;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//-
            if(LOWORD(wParam) == 37){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00E8;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//è
            if(LOWORD(wParam) == 38){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x005F;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//_
            if(LOWORD(wParam) == 39){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00E7;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//ç
            if(LOWORD(wParam) == 40){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x00E0;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//à
            if(LOWORD(wParam) == 41){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0029;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//)
            if(LOWORD(wParam) == 42){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x002B;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//+
            if(LOWORD(wParam) == 43){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x007E;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//~
            if(LOWORD(wParam) == 44){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0023;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//#
            if(LOWORD(wParam) == 45){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x007B;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//{
            if(LOWORD(wParam) == 46){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x005B;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//[
            if(LOWORD(wParam) == 47){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x007C;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//|
            if(LOWORD(wParam) == 48){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0060;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//`
            if(LOWORD(wParam) == 49){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x005C;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//backslash
            if(LOWORD(wParam) == 50){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x002F;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//forwardslash
            if(LOWORD(wParam) == 51){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x007D;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//}
            if(LOWORD(wParam) == 52){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x005D;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//]
            if(LOWORD(wParam) == 53){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x003E;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//>
            if(LOWORD(wParam) == 54){
                INPUT ip = {};
                ip.type = INPUT_KEYBOARD;
                ip.ki.wScan = 0x0040;
                ip.ki.wVk = 0;
                ip.ki.dwFlags = KEYEVENTF_UNICODE;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = GetMessageExtraInfo();
                SendInput(1,&ip,sizeof(INPUT));
            }//@
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
    WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,//disabled maximize & minimize buttons 
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