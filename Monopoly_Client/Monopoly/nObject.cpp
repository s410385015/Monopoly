#include "MapData.cpp"
#define MAX 35


class Object{


public:

	ObjInfo EacPoint[MAX];
	Object(){};
	void SetObject(){
		EacPoint[0].category = 0;
		EacPoint[0].value = NULL;
		strcpy(EacPoint[0].name, "Start Point");

		EacPoint[1].category = 2;
		EacPoint[1].value = 100;
		strcpy(EacPoint[1].name, "維也納");

		EacPoint[2].category = 2;
		//EacPoint[2].rank = 1;
		EacPoint[2].value = 100;
		strcpy(EacPoint[2].name, "胡同");

		EacPoint[3].category = 2;
		//EacPoint[3].rank = 2;
		EacPoint[3].value = 150;
		strcpy(EacPoint[3].name, "朵爾奇");

		EacPoint[4].category = 2;
		//EacPoint[4].rank = 3;
		EacPoint[4].value = 200;
		strcpy(EacPoint[4].name, "矻克");

		EacPoint[5].category = 2;
		EacPoint[5].value = 150;
		strcpy(EacPoint[5].name, "米卡");

		EacPoint[6].category = 2;
		EacPoint[6].value = 100;
		strcpy(EacPoint[6].name, "依嘉");

		EacPoint[7].category = 2;
		EacPoint[7].value = 150;
		strcpy(EacPoint[7].name, "韓贊");

		EacPoint[8].category = 2;
		EacPoint[8].value = 200;
		strcpy(EacPoint[8].name, "禾岡");

		EacPoint[9].category = 2;
		EacPoint[9].value = 100;
		strcpy(EacPoint[9].name, "帝一");

		EacPoint[10].category = 2;
		EacPoint[10].value = 150;
		strcpy(EacPoint[10].name, "艾波索");

		EacPoint[11].category = 1;
		EacPoint[11].value = NULL;
		strcpy(EacPoint[11].name, "機會");

		EacPoint[12].category = 2;
		EacPoint[12].value = 150;
		strcpy(EacPoint[12].name, "巧食雞");

		EacPoint[13].category = 2;
		EacPoint[13].value = 150;
		strcpy(EacPoint[13].name, "凡提斯");

		EacPoint[14].category = 2;
		EacPoint[14].value = 200;
		strcpy(EacPoint[14].name, "三禾");

		EacPoint[15].category = 2;
		EacPoint[15].value = 250;
		strcpy(EacPoint[15].name, "晶棧");

		EacPoint[16].category = 2;
		EacPoint[16].value = 250;
		strcpy(EacPoint[16].name, "上北大");

		EacPoint[17].category = 1;
		EacPoint[17].value = NULL;
		strcpy(EacPoint[17].name, "命運");

			EacPoint[18].category = 2;
		EacPoint[18].value = 250;
		strcpy(EacPoint[18].name, "滿筑");

		EacPoint[19].category = 2;
		EacPoint[19].value = 200;
		strcpy(EacPoint[19].name, "達人生活館");

		EacPoint[20].category = 2;
		EacPoint[20].value = 250;
		strcpy(EacPoint[20].name, "北大御景");

		EacPoint[21].category = 2;
		EacPoint[21].value = 300;
		strcpy(EacPoint[21].name, "碧連天");

		EacPoint[22].category = 2;
		EacPoint[22].value = 250;
		strcpy(EacPoint[22].name, "耶魯");

		EacPoint[23].category = 2;
		EacPoint[23].value = 300;
		strcpy(EacPoint[23].name, "大學哈佛");

		EacPoint[24].category = 2;
		EacPoint[24].value = 300;
		strcpy(EacPoint[24].name, "大學風呂");

		EacPoint[25].category = 2;
		EacPoint[25].value = 300;
		strcpy(EacPoint[25].name, "鳶山");

		EacPoint[26].category = 2;
		EacPoint[26].value = 250;
		strcpy(EacPoint[26].name, "三峽老街");

		EacPoint[27].category = 2;
		EacPoint[27].value = 250;
		strcpy(EacPoint[27].name, "大英博物館");

		EacPoint[28].category = 1;
		EacPoint[28].value = NULL;
		strcpy(EacPoint[28].name, "事件");

		EacPoint[29].category = 2;
		EacPoint[29].value = 300;
		strcpy(EacPoint[29].name, "清水祖師廟");

		EacPoint[30].category = 2;
		EacPoint[30].value = 300;
		strcpy(EacPoint[30].name, "北大圖書館");

		EacPoint[31].category = 2;
		EacPoint[31].value = 300;
		strcpy(EacPoint[31].name, "北大商院");

		EacPoint[32].category = 2;
		EacPoint[32].value = 300;
		strcpy(EacPoint[32].name, "北大法院");

		EacPoint[33].category = 2;
		EacPoint[33].value = 300;
		strcpy(EacPoint[33].name, "北大公院");

	}

};
