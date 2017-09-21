#include<cstring>
#include<stdio.h>
#define LEN 35
#define STRLEN 256
//enum  minfo{ START , OPP , HOUSE , TEMP};

struct ObjInfo
{
	int category;
	bool ifbuy;
	int rank;
	char owner[STRLEN];
	int value;
	char name[STRLEN];
	int color;
};


class GameSet
{
	protected:
		ObjInfo property[LEN];
	public:
		GameSet(){};
		GameSet(ObjInfo data[])
		{
			for (int i = 0; i < LEN; i++){
				property[i].category = data[i].category;
				property[i].value = data[i].value;
				strcpy(property[i].name, data[i].name);
				property[i].ifbuy= false;
				property[i].rank = 0;
				property[i].color = 7;
				strcpy(property[i].owner,"");
			}
		};
		ObjInfo GetInfo(int num)
		{
			return property[num];
		}
		void Buy(int num, char name[],int c)
		{
			strcpy(property[num].owner,name);
			property[num].ifbuy = true;
			property[num].color = c;
		}
		void Updata_Rank(int num, int op)
		{
			property[num].rank += op;
		}
		bool IsEmpty(int num)
		{
			return !property[num].ifbuy;
		}
		bool IsOwner(int num, char name[])
		{

			return (strcmp(property[num].owner, name)==0);
		}
		bool IsHouse(int num)
		{
			if (num == 0 || num == 11 || num == 17 || num == 28)
				return false;
			return true;
		}
		int GetUpdataFee(int num)
		{
			int temp = 0;
			for (int i = 1; i <= property[num].rank+1; i++)
				temp += i;
			return temp*property[num].value;
		}
		int GetFee(int num)
		{
			return property[num].value*property[num].rank*property[num].rank;
		}
};