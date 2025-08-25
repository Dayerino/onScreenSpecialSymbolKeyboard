#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <iostream>
#include <vector>
/*
full list https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/
using namespace std;
int incrementspace(int oldpos, int byhowmuch){
    int newpos = oldpos + byhowmuch;
    return newpos;
}
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
        case WM_SIZE://resize buttons when window gets resized
        {
            
        }
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
    WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX| WS_MINIMIZEBOX,//disabled maximize & minimize buttons 
    x,y,windowWidth,windowHeight,
    NULL,NULL,
    window.hInstance,
    NULL
);
int btnxPos, btnyPos,btnW,btnH;
btnW = windowWidth * 0.05;
btnH = windowHeight * 0.11; 
int firstRowbtnXPos, firstRowbtnYPos;
firstRowbtnXPos = windowWidth * 0.02;
firstRowbtnYPos = windowHeight *0.06;
int spacecalc = windowWidth * 0.05;
int f1spacecalc = windowWidth * 0.10;
//font size changes might be necessary for lower resolutions, but that's for later
//first row
vector<HWND>buttonsVector;
vector<HWND>specialBtnsVector;//a vector for all normal buttons and multiple vectors for different sized buttons
HWND escButton = CreateWindowA("Button","ESC",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)1,window.hInstance,NULL);
buttonsVector.push_back(escButton);
firstRowbtnXPos = firstRowbtnXPos + f1spacecalc;
HWND F1Button = CreateWindowA("Button","F1",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)2,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F2Button = CreateWindowA("Button","F2",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)3,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F3Button = CreateWindowA("Button","F3",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)4,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F4Button = CreateWindowA("Button","F4",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)5,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, f1spacecalc);
HWND F5Button = CreateWindowA("Button","F5",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)6,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F6Button = CreateWindowA("Button","F6",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)7,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F7Button = CreateWindowA("Button","F7",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)8,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F8Button = CreateWindowA("Button","F8",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)9,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, f1spacecalc);
HWND F9Button = CreateWindowA("Button","F9",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)10,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F10Button = CreateWindowA("Button","F10",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)11,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F11Button = CreateWindowA("Button","F11",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)12,window.hInstance,NULL);
firstRowbtnXPos = incrementspace(firstRowbtnXPos, spacecalc);
HWND F12Button = CreateWindowA("Button","F12",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, firstRowbtnXPos,firstRowbtnYPos,btnW,btnH,hwnd,(HMENU)13,window.hInstance,NULL);
buttonsVector.push_back(F1Button);
buttonsVector.push_back(F2Button);
buttonsVector.push_back(F3Button);
buttonsVector.push_back(F4Button);
buttonsVector.push_back(F5Button);
buttonsVector.push_back(F6Button);
buttonsVector.push_back(F7Button);
buttonsVector.push_back(F8Button);
buttonsVector.push_back(F9Button);
buttonsVector.push_back(F10Button);
buttonsVector.push_back(F11Button);
buttonsVector.push_back(F12Button);
//second row
int secondRowbtnXPos, secondRowbtnYPos,secondrowspacecalc;
secondRowbtnYPos = windowHeight * 0.18;
secondRowbtnXPos = windowWidth * 0.02; 
secondrowspacecalc = windowWidth * 0.05;
HWND subscript2Button = CreateWindowW(L"Button",L"²",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,btnW,btnH,hwnd,(HMENU)14,window.hInstance,NULL);
secondRowbtnXPos = incrementspace(secondRowbtnXPos, secondrowspacecalc); 
HWND smalloButton = CreateWindowW(L"Button",L"°",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,btnW,btnH,hwnd,(HMENU)15,window.hInstance,NULL);
secondRowbtnXPos = incrementspace(secondRowbtnXPos,secondrowspacecalc);
HWND equalsButton = CreateWindowA("Button","=",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,btnW,btnH,hwnd,(HMENU)16,window.hInstance,NULL);
secondRowbtnXPos = incrementspace(secondRowbtnXPos,secondrowspacecalc);
buttonsVector.push_back(subscript2Button);
buttonsVector.push_back(smalloButton);
buttonsVector.push_back(equalsButton);
int backspacebtnW;
backspacebtnW = windowWidth * 0.15;
HWND backspaceButton = CreateWindowA("Button","backspace",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,backspacebtnW,btnH,hwnd,(HMENU)17,window.hInstance,NULL);
for(int i = 0;i<=2;i++){
secondRowbtnXPos = incrementspace(secondRowbtnXPos,secondrowspacecalc);
}
int pgupanddown = windowWidth *0.1;
HWND PageupButton = CreateWindowA("Button","PgUp",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,pgupanddown,btnH,hwnd,(HMENU)68,window.hInstance,NULL);
for(int i = 0;i<2;i++){
secondRowbtnXPos = incrementspace(secondRowbtnXPos,secondrowspacecalc);
}
HWND PageDownButton = CreateWindowA("Button","PgDown",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, secondRowbtnXPos,secondRowbtnYPos,pgupanddown,btnH,hwnd,(HMENU)69,window.hInstance,NULL);
//third row
int thirdrowXPos,thirdrowYPos;
thirdrowYPos = windowHeight *0.3;
thirdrowXPos = windowWidth * 0.02;
HWND tabButton=CreateWindowA("Button","Tab",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)18,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND poundButton = CreateWindowW(L"BUTTON",L"£",WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)19,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND dollarButton = CreateWindowW(L"Button",L"$",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)20,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND caretButton = CreateWindowW(L"Button",L"^",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)21,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND ùButton = CreateWindowW(L"Button",L"ù",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)22,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc); 
HWND starButton = CreateWindowA("Button","*",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)23,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND ampersandButton = CreateWindowA("Button","&&",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)24,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND smallerthanButton = CreateWindowA("Button","<",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)26,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND biggerthanButton = CreateWindowA("Button",">",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)53,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND semicolonButton = CreateWindowA("Button",";",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)28,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND colonButton = CreateWindowA("Button",":",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)29,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND exclamationButton = CreateWindowW(L"Button",L"!",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)30,window.hInstance,NULL);
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND accentButton = CreateWindowW(L"Button",L"é",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,thirdrowXPos,thirdrowYPos,btnW,btnH,hwnd,(HMENU)31,window.hInstance,NULL);
buttonsVector.push_back(tabButton);
buttonsVector.push_back(poundButton);
buttonsVector.push_back(dollarButton);
buttonsVector.push_back(caretButton);
buttonsVector.push_back(ùButton);
buttonsVector.push_back(starButton);
buttonsVector.push_back(ampersandButton);
buttonsVector.push_back(smallerthanButton);
buttonsVector.push_back(biggerthanButton);
buttonsVector.push_back(semicolonButton);
buttonsVector.push_back(colonButton);
buttonsVector.push_back(exclamationButton);
buttonsVector.push_back(accentButton);
//fourth row
int fourthrowXPos,fourthrowYPos;
fourthrowXPos = windowWidth *0.02;
fourthrowYPos = windowHeight * 0.42;
int LshiftW = windowWidth * 0.1;
HWND LshiftButton = CreateWindowA("Button","LShift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, fourthrowXPos,fourthrowYPos,LshiftW,btnH,hwnd,(HMENU)32,window.hInstance,NULL);//special
for(int i = 0;i<=1;i++){
    fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
}
HWND doubleQuoteButton = CreateWindowA("Button","\"",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)33,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND singleQuoteButton = CreateWindowA("Button","\'",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)34,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND openingParenthesisButton = CreateWindowA("Button","(",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)35,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND closingParenthesisButton = CreateWindowA("Button",")",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)41,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND otheraccentButton = CreateWindowW(L"Button",L"è",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)37,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND underScoreButton = CreateWindowA("Button","_",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)38,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND çButton = CreateWindowW(L"Button",L"ç",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)39,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND àButton = CreateWindowW(L"Button",L"à",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)40,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND hyphonButton = CreateWindowA("Button","-",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,btnW,btnH,hwnd,(HMENU)36,window.hInstance,NULL);
fourthrowXPos = incrementspace(fourthrowXPos,secondrowspacecalc);
HWND RshiftButton = CreateWindowA("Button","RShift",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,fourthrowXPos,fourthrowYPos,LshiftW,btnH,hwnd,(HMENU)25,window.hInstance,NULL);//special
buttonsVector.push_back(doubleQuoteButton);
buttonsVector.push_back(singleQuoteButton);
buttonsVector.push_back(openingParenthesisButton);
buttonsVector.push_back(closingParenthesisButton);
buttonsVector.push_back(otheraccentButton);
buttonsVector.push_back(underScoreButton);
buttonsVector.push_back(çButton);
buttonsVector.push_back(àButton);
buttonsVector.push_back(hyphonButton);
//fifth
int fifthrowXPos,fifthrowYPos;
fifthrowXPos = windowWidth *0.02;
fifthrowYPos = windowHeight *0.54;
HWND plusButton = CreateWindowA("Button","+",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)42,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND tildeButton = CreateWindowA("Button","~",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)43,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND hashTagButton = CreateWindowA("Button","#",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)44,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND openingbracesButton = CreateWindowA("Button","{",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)45,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND closingBraceButton = CreateWindowA("Button","}",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)51,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND orButton = CreateWindowA("Button","|",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)47,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND backTickButton = CreateWindowA("Button","`",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)48,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND backSlashButton = CreateWindowA("Button","\\",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)49,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND forwardSlashButton = CreateWindowA("Button","/",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)50,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND openingbracketButton = CreateWindowA("Button","[",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)46,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND closingBracketButton = CreateWindowA("Button","]",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)52,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND commaButton = CreateWindowA("Button",",",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)27,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND atButton = CreateWindowA("Button","@",WS_CHILD |WS_VISIBLE |BS_PUSHBUTTON,fifthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)54,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
buttonsVector.push_back(plusButton);
buttonsVector.push_back(tildeButton);
buttonsVector.push_back(hashTagButton);
buttonsVector.push_back(openingbracesButton);
buttonsVector.push_back(closingBraceButton);
buttonsVector.push_back(orButton);
buttonsVector.push_back(backTickButton);
buttonsVector.push_back(backSlashButton);
buttonsVector.push_back(forwardSlashButton);
buttonsVector.push_back(openingbracketButton);
buttonsVector.push_back(closingBracketButton);
buttonsVector.push_back(commaButton);
buttonsVector.push_back(atButton);
//sixth
int sixthrowXPos, sixthrowYPos;
sixthrowXPos = windowWidth * 0.02;
sixthrowYPos = windowHeight * 0.66;
int ctrlbtnW = windowWidth *0.05;
int ctrlspace = windowWidth *0.1;
HWND CtrlButton = CreateWindowA("Button","Ctrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,ctrlbtnW,btnH,hwnd,(HMENU)55,window.hInstance,NULL);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND WindowsButton = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)56,window.hInstance,NULL);
buttonsVector.push_back(WindowsButton);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND AltButton = CreateWindowA("Button","Alt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)57,window.hInstance,NULL);
buttonsVector.push_back(AltButton);
int spacebtnW = windowWidth * 0.25;
HWND SpaceButton = CreateWindowA("Button","Space",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,sixthrowXPos,sixthrowYPos,spacebtnW,btnH,hwnd,(HMENU)58,window.hInstance,NULL);
sixthrowXPos = incrementspace(sixthrowXPos,spacebtnW);
HWND RightAltButton = CreateWindowA("Button","RAlt",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)59,window.hInstance,NULL);
buttonsVector.push_back(RightAltButton);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND Windows2Button = CreateWindowA("Button","Win",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)60,window.hInstance,NULL);
buttonsVector.push_back(Windows2Button);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND RCtrlButton = CreateWindowA("Button","RCtrl",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,ctrlbtnW,btnH,hwnd,(HMENU)61,window.hInstance,NULL);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND DeleteButton = CreateWindowA("Button","Del",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)67,window.hInstance,NULL);
buttonsVector.push_back(DeleteButton);
//page up & down btns could go next to backspace, add delete to sixth row
//arrows keys
for(int i = 0;i<3;i++){
    sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
}
HWND leftButton = CreateWindowW(L"Button",L"←",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)63,window.hInstance,NULL);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND downButton = CreateWindowW(L"Button",L"↓",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)64,window.hInstance,NULL);
fifthrowXPos = incrementspace(fifthrowXPos,secondrowspacecalc);
HWND upButton = CreateWindowW(L"Button",L"↑",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,sixthrowXPos,fifthrowYPos,btnW,btnH,hwnd,(HMENU)62,window.hInstance,NULL);
sixthrowXPos = incrementspace(sixthrowXPos,secondrowspacecalc);
HWND rightButton = CreateWindowW(L"Button",L"→",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, sixthrowXPos,sixthrowYPos,btnW,btnH,hwnd,(HMENU)65,window.hInstance,NULL);
buttonsVector.push_back(leftButton);
buttonsVector.push_back(downButton);
buttonsVector.push_back(upButton);
buttonsVector.push_back(rightButton);
/*delete, enter(return) fin?, pageup/down, numpad to switch between numbers & special chars(i guess shift btn can do that)*/
int returnkeyW,returnkeyH;
returnkeyW = windowWidth * 0.1;
returnkeyH = windowHeight *0.23;
thirdrowXPos = incrementspace(thirdrowXPos,secondrowspacecalc);
HWND EnterButton = CreateWindowA("Button","Enter",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, thirdrowXPos,thirdrowYPos,returnkeyW,returnkeyH,hwnd,(HMENU)66,window.hInstance,NULL);
/*HWND PageupButton = CreateWindowA("Button","PgUp",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 560,85,60,30,hwnd,(HMENU)68,window.hInstance,NULL);
HWND PageDownButton = CreateWindowA("Button","PgDown",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 560,120,60,30,hwnd,(HMENU)69,window.hInstance,NULL);*/
MSG msg;
ShowWindow(hwnd,SW_SHOW);
UpdateWindow(hwnd);
while(GetMessage(&msg,NULL,0,0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}
//okay so it works now, i cant use ai anymore, i will have to add the rest of the buttons and adjust the window size to better fit