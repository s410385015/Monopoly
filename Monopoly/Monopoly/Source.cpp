#include<stdio.h>
#include<algorithm>
#include<time.h>
#include"Socket.cpp"
#include"Control.cpp"
#include"Event.cpp"

#define p1c 3
#define SLEN 256


int main()
{
	char buffer[MAXBYTE]="?";
	char chosen[2] ="?";
	int nbyte;

	ObjInfo EacPoint[25];
	srand(time(NULL));
	Object obj;
	obj.SetObject();
	
	GameSet data(obj.EacPoint);
	ScreenCon game;
	ControlSet con;
	game.Show_Theme();
	char p1n[SLEN];
	game.Register();
	scanf("%s", p1n);
	game.SetCoord(20,13);
	game.GoToPos(game.GetP());
	printf("輸入IP:");
	char ip[SLEN];
	scanf("%s", ip);

	game.Clear_Enter();
	//char p2n[SLEN];
	//printf("Player2 name:");
	//scanf("%s", p2n);
	SockSet sock(ip);
	sock.Server();
	nbyte = recv(sock.GetClientSock(), buffer, MAXBYTE, NULL);
	send(sock.GetClientSock(), p1n, MAXBYTE, NULL);
	//buffer[nbyte] = '\0';
	system("Cls");
	game.Show_Theme();
	game.Show_Space();
	game.Set_House();
	game.Set_Player();


	
	
	ObjInfo temp;
	EventInfo eve_temp;
	
	//buffer[nbyte] = '\0';
	PlayerInfo pt;
	PlayerSet p1(p1n, 5, p1c);
	PlayerSet p2(buffer, 6, 5);

	Event eve;
	eve.SetEvent();
	p1.intial();
	p2.intial();
	int t;
	game.Show_Player_Initial(p1c);
	game.SetColor(p1c,7);
	game.Show_PlayerM(6,p1.GetInfo().name, p1.GetInfo().money, p1.GetInfo().cur);
	game.SetColor(5);
	game.Show_PlayerM(8,p2.GetInfo().name, p2.GetInfo().money, p2.GetInfo().cur);
	game.SetColor();
	while (1)
	{

		game.Show_Option(1);
		t = rand()%6+1;
		chosen[0] = '0' + t;
		con.ConDie(t);
		send(sock.GetClientSock(),chosen, MAXBYTE, NULL);
		game.Clear();

		pt = p1.GetInfo();
		game.Show_Die(t);
		game.Show_Player(pt.cur, t, p1c, p2.GetCurPos(), p2.GetColor());
		if (p1.GetCurPos() + t > 33){
			p1.Update_Money(1500);
			game.SetColor(p1c);
			game.Show_PlayerM(6, p1.GetInfo().name, p1.GetInfo().money, p1.GetInfo().cur);
			game.SetColor();
		}
		p1.SetCurPos(t);
	
		temp = data.GetInfo(p1.GetCurPos());
		if (!data.IsHouse(p1.GetCurPos()))
		{
			if (p1.GetCurPos() != 0)
			{
				int e = rand() % 20;
				chosen[0] = '0' + e;
				send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
				eve_temp = eve.GetEvent(e);
				int a=eve_temp.fee;
				char str[SLEN];
				strcpy(str, eve_temp.str);
				if (a < 0)
					game.SetColor(4, 0);
				else
					game.SetColor(2, 0);
				game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 0,str );
				game.SetColor();
				
				
				con.ConButton_sizeoftwo(5);
				send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
				p1.Update_Money(a);
				if (p1.IsBust())
					break;
			}
			else
			{
				game.SetColor(6, 0);
				game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 0, "獲得獎金500元!");
				game.SetColor();
				con.ConButton_sizeoftwo(5);
				send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
				p1.Update_Money(500);
			}
		}
		else{
			if (!temp.ifbuy){
				game.Show_Option(2);
				game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 1);
				if (con.ChooseCon())
				{
					chosen[0] = '0' + 1;
					send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
					data.Buy(p1.GetCurPos(), pt.name, pt.color);
					p1.Update_Money(-data.GetUpdataFee(p1.GetCurPos()));
					data.Updata_Rank(p1.GetCurPos(), 1);
					if(p1.IsBust())
						break;
				}
				else
				{
					chosen[0] = '0' + 0;
					send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
				}
					
			}
			else
			{
				if (data.IsOwner(p1.GetCurPos(), pt.name)){
					if (temp.category != 4){
						game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 3);
						game.Show_Option(3);
						if (con.ChooseCon())
						{
							chosen[0] = '0' + 1;
							send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
							p1.Update_Money(-data.GetUpdataFee(p1.GetCurPos()));
							data.Updata_Rank(p1.GetCurPos(), 1);
							if(p1.IsBust())
								break;
						}
						else
						{
							chosen[0] = '0' + 0;
							send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
						}
					}
					else
					{
						game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 3);
						con.ConButton_sizeoftwo(5);
						send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
					}
				}
				else
				{
					game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 2);
					con.ConButton_sizeoftwo(4);
					send(sock.GetClientSock(), chosen, MAXBYTE, NULL);
					p1.Update_Money(-data.GetFee(p1.GetCurPos()));
					p2.Update_Money(data.GetFee(p1.GetCurPos()));
					if(p1.IsBust())
						break;
				}
			}
			
		}
		game.Show_House(data.GetInfo(p1.GetCurPos()), p1.GetCurPos());
		game.SetColor(p1c);
		game.Show_PlayerM(6,p1.GetInfo().name, p1.GetInfo().money, p1.GetInfo().cur);
		game.SetColor(5,7);
		game.Show_PlayerM(8,p2.GetInfo().name, p2.GetInfo().money, p2.GetInfo().cur);
		game.SetColor();
		game.Clear();


		//player2
		//game.Show_Option(1);
		t = sock.Server_R();
		//con.ConDie(t);
		//game.Clear();
		pt = p2.GetInfo();
		game.Show_Die(t);
		game.Show_Player(pt.cur, t, 5, p1.GetCurPos(), p1.GetColor());
		if (p2.GetCurPos() + t > 33){
			p2.Update_Money(1500);
			game.SetColor(5);
			game.Show_PlayerM(6, p2.GetInfo().name, p2.GetInfo().money, p2.GetInfo().cur);
			game.SetColor();
		}
		p2.SetCurPos(t);

		temp = data.GetInfo(p2.GetCurPos());
		if (!data.IsHouse(p2.GetCurPos()))
		{
			if (p2.GetCurPos() != 0)
			{
				int e=sock.Server_R();
				eve_temp = eve.GetEvent(e);
				int a = eve_temp.fee;
				char str[SLEN];
				strcpy(str, eve_temp.str);
				if (a < 0)
					game.SetColor(4, 0);
				else
				game.SetColor(2, 0);
				game.Show_HouseData(data.GetInfo(p2.GetCurPos()), 0, str);
				game.SetColor();
				//con.ConButton_sizeoftwo(5);
				sock.Server_R();
				p2.Update_Money(a);
				if (p2.IsBust())
					break;
			}
			else
			{
				game.SetColor(6, 0);
				game.Show_HouseData(data.GetInfo(p2.GetCurPos()), 0, "獲得獎金500元!");
				game.SetColor();
				//con.ConButton_sizeoftwo(5);
				sock.Server_R();
				p2.Update_Money(500);
			}
		}
		else{
			if (!temp.ifbuy){
				int a = sock.Server_R();
				//game.Show_Option(2);
				//game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 1);
				if (a)
				{
					data.Buy(p2.GetCurPos(), pt.name, pt.color);
					p2.Update_Money(-data.GetUpdataFee(p2.GetCurPos()));
					data.Updata_Rank(p2.GetCurPos(), 1);
					if (p2.IsBust())
						break;
				}
				else
				{

				}

			}
			else
			{
				if (data.IsOwner(p2.GetCurPos(), pt.name)){
					if (temp.category != 4){
						int a = sock.Server_R();
						//game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 3);
						//game.Show_Option(3);
						if (a)
						{
							p2.Update_Money(-data.GetUpdataFee(p2.GetCurPos()));
							data.Updata_Rank(p2.GetCurPos(), 1);
							if (p2.IsBust())
								break;
						}
						else
						{

						}
					}
					else
					{
						//game.Show_HouseData(data.GetInfo(p1.GetCurPos()), 3);
						//con.ConButton_sizeoftwo(5);
						sock.Server_R();
					}
				}
				else
				{
					game.Show_HouseData(data.GetInfo(p2.GetCurPos()), 2);
					sock.Server_R();
					//con.ConButton_sizeoftwo(4);
					p2.Update_Money(-data.GetFee(p2.GetCurPos()));
					p1.Update_Money(data.GetFee(p2.GetCurPos()));
					if (p2.IsBust())
						break;
				}
			}

		}
		game.Show_House(data.GetInfo(p2.GetCurPos()), p2.GetCurPos());
		game.SetColor(p1c,7);
		game.Show_PlayerM(6, p1.GetInfo().name, p1.GetInfo().money, p1.GetInfo().cur);
		game.SetColor(5);
		game.Show_PlayerM(8, p2.GetInfo().name, p2.GetInfo().money, p2.GetInfo().cur);
		game.SetColor();
		game.Clear();
	}
	game.SetColor(p1c);
	game.Show_Result(6, p1.GetInfo().name, p1.GetInfo().money, p1.GetInfo().cur);
	game.SetColor(5);
	game.Show_Result(8, p2.GetInfo().name, p2.GetInfo().money, p2.GetInfo().cur);
	game.SetColor();
	if (p1.IsBust()){
		game.Show_Winner(p2.GetInfo().name);	
		game.Lose();
	}
	else{
		game.Show_Winner(p1.GetInfo().name);
		game.Win();
	}

	getchar();
	
	getchar();
}