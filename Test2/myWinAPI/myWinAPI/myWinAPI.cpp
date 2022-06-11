// myWinAPI.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "myWinAPI.h"
#include <math.h>



#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MYWINAPI, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYWINAPI));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYWINAPI));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MYWINAPI);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	int cx, cy;
	float x = 250, y = 100, x1, y1, angle;     //旋转坐标点
	float x0 = -600;
	float xcenter = 400, ycenter = 0;   //旋转中心
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH Brush, oldhbrush;
	HPEN hPen;
	RECT rect;

	POINT pts0[5] = { {-800, 0},{-800, 400},{-400, 400},{-400, 0},{-800, 0} };
	BYTE bts0[5] = { PT_MOVETO,PT_LINETO,PT_LINETO,PT_LINETO,PT_LINETO };
	POINT pts20[3] = { {-800, 0},{-600, 100},{-400, 0} };
	POINT pts30[3] = { {-400, 400},{-600, 100},{-400, 0} };

	POINT pts1[5] = { {0, 0},{0, 400},{400, 400},{400, 0},{0, 0} };
	BYTE bts1[5] = { PT_MOVETO,PT_LINETO,PT_LINETO,PT_LINETO,PT_LINETO };

	POINT pts2[3] = { {0, 0},{250, 100},{400, 0} };
	POINT pts3[3] = { {400, 400},{250, 100},{400, 0} };

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
		GetClientRect(hWnd, &rect);            //获得窗口长、宽                
		cx = rect.right - rect.left;
		cy = rect.bottom - rect.top;

		SetMapMode(hdc, MM_ISOTROPIC);          //将坐标系原点设置到窗口中心               
		SetWindowExtEx(hdc, 1000, 1000, NULL);
		SetViewportExtEx(hdc, cx, -cy, NULL);
		SetViewportOrgEx(hdc, cx / 2, cy / 2, NULL);

		SetBkMode(hdc, TRANSPARENT);            //给正方形标注
		TextOutW(hdc, -820, 0, _T("A"), 1);
		TextOutW(hdc, -420, 0, _T("B"), 1);
		TextOutW(hdc, -820, 420, _T("C"), 1);
		TextOutW(hdc, -430, 430, _T("D"), 1);
		TextOutW(hdc, -630, 130, _T("P"), 1);
		TextOutW(hdc, -630, -20, _T("(A) origin"), 10);

		PolyDraw(hdc, pts0, bts0, 5);      //绘制正方形
		Polygon(hdc, pts20, 3);//绘制三角形
		MoveToEx(hdc, -600, 100, NULL);  //画一条直线
		LineTo(hdc, -400, 400);
		angle = -3.14 / 2;            //
		x1 = (x0 +xcenter) * cos(angle) - (y - ycenter) * sin(angle) -xcenter;
		y1 = (x0 + xcenter) * sin(angle) + (y - ycenter) * cos(angle) + ycenter;
		pts30[1].x = x1;
		pts30[1].y = y1;
		Polygon(hdc, pts30, 3);//绘制三角形
		hPen = CreatePen(PS_DASH, 3, RGB(0, 0, 0));//创建虚线画笔
		oldhbrush = (HBRUSH)SelectObject(hdc, hPen);
		MoveToEx(hdc, -600, 100, NULL);  //画一条直线
		LineTo(hdc, x1, y1);
		SelectObject(hdc, oldhbrush);
		
		TextOutW(hdc, x1 + 20, y1, _T("P'"), 2);


		SetBkMode(hdc, TRANSPARENT);            //给正方形标注
		TextOutW(hdc, -20, 0, _T("A"), 1);
		TextOutW(hdc, 420, 0, _T("B"), 1);
		TextOutW(hdc, 420, 420, _T("C"), 1);
		TextOutW(hdc, -30, 420, _T("D"), 1);
		TextOutW(hdc, 230, 130, _T("P"), 1);
		TextOutW(hdc, 200, -20, _T("(B) after whirl"), 15);

		PolyDraw(hdc, pts1, bts1, 5);      //绘制正方形

		SetPolyFillMode(hdc, ALTERNATE);//设置填充模式
		Brush = CreateSolidBrush(RGB(255, 105, 180)); //品红色实心画刷
		oldhbrush = (HBRUSH)SelectObject(hdc, Brush);
		Polygon(hdc, pts2, 3);//绘制三角形
		SelectObject(hdc, oldhbrush);
		DeleteObject(Brush);

		MoveToEx(hdc, 250, 100, NULL);  //画一条直线
		LineTo(hdc, 400, 400);

		angle = -3.14 / 2;            //
		x1 = (x - xcenter) * cos(angle) - (y - ycenter) * sin(angle) + xcenter;
		y1 = (x - xcenter) * sin(angle) + (y - ycenter) * cos(angle) + ycenter;
		pts3[1].x = x1;
		pts3[1].y = y1;
		SetPolyFillMode(hdc, ALTERNATE);//设置填充模式
		Brush = CreateSolidBrush(RGB(255, 105, 180)); //品红色实心画刷
		oldhbrush = (HBRUSH)SelectObject(hdc, Brush);
		Polygon(hdc, pts3, 3);//绘制三角形
		SelectObject(hdc, oldhbrush);
		DeleteObject(Brush);

		hPen = CreatePen(PS_DASH, 3, RGB(0, 0, 0));//创建虚线画笔
		oldhbrush = (HBRUSH)SelectObject(hdc, hPen);
		MoveToEx(hdc, 250, 100, NULL);  //画一条直线
		LineTo(hdc, x1, y1);
		SelectObject(hdc, oldhbrush);
		DeleteObject(Brush);
		TextOutW(hdc, x1 + 20, y1, _T("P'"), 2);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
