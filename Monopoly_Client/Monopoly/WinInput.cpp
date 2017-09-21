#include "WinInput.h"

WinInput::WinInput(HWND hwnd){
	memset(&KeyState, 0, sizeof(KeyState));		// 清空KeyState
	hWnd = hwnd;
};

WinInput::~WinInput(){
	hWnd = NULL;
};

bool WinInput::IsKeyDown(int vKey){
	if (GetAsyncKeyState(vKey) & 0x8000)		// 如果有按下
		return true;							// 傳是
	else										// 否則
		return false;							// 傳否
};

bool WinInput::IsKeyPress(int vKey){
	SHORT m_KeyState = GetAsyncKeyState(vKey);	// 取的按鍵狀態
	if (m_KeyState & 0x8000){					// 如果有按下
		KeyState[vKey] = m_KeyState;			// 記錄狀態
		return false;							// 傳否
	}
	else{										// 否則
		if (KeyState[vKey] & 0x8000){			// 如果之前是按下
			KeyState[vKey] = m_KeyState;		// 記錄狀態
			return true;						// 傳真
		}
		return false;
	}
};

bool WinInput::IsKeyUp(int vKey){
	if (GetAsyncKeyState(vKey) & 0x8000)		// 如果有按下
		return false;							// 傳否
	else										// 否則
		return true;							// 傳是
};

POINT WinInput::GetMousePos(){
	POINT Pos;
	GetCursorPos(&Pos);							// 取得滑鼠位置
	ScreenToClient(hWnd, &Pos);					// 轉為 Client 座標
	return Pos;
};


BOOL WinInput::SetMousePos(POINT Pos){
	ClientToScreen(hWnd, &Pos);					// 轉為 Screen 座標
	return SetCursorPos(Pos.x, Pos.y);			// 設定滑鼠位置		
};

BOOL WinInput::SetMousePos(int X, int Y){
	POINT Pos;
	Pos.x = X;
	Pos.y = Y;
	return SetMousePos(Pos);
};