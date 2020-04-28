#include <Windows.h>
#include <tchar.h>
#include <conio.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // ���������� �������� ���������� 
	HINSTANCE Prev, 	// � ����������� �������� ������ 0 
	LPTSTR cmd, 		// ��������� ������ 
	int mode) 		// ����� ����������� ����
{
	HWND hWnd;		// ���������� �������� ���� ��������� 
	MSG msg; 		// ��������� ��� �������� ��������� 
	WNDCLASS wc; 	// ����� ����
	// ����������� ������ ���� 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// ��� ������ ���� 
	wc.lpfnWndProc = WndProc; 					// ������� ���� 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// ����� ���� 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// ����������� ������ 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// ����������� ������ 
	wc.lpszMenuName = NULL; 					// ��� ���� 
	wc.cbClsExtra = 0; 						// ��� �������������� ������ ������ 
	wc.cbWndExtra = 0; 						// ��� �������������� ������ ���� 
	wc.hbrBackground = CreateSolidBrush(RGB(30, 30, 122)); 	// ���������� ���� ����� ������


	// ����������� ������ ����
	if (!RegisterClass(&wc)) return 0;

	// �������� ���� 
	hWnd = CreateWindow(WinName,			// ��� ������ ���� 
		_T("������ Windows-����������"), 		// ��������� ���� 
		WS_OVERLAPPEDWINDOW, 		// ����� ���� 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 ������� ���� 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// ���������� ������������� ���� 
		NULL, 						// ��� ���� 
		This, 						// ���������� ���������� 
		NULL); 					// �������������� ���������� ��� 

	ShowWindow(hWnd, mode); 				// �������� ����

	// ���� ��������� ��������� 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// ������� ���������� ����� ������� ������� 
		DispatchMessage(&msg); 		// �������� ��������� ������� WndProc() 
	}
	return 0;
}

// ������� ������� ���������� ������������ ��������
// � �������� ��������� �� ������� ��� ������� ����������

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;

	TCHAR instructuion[] = _T("LBC to start timer, LBC to pause timer, RBC to stop timer");
	TCHAR top_clock[] = _T("12");
	TCHAR left_clock[] = _T("9");
	TCHAR right_clock[] = _T("3");
	TCHAR bottom_clock[] = _T("6");

	switch (message)		 // ���������� ���������
	{
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);

		MoveToEx(hdc, 200, 200, NULL);
		LineTo(hdc, 200, 100);

		SetTimer(hwnd,             // handle to main window 
			IDT_TIMER1,            // timer identifier 
			1000,                 // 1-second interval 
			(TIMERPROC)NULL);     // no timer callback

		ReleaseDC(hWnd, hdc);
		break;


	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Ellipse(hdc, 100, 100, 300, 300);

		TextOut(hdc, 50, 5, instructuion, _tcslen(instructuion));
		TextOut(hdc, 193, 102, top_clock, _tcslen(top_clock));
		TextOut(hdc, 290, 193, right_clock, _tcslen(right_clock));
		TextOut(hdc, 196, 282, bottom_clock, _tcslen(bottom_clock));
		TextOut(hdc, 102, 193, left_clock, _tcslen(left_clock));

		EndPaint(hWnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// ���������� ��������� 
	default: 			// ��������� ��������� �� ��������� 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
