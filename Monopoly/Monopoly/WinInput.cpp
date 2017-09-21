#include "WinInput.h"

WinInput::WinInput(HWND hwnd){
	memset(&KeyState, 0, sizeof(KeyState));		// �M��KeyState
	hWnd = hwnd;
};

WinInput::~WinInput(){
	hWnd = NULL;
};

bool WinInput::IsKeyDown(int vKey){
	if (GetAsyncKeyState(vKey) & 0x8000)		// �p�G�����U
		return true;							// �ǬO
	else										// �_�h
		return false;							// �ǧ_
};

bool WinInput::IsKeyPress(int vKey){
	SHORT m_KeyState = GetAsyncKeyState(vKey);	// �������䪬�A
	if (m_KeyState & 0x8000){					// �p�G�����U
		KeyState[vKey] = m_KeyState;			// �O�����A
		return false;							// �ǧ_
	}
	else{										// �_�h
		if (KeyState[vKey] & 0x8000){			// �p�G���e�O���U
			KeyState[vKey] = m_KeyState;		// �O�����A
			return true;						// �ǯu
		}
		return false;
	}
};

bool WinInput::IsKeyUp(int vKey){
	if (GetAsyncKeyState(vKey) & 0x8000)		// �p�G�����U
		return false;							// �ǧ_
	else										// �_�h
		return true;							// �ǬO
};

POINT WinInput::GetMousePos(){
	POINT Pos;
	GetCursorPos(&Pos);							// ���o�ƹ���m
	ScreenToClient(hWnd, &Pos);					// �ର Client �y��
	return Pos;
};


BOOL WinInput::SetMousePos(POINT Pos){
	ClientToScreen(hWnd, &Pos);					// �ର Screen �y��
	return SetCursorPos(Pos.x, Pos.y);			// �]�w�ƹ���m		
};

BOOL WinInput::SetMousePos(int X, int Y){
	POINT Pos;
	Pos.x = X;
	Pos.y = Y;
	return SetMousePos(Pos);
};