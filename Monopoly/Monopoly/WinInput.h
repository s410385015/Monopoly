#ifndef _SECTION_WININPUT_	// �קK����include
#define _SECTION_WININPUT_

/*

WinInput 1.0

p.s ����Ƚй���VK
MSDN : http://msdn.microsoft.com/en-us/library/dd375731(v=vs.85).aspx

GetAsyncKeyState
MSDN : http://msdn.microsoft.com/en-us/library/ms646293(v=VS.85).aspx

*/

#include <windows.h>
#include <stdio.h>

class WinInput{
private:
	SHORT KeyState[256];				// �Ȧs���䪬�A��
	HWND hWnd;
public:
	WinInput(HWND hwnd);
	~WinInput();

	bool	IsKeyDown(int vKey);		// ����O�_�����U���A
	bool	IsKeyUp(int vKey);			// ����O�_����}���A
	bool	IsKeyPress(int vKey);		// �O�_���U�é�}����
	POINT	GetMousePos();				// ���o�ƹ���m (Clinet�y��)
	BOOL	SetMousePos(POINT Pos);		// �]�w�ƹ���m (Clinet�y��)
	BOOL	SetMousePos(int X, int Y);	// �]�w�ƹ���m (Clinet�y��)
};

#endif