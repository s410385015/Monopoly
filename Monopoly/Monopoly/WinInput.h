#ifndef _SECTION_WININPUT_	// 避免重複include
#define _SECTION_WININPUT_

/*

WinInput 1.0

p.s 按鍵值請對應VK
MSDN : http://msdn.microsoft.com/en-us/library/dd375731(v=vs.85).aspx

GetAsyncKeyState
MSDN : http://msdn.microsoft.com/en-us/library/ms646293(v=VS.85).aspx

*/

#include <windows.h>
#include <stdio.h>

class WinInput{
private:
	SHORT KeyState[256];				// 暫存按鍵狀態用
	HWND hWnd;
public:
	WinInput(HWND hwnd);
	~WinInput();

	bool	IsKeyDown(int vKey);		// 按鍵是否為按下狀態
	bool	IsKeyUp(int vKey);			// 按鍵是否為放開狀態
	bool	IsKeyPress(int vKey);		// 是否按下並放開按鍵
	POINT	GetMousePos();				// 取得滑鼠位置 (Clinet座標)
	BOOL	SetMousePos(POINT Pos);		// 設定滑鼠位置 (Clinet座標)
	BOOL	SetMousePos(int X, int Y);	// 設定滑鼠位置 (Clinet座標)
};

#endif