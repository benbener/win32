#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	WNDCLASS	wc;
	//typedef struct tagWNDCLASSW {
	//	UINT        style;
	//	WNDPROC     lpfnWndProc;
	//	int         cbClsExtra;
	//	int         cbWndExtra;
	//	HINSTANCE   hInstance;
	//	HICON       hIcon;
	//	HCURSOR     hCursor;
	//	HBRUSH      hbrBackground;
	//	LPCWSTR     lpszMenuName;
	//	LPCWSTR     lpszClassName;
	//} WNDCLASSW, *PWNDCLASSW, NEAR *NPWNDCLASSW, FAR *LPWNDCLASSW;
	HWND		hwnd;
	MSG			msg;
	//typedef struct tagMSG {
	//	HWND        hwnd;
	//	UINT        message;
	//	WPARAM      wParam;
	//	LPARAM      lParam;
	//	DWORD       time;
	//	POINT       pt;
	//} MSG, *PMSG, NEAR *NPMSG, FAR *LPMSG;

	wc.style         = 0;							// class style
	wc.lpfnWndProc   = (WNDPROC)WndProc;			// window procedure address
	wc.cbClsExtra    = 0;							// class extra bytes
	wc.cbWndExtra    = 0;							// window extra bytes
	wc.hInstance     = hInstance;					// instance handle
	wc.hIcon         = LoadIcon(NULL,IDI_WINLOGO);	// icon handle
	wc.hCursor       = LoadCursor(NULL,IDC_ARROW);	// cursor handle
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);	// background color
	wc.lpszMenuName  = NULL;						// menu name
	wc.lpszClassName = TEXT("MyWndClass");			// wndclass name

	RegisterClass(&wc);

	// CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
			nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
	hwnd = CreateWindow(
			L"MyWndClass",			// wndclass name
			L"SDK Application",		// window title
			WS_OVERLAPPEDWINDOW,	// window style
			CW_USEDEFAULT,			// left
			CW_USEDEFAULT,			// top
			CW_USEDEFAULT,			// width
			CW_USEDEFAULT,			// height
			HWND_DESKTOP,			// parent-window handle
			NULL,					// menu handle
			hInstance,				// application handle
			NULL					// window-creation data
		);

	// ʹ���ڿɼ���ȷ��WM_PAINT��Ϣ����������̱�����
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);

	// ��Ϣѭ��
	while (GetMessage(&msg,NULL,0,0))	// ��WM_QUIT����Ϣ�����б������� GetMessage����
	{
		TranslateMessage(&msg);		// ���������Ϣת��Ϊ�ַ���Ϣ
		DispatchMessage(&msg);		// ������Ϣ�����ڹ���
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		Ellipse(hdc,0,0,200,100);
		EndPaint(hwnd,&ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd,message,wParam,lParam);
}