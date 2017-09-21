#include<stdio.h>
#include<algorithm>
#include<windows.h>
#include"Object.cpp"
#include"PlayData.cpp"
#define BLANK 34


class ScreenCon
{
	private:
		COORD p;
		COORD house[BLANK];
		COORD player[BLANK];
		COORD temp[BLANK];
	public:
		ScreenCon(){};
		void GoToPos(COORD Pos )
		{
			HANDLE Hin;
			Hin = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(Hin, Pos);
		}
		void getxy(short *x, short *y)
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			*x = csbi.dwCursorPosition.X;
			*y = csbi.dwCursorPosition.Y;
		}
		COORD GetP(){ return p; }
		COORD GetCoord(int n){ return player[n]; }
		void intial()
		{
			for (int i = 0; i < BLANK; i++){
				temp[i].X = temp[i].Y = 0;
				house[i] = player[i] = temp[i];
			}
		}
		void SetColor(int f = 7, int b = 0)
		{
			unsigned short ForeColor = f + 16 * b;
			HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hCon, ForeColor);
		}
		void SetCoord(int x, int y)
		{
			p.X = x;
			p.Y = y;
		}

		void Show_Die(int n)
		{
			Clean_Title();
			SetCoord(33, 2);
			GoToPos(p);
			printf("骰子點數: %d",n);
			Sleep(200);
		}

		void Show_Space()
		{
			int n = 0;
			SetCoord(14, 4);
			GoToPos(p);
			for (int i = 0; i < 12 ; i++)
			{
				printf("[  ]");
				getxy(&temp[n].X, &temp[n].Y);
				n++;
			}
			printf("\n");
			for (int i = 0; i < 5; i++){
				SetCoord(p.X, p.Y + 1);
				GoToPos(p);
				printf("[  ]");
				getxy(&temp[n].X, &temp[n].Y);
				n++;
				for (int j = 0; j < 40; j++) printf(" ");
				printf("[  ]");
				getxy(&temp[n].X, &temp[n].Y);
				printf("\n");
				n++;
			}
			SetCoord(p.X, p.Y + 1);
			GoToPos(p);
			for (int i = 0; i < 12 ; i++)
			{
				printf("[  ]");
				getxy(&temp[n].X, &temp[n].Y);
				n++;
			}
	
		}

		void Set_House()
		{
			for (int i = 0; i < BLANK; i++)
			{
				if (i>0 && i < 11){
					house[i].Y =temp[i].Y- 1;
					house[i].X =temp[i].X- 3;
				}
				else if (i>11 && i < 22)
				{
					house[i].Y = temp[i].Y;
					if (!(i % 2))
						house[i].X = temp[i].X - 6;
					else
						house[i].X = temp[i].X;
		
				}
				else{
					house[i].Y =temp[i].Y+ 1;
					house[i].X =temp[i].X- 3;

				}
			}

			COORD s[BLANK];
			for (int i = 0; i < BLANK; i++)
				s[i] = house[i];
			int n = 12;
			for (int i = 13; i < 22; i += 2)
				house[n++] = s[i];
			for (int i = 33; i>21; i--)
				house[n++] = s[i];
			for (int i = 20; i>11; i -= 2)
				house[n++] = s[i];
			Show_Sp();
		}

		void Show_House(ObjInfo data,int num)
		{
			GoToPos(house[num]);
			if (data.category == 2)
			{	
				SetColor(data.color, 0);
				if (data.rank == 1)	printf("▃");
				else if (data.rank == 2)	printf("▅");
				else if (data.rank == 3)	printf("▇");
				else if (data.rank == 4)	printf("▲");
				SetColor();
			}
		}
		void Show_Player_Initial(int c){
			GoToPos(player[0]);
			SetColor(c, 0);
			printf("●");
			SetColor();
		}
		void Set_Player()
		{
				
			for (int i = 0; i < BLANK; i++)
			{
				player[i].X=temp[i].X-3;
				player[i].Y = temp[i].Y;
			}
			COORD s[BLANK];
			for (int i = 0; i < BLANK; i++)
				s[i] = player[i];
			int n = 12;
			for (int i = 13; i < 22; i+=2)
				player[n++] = s[i];
			for (int i = 33; i>21; i--)
				player[n++] = s[i];
			for (int i = 20; i>11; i -= 2)
				player[n++] = s[i];
		}
		
		void Show_Player(int cur,int steps,int color,int ocur,int oc)
		{

			GoToPos(player[cur%BLANK]);
			if (cur == ocur)
			{
				SetColor(oc, 0);
				printf("●");
				SetColor();
			}
			else
				printf(" ");
			cur++;
			for (int i = 0; i < steps-1; i++){
				GoToPos(player[cur%BLANK]);
				SetColor(color, 0);
				printf("●");
				SetColor();
				if (cur%BLANK == 0){
					Show_Pass();
					Sleep(300);
				}
				Sleep(200);
				GoToPos(player[cur%BLANK]);
				if (cur%34 == ocur)
				{
					SetColor(oc, 0);
					printf("●");
					SetColor();
				}
				else
					printf(" ");
				cur++;
			}
			GoToPos(player[cur%BLANK]);
			SetColor(color, 0);
			printf("●");
			SetColor();
			Clean_Title();
		}

		void Clear()
		{
			for (int j = 12; j < 20;j++)
			{
				for (int i = 1; i < 79; i++)
				{
					SetCoord(i, j);
					GoToPos(p);
					printf(" ");
				}
			}
		}

		void Show_HouseData(ObjInfo cur,int ncase,char new_event[]=NULL)
		{
			SetCoord(20, 13);
			GoToPos(p);
			int temp;
			switch (ncase){
				case 0:
					printf("%s %s", cur.name,new_event);
					break;
				case 1:
					printf("%s 空屋 %d", cur.name, cur.value);
					break;
				case 2:				
					temp = cur.value*cur.rank*cur.rank;
					printf("%s %s 過路費:%d", cur.name, cur.owner, temp);
					break;
				case 3:
					temp=0;
					for (int i = 1; i <= cur.rank+1; i++)
						temp += i;
					temp = cur.value*temp;
					printf("%s %s 升級費:%d", cur.name, cur.owner, temp);
					break;
				
			}
		}
	
		void Show_Option(int ncase)
		{
			SetCoord(20, 17);
			GoToPos(p);
			switch (ncase){
				case 1:
					SetCoord(20, 15);
					GoToPos(p);
					printf("擲骰子");
					break;
				case 2:
					SetCoord(20, 15);
					GoToPos(p);
					printf("購買:");
					break;
				case 3:
					SetCoord(20, 15);
					GoToPos(p);
					printf("升級:");
					break;
				case 4:
					SetCoord(20, 15);
					GoToPos(p);
					printf("付款");
					break;
				case 5:
					SetCoord(20, 15);
					GoToPos(p);
					printf("確認");
					break;
			}
			SetCoord(79, 0);
			GoToPos(p);
		}
		void Show_Yes()
		{
			SetCoord(35, 15);
			GoToPos(p);
			printf("是");
			SetCoord(79,0);
			GoToPos(p);
		}

		void Show_No()
		{
			SetCoord(50, 15);
			GoToPos(p);
			printf("否");
			SetCoord(79, 0);
			GoToPos(p);
		}
		void Show_PlayerM(int y, char name[], int money, int cur)
		{
			Clean_Mid(y);
			SetCoord(24, y);
			GoToPos(p);
			printf("%s:%d元 目前位於%d", name, money,cur);
			SetCoord(79, 0);
			GoToPos(p);
		}
		void Show_Result(int y, char name[], int money, int cur)
		{
			Clean_Mid(y);
			SetCoord(24, y);
			GoToPos(p);
			if (money >= 0)
				printf("%s:%d元 目前位於%d", name, money, cur);
			else
				printf("%s 破產", name);
			SetCoord(79, 0);
			GoToPos(p);
		}
		void Show_Winner(char name[])
		{
			Clean_Title();
			SetCoord(33, 2);
			GoToPos(p);
			printf("%s 獲勝了!", name);
		}
		void Show_Sp()
		{
			int sp[4] = { 0, 11, 17, 28 };
			for (int i = 0; i < 4; i++){
				SetCoord(house[sp[i]].X-1, house[sp[i]].Y-1);
				GoToPos(p);
				SetColor(6);
				printf("[  ]");
				SetColor();
			}
		}
		void Show_Pass()
		{
			Clean_Title();
			SetCoord(30, 2);
			GoToPos(p);
			printf("通過原點 獲得獎金1500元");
		}
		void Clean_Mid(int y)
		{
			SetCoord(29, y);
			GoToPos(p);
			for (int i = 0; i < 23; i++)
				printf(" ");
		}
		void Clean_Title()
		{
			SetCoord(1, 2);
			GoToPos(p);
			for (int i =0; i < 70;i++)
				printf(" ");
		}
		void Show_Theme()
		{
			for (int i = 0; i < 80; i++)
				printf("_");

			for (int i = 1; i < 20; i++)
			{
				SetCoord(0, i);
				GoToPos(p);
				printf("|");
				SetCoord(79, i);
				GoToPos(p);
				printf("|");
			}
			printf("|");
			for (int i = 1; i < 79; i++)
				printf("_");
			printf("|");
			SetColor(0, 7);
			SetCoord(0, 0);
			GoToPos(p);
			printf("北大大富翁ver1.0 Server");
			SetColor();
		}
		void Lose()
		{
			for (int i = 1; i < 7; i++){
				SetColor(i);
				SetCoord(11, 13);
				GoToPos(p);
				printf("▇           ◢▇▇▇◣    ◢▇▇▇▇◣  ◢▇▇▇▇◣  ▇");
				SetCoord(11, 14);
				GoToPos(p);
				printf("▇         ◢          ◣  ▇            ▇            ▇ ");
				SetCoord(11, 15);
				GoToPos(p);
				printf("▇         ◢          ◣  ▇            ▇            ▇ ");
				SetCoord(11, 16);
				GoToPos(p);
				printf("▇         ▇          ▇  ▇▇▇▇▇◣  ▇▇▇▇▇▇  ▇ ");
				SetCoord(11, 17);
				GoToPos(p);
				printf("▇         ▇          ▇            ▇  ▇            ▇ ");
				SetCoord(11, 18);
				GoToPos(p);
				printf("▇         ◥          ◤            ▇  ▇               ");
				SetCoord(11, 19);
				GoToPos(p);
				printf("▇▇▇▇▇◣ ◥▇▇▇◤    ◥▇▇▇▇◤  ◥▇▇▇▇◤  ▇ ");
				Sleep(300);
			}
		}
		void Win()
		{
			for (int i = 1; i < 7; i++){
				SetColor(i);
				SetCoord(11, 13);
				GoToPos(p);
				printf("▇                ▇       ▇       ◢◣         ▇    ▇ ");
				SetCoord(11, 14);
				GoToPos(p);
				printf("▇                ▇                ▇▇         ▇    ▇ ");
				SetCoord(11, 15);
				GoToPos(p);
				printf("▇       ▇       ▇       ▇       ▇  ▇       ▇    ▇ ");
				SetCoord(11, 16);
				GoToPos(p);
				printf("▇       ▇       ▇       ▇       ▇    ▇     ▇    ▇ ");
				SetCoord(11, 17);
				GoToPos(p);
				printf("▇       ▇       ▇       ▇       ▇       ▇  ▇    ▇ ");
				SetCoord(11, 18);
				GoToPos(p);
				printf("◥       ▇       ◤       ▇       ▇         ▇▇       ");
				SetCoord(11, 19);
				GoToPos(p);
				printf("  ◥▇▇◤◥▇▇◤         ▇       ▇         ◥◤    ▇ ");
				Sleep(300);
			}
		}

		void Register()
		{
			SetCoord(10, 3);
			GoToPos(p);
			printf(" __  __  ____  _   _  ____  _____   ____  _  __     __\n");
			SetCoord(10, 4);
			GoToPos(p);
			printf("|  \\/  |/ __ \\| \\ | |/ __ \\|  __ \\ / __ \\| | \\ \\   / /\n");
			SetCoord(10, 5);
			GoToPos(p);
			printf("| \\  / | |  | |  \\| | |  | | |__) | |  | | |  \\ \\_/ / \n");
			SetCoord(10, 6);
			GoToPos(p);
			printf("| |\\/| | |  | | . ` | |  | |  ___/| |  | | |   \\   /  \n");
			SetCoord(10, 7);
			GoToPos(p);
			printf("| |  | | |__| | |\\  | |__| | |    | |__| | |___ | | \n");
			SetCoord(10, 8);
			GoToPos(p);
			printf("|_|  |_|\\____/|_| \\_|\\____/|_|     \\____/|_____||_|\n");
			SetCoord(20, 12);
			GoToPos(p);
			printf("請輸入使用者名稱:");
		}
		void Clear_Enter()
		{
			SetCoord(20, 14);
			GoToPos(p);
			printf("等待玩家連線中.....");
			SetCoord(0, 0);
			GoToPos(p);
		}
};


