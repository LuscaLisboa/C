#include <windows.h>

// Declaração da função de callback para a janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// C
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) 
{
    // Register the window class.
    const char CLASS_NAME[] = "Classe_Janela";

    // Inicializa a estrutura da classe da janela
    WNDCLASS wc;
    wc.style = 0;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = CLASS_NAME;

    // Register the screen class
    if (!RegisterClass(&wc)) 
    {
        return 0;
    }

    // Create the window.
    HWND hwnd = CreateWindowExA(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Window text",                  // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL) 
    {
        return 0;
    }

    // Altera o Nome da Janela
    SetWindowText(hwnd, "Altera o nome da janela");

    // Coordenadas (x, y) | Largura e Altura
    SetWindowPos(hwnd, NULL, 0, 0, 1800, 960, SWP_NOZORDER | SWP_NOACTIVATE); 

    // Não Redimensionável
    SetWindowLong(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);


    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}