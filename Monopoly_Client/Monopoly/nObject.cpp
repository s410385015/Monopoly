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
		strcpy(EacPoint[1].name, "���]��");

		EacPoint[2].category = 2;
		//EacPoint[2].rank = 1;
		EacPoint[2].value = 100;
		strcpy(EacPoint[2].name, "�J�P");

		EacPoint[3].category = 2;
		//EacPoint[3].rank = 2;
		EacPoint[3].value = 150;
		strcpy(EacPoint[3].name, "�����_");

		EacPoint[4].category = 2;
		//EacPoint[4].rank = 3;
		EacPoint[4].value = 200;
		strcpy(EacPoint[4].name, "�}�J");

		EacPoint[5].category = 2;
		EacPoint[5].value = 150;
		strcpy(EacPoint[5].name, "�̥d");

		EacPoint[6].category = 2;
		EacPoint[6].value = 100;
		strcpy(EacPoint[6].name, "�̹�");

		EacPoint[7].category = 2;
		EacPoint[7].value = 150;
		strcpy(EacPoint[7].name, "����");

		EacPoint[8].category = 2;
		EacPoint[8].value = 200;
		strcpy(EacPoint[8].name, "�ݩ�");

		EacPoint[9].category = 2;
		EacPoint[9].value = 100;
		strcpy(EacPoint[9].name, "�Ҥ@");

		EacPoint[10].category = 2;
		EacPoint[10].value = 150;
		strcpy(EacPoint[10].name, "��i��");

		EacPoint[11].category = 1;
		EacPoint[11].value = NULL;
		strcpy(EacPoint[11].name, "���|");

		EacPoint[12].category = 2;
		EacPoint[12].value = 150;
		strcpy(EacPoint[12].name, "������");

		EacPoint[13].category = 2;
		EacPoint[13].value = 150;
		strcpy(EacPoint[13].name, "�Z����");

		EacPoint[14].category = 2;
		EacPoint[14].value = 200;
		strcpy(EacPoint[14].name, "�T��");

		EacPoint[15].category = 2;
		EacPoint[15].value = 250;
		strcpy(EacPoint[15].name, "����");

		EacPoint[16].category = 2;
		EacPoint[16].value = 250;
		strcpy(EacPoint[16].name, "�W�_�j");

		EacPoint[17].category = 1;
		EacPoint[17].value = NULL;
		strcpy(EacPoint[17].name, "�R�B");

			EacPoint[18].category = 2;
		EacPoint[18].value = 250;
		strcpy(EacPoint[18].name, "����");

		EacPoint[19].category = 2;
		EacPoint[19].value = 200;
		strcpy(EacPoint[19].name, "�F�H�ͬ��]");

		EacPoint[20].category = 2;
		EacPoint[20].value = 250;
		strcpy(EacPoint[20].name, "�_�j�s��");

		EacPoint[21].category = 2;
		EacPoint[21].value = 300;
		strcpy(EacPoint[21].name, "�ѳs��");

		EacPoint[22].category = 2;
		EacPoint[22].value = 250;
		strcpy(EacPoint[22].name, "�C�|");

		EacPoint[23].category = 2;
		EacPoint[23].value = 300;
		strcpy(EacPoint[23].name, "�j�ǫ���");

		EacPoint[24].category = 2;
		EacPoint[24].value = 300;
		strcpy(EacPoint[24].name, "�j�ǭ��f");

		EacPoint[25].category = 2;
		EacPoint[25].value = 300;
		strcpy(EacPoint[25].name, "��s");

		EacPoint[26].category = 2;
		EacPoint[26].value = 250;
		strcpy(EacPoint[26].name, "�T�l�ѵ�");

		EacPoint[27].category = 2;
		EacPoint[27].value = 250;
		strcpy(EacPoint[27].name, "�j�^�ժ��]");

		EacPoint[28].category = 1;
		EacPoint[28].value = NULL;
		strcpy(EacPoint[28].name, "�ƥ�");

		EacPoint[29].category = 2;
		EacPoint[29].value = 300;
		strcpy(EacPoint[29].name, "�M�����v�q");

		EacPoint[30].category = 2;
		EacPoint[30].value = 300;
		strcpy(EacPoint[30].name, "�_�j�Ϯ��]");

		EacPoint[31].category = 2;
		EacPoint[31].value = 300;
		strcpy(EacPoint[31].name, "�_�j�Ӱ|");

		EacPoint[32].category = 2;
		EacPoint[32].value = 300;
		strcpy(EacPoint[32].name, "�_�j�k�|");

		EacPoint[33].category = 2;
		EacPoint[33].value = 300;
		strcpy(EacPoint[33].name, "�_�j���|");

	}

};