//int main()
//{
	/*
	srand(time(NULL));
	ScreenCon show;
	ControlSet con;
	POINT t;
	t.x=210;
	t.y = 270;
	con.SetDie(t);
	while (1)
	{
		int temp=rand()%6+1;
		bool flag = false;
		show.Show_Die(temp);
		while(!con.IsMousePress(VK_LBUTTON)){
			t = con.GetDie();
			if (con.IsOnOption(t)&&!flag)
			{
				show.SetColor(0, 7);
				show.Show_Die(temp);
				show.SetColor(7, 0);
				flag = true;
			}
			else if (!con.IsOnOption(t) && flag){
				show.Show_Die(temp);
				flag = false;
			}
		}
		getchar();
		

	}
	*/
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
	srand(time(NULL));
	ScreenCon game;
	Object obj;
	
	game.Show_Space();
	game.Set_House();
	game.Set_Player();
	obj.SetObject();
	GameSet data(obj.EacPoint);

	ObjInfo temp;
	
	PlayerInfo pt;
	PlayerSet p1("Nako",5,p1c);
	PlayerSet p2("Okan",6,2);
	p1.intial();
	p2.intial();
	int t;
	game.Show_Player_Initial(p1c);
	while (1)
	{
		getchar();
		t = rand() % 6 + 1;
		pt = p1.GetInfo();
		game.Show_Die(t);
		game.Show_Player(pt.cur, t, p1c, p2.GetCurPos(), p2.GetColor());
		p1.SetCurPos(t);
		temp = data.GetInfo(p1.GetCurPos());
		game.Show_HouseData(data.GetInfo(p1.GetCurPos()));
		game.Show_Option(pt, temp);
		

		getchar();
		if (!temp.ifbuy){
			data.Buy(p1.GetCurPos(),pt.name,pt.color);
			data.Updata_Rank(p1.GetCurPos(), 1);
		}
		else
		{
			
			if (data.IsOwner(p1.GetCurPos(), pt.name)){
				data.Updata_Rank(p1.GetCurPos(), 1);
			}
		}
		game.Show_House(data.GetInfo(p1.GetCurPos()), p1.GetCurPos());
		game.Clear();
		//player2
		getchar();
		t = rand() % 6 + 1;
		pt = p2.GetInfo();
		game.Show_Die(t);
		game.Show_Player(pt.cur, t, pt.color,p1.GetCurPos(),p1.GetColor());
		p2.SetCurPos(t);
		temp = data.GetInfo(p2.GetCurPos());
		game.Show_HouseData(data.GetInfo(p2.GetCurPos()));
		game.Show_Option(pt, temp);


		getchar();
		if (!temp.ifbuy){
			data.Buy(p2.GetCurPos(), pt.name, pt.color);
			data.Updata_Rank(p2.GetCurPos(), 1);
		}
		else
		{
		
			if (data.IsOwner(p2.GetCurPos(), pt.name)){	
				data.Updata_Rank(p2.GetCurPos(), 1);
			}
		}
		game.Show_House(data.GetInfo(p2.GetCurPos()), p2.GetCurPos());
		game.Clear();
	}
	*/
//}
