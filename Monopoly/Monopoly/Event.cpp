#include<cstring>
#define EVENTLEN 256
#define	EVENTMAX 20

struct EventInfo
{
	int fee;
	char str[EVENTLEN];
};

class Event{
	private:
		EventInfo events[EVENTMAX];
	public:
		Event(){};
		void SetEvent()
		{
			events[0].fee = -1000; //所有人扣％數？
			strcpy(events[0].str, "查稅	損失1000元"); 

			events[1].fee = -500;
			strcpy(events[1].str, "口袋破洞	損失500元");

			events[2].fee = -1000;
			strcpy(events[2].str, "被歹徒搶劫 損失1000元");

			events[3].fee = -1500;
			strcpy(events[3].str, "被老爺爺搶劫 損失1500元");

			events[4].fee = -500;
			strcpy(events[4].str, "被老奶奶搶劫	損失500元");

			events[5].fee = -1000;
			strcpy(events[5].str, "不小心把錢存進悠遊卡 損失1000元");

			events[6].fee = -500; // 500*人數？
			strcpy(events[6].str, "請大家吃大餐 損失500元");

			events[7].fee = -2000;
			strcpy(events[7].str, "窮鬼附身	損失2000元");

			events[8].fee = -1000;
			strcpy(events[8].str, "你聽過安麗嗎? 損失1000元");

			events[9].fee = -1500;
			strcpy(events[9].str, "我要課龍族一單! 損失1500元");

			events[10].fee = +500;
			strcpy(events[10].str, "地上撿到錢 獲得500元");

			events[11].fee = +1000;
			strcpy(events[11].str, "遇到有錢人 獲得1000元");

			events[12].fee = +500;
			strcpy(events[12].str, "到Porn的抽屜拿錢 獲得500元");

			events[13].fee = +2000;
			strcpy(events[13].str, "財神附身 獲得2000元");

			events[14].fee = +2000;
			strcpy(events[14].str, "遇到好野人 獲得2000元");

			events[15].fee = +1000;
			strcpy(events[15].str, "禮拜六黃金之日 獲得1000元");

			events[16].fee = +500;
			strcpy(events[16].str, "First Blood 獲得500元");

			events[17].fee = +100;
			strcpy(events[17].str, "提款機噴出一張鈔票  獲得100元");

			events[18].fee = +500;
			strcpy(events[18].str, "遇到小氣的有錢人  獲得500元");

			events[19].fee = +500; //人數or％數？
			strcpy(events[19].str, "撿到五百塊囉~  獲得500元");

		}
		EventInfo GetEvent(int num)
		{
			return events[num];
		}
};
