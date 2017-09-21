#include<windows.h>
#include"Draw.cpp"

class ControlSet
{
	public:
		ControlSet()
		{ 
			hWnd = GetConsoleWindow(); 
			SetDie();
			SetYesNo();
			SetPay();
		};
		POINT GetMousePos()
		{
			POINT Pos;
			GetCursorPos(&Pos);							
			ScreenToClient(hWnd, &Pos);
			return Pos;
		}
		bool IsMousePress(int key)
		{
			SHORT m_KeyState = GetAsyncKeyState(key);	
			if (m_KeyState & 0x8000){					
				KeyState[key] = m_KeyState;			
				return false;							
			}
			else{										
				if (KeyState[key] & 0x8000){			
					KeyState[key] = m_KeyState;		
					return true;						
				}
				return false;
			}
		}
		bool IsOnOption(POINT op)
		{
			POINT temp = GetMousePos();
			if (temp.x>op.x - 50 && temp.x<op.x + 50 && temp.y>op.y - 10&&temp.y<op.y +10)
				return true;
			return false;
		}
		void SetDie()
		{
			Die.x = 210;
			Die.y = 270;
		}
		void SetPay()
		{
			Pay.x = 193;
			Pay.y = 270;
		}

		void ConButton_sizeoftwo(int n)
		{
			ControlSet con;
			ScreenCon show;
			bool flag = false;
			show.Show_Option(n);
			while (1){
				if (con.IsOnOption(Pay) && !flag)
				{
					show.SetColor(0, 7);
					show.Show_Option(n);
					show.SetColor(7, 0);
					flag = true;
				}
				else if (con.IsOnOption(Pay))
				{
					if (con.IsMousePress(VK_LBUTTON))
						break;
				}
				else if (!con.IsOnOption(Pay) && flag){
					show.Show_Option(n);
					flag = false;
				}
			}
			return;
		}
		void SetYesNo()
		{
			Yes.x = 287;
			Yes.y = 273;
			No.x = 409;
			No.y = 273;
		}
		void ConDie(int d)
		{
			ControlSet con;
			ScreenCon show;
			bool flag=false;
			show.Show_Option(1);
			while (1){
				if (con.IsOnOption(Die) && !flag)
				{
					show.SetColor(0, 7);
					show.Show_Option(1);
					show.SetColor(7, 0);
					flag = true;
				}
				else if (con.IsOnOption(Die))
				{
					if (con.IsMousePress(VK_LBUTTON))
						break;
				}
				else if (!con.IsOnOption(Die) && flag){
					show.Show_Option(1);
					flag = false;
				}
			}
			return;
		}
		void SetBuy(){}
		bool ChooseCon()
		{
			ControlSet con;
			ScreenCon show;
			bool yflag = false;
			bool nflag = false;
			show.Show_No();
			show.Show_Yes();
			while (1){
				if (con.IsOnOption(No) && !nflag)
				{
					show.SetColor(0, 7);
					show.Show_No();
					show.SetColor(7, 0);
					nflag = true;
				}
				else if (con.IsOnOption(No))
				{
					if (con.IsMousePress(VK_LBUTTON))
						return false;
				}
				else if (!con.IsOnOption(No) && nflag){
					show.Show_No();
					nflag = false;
				}

				if (con.IsOnOption(Yes) && !yflag)
				{
					show.SetColor(0, 7);
					show.Show_Yes();
					show.SetColor(7, 0);
					yflag = true;
				}
				else if (con.IsOnOption(Yes))
				{
					if (con.IsMousePress(VK_LBUTTON))
						return true;
				}
				else if (!con.IsOnOption(Yes) && yflag){
					show.Show_Yes();
					yflag = false;
				}

			}
		}
		POINT GetDie(){ return Die; }
	private:
		HWND hWnd;
		SHORT KeyState[256];
		POINT Die;
		POINT Yes, No;
		POINT Pay;

};


	/*
	HWND hWnd = GetConsoleWindow();
	//if (wnd == NULL) printf("No\n");
	WinInput test(hWnd);
	while (1)
	{
	if (test.IsKeyPress(VK_LBUTTON)){            // 如果滑鼠左鍵被按下並放開
	POINT Pos = test.GetMousePos();
	wprintf_s(L"LMB (%d,%d)\n", Pos.x, Pos.y);      // 印出 LMB (滑鼠座標)
	}
	}*/
/*
ControlSet a;

ScreenCon c;
c.Show_Option(2);
a.ChooseCon();
while (1)
{

POINT b;
if (a.IsMousePress(VK_LBUTTON)){
b = a.GetMousePos();
printf("%d %d", b.x, b.y);
}
}
*/