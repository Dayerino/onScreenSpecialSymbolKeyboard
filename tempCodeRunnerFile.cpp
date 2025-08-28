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