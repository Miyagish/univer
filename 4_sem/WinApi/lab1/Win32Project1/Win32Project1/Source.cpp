#include <Windows.h>
#include <tchar.h>
#include <conio.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = CreateSolidBrush(RGB(30, 30, 122)); 	// Заполнение окна белым цветом


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Каркас Windows-приложения"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		CW_USEDEFAULT, 				// width 
		CW_USEDEFAULT, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;

	TCHAR instructuion[] = _T("LBC to start timer, LBC to pause timer, RBC to stop timer");
	TCHAR top_clock[] = _T("12");
	TCHAR left_clock[] = _T("9");
	TCHAR right_clock[] = _T("3");
	TCHAR bottom_clock[] = _T("6");

	switch (message)		 // Обработчик сообщений
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
		break; 			// Завершение программы 
	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
