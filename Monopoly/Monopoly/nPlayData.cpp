#include<cstring>
#define STRLEN 30
#define TOTAL 35

struct PlayerInfo
{
	char name[STRLEN];
	int num;
	int money;
	int item[TOTAL];
	bool property[TOTAL];
	int cur;
	int color;
};

class PlayerSet
{
	private:
		PlayerInfo player;
	public:
		PlayerSet(){};
		PlayerSet(char str[],int n,int c)
		{
			strcpy(player.name, str);
			player.num = n;
			player.color = c;
		};
		void intial()
		{
			player.money = 5000;
			for (int i = 0; i < TOTAL; i++){
				player.item[i] = -1;
				player.property[i] = false;
			}
			player.cur = 0;
		}
		PlayerInfo GetInfo(){ return player; }
		void Update_Money(int fee){ player.money += fee; }
		int GetCurPos(){ return player.cur; }
		int GetColor(){ return player.color; }
		void SetCurPos(int steps){ player.cur = (player.cur + steps) % (TOTAL - 1); }
		bool Add_Item(int it){
			for (int i = 0;i<TOTAL; i++)
			{
				if (player.item[i] == -1){
					player.item[i] = it;
					return true;
				}
				else if (i == TOTAL - 1)
					return false;
			}
		}
		void Delet_Item(int n){
			player.item[n] = -1;
			for (int i = n + 1; i < TOTAL; i++)
			{
				if (player.item[i] == -1)
					break;
				else
					player.item[i - 1] = player.item[i];
			}
		}
		void Add_Property(int n){ player.property[n] = true; }
		void Delet_Property(int n){ player.property[n] = false; }
		bool IsBust()
		{
			if (player.money < 0)
				return true;
			return false;
		}

};