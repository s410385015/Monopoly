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
			events[0].fee = -1000; //�Ҧ��H���H�ơH
			strcpy(events[0].str, "�d�|	�l��1000��"); 

			events[1].fee = -500;
			strcpy(events[1].str, "�f�U�}�}	�l��500��");

			events[2].fee = -1000;
			strcpy(events[2].str, "�Q��{�m�T �l��1000��");

			events[3].fee = -1500;
			strcpy(events[3].str, "�Q�ѷݷݷm�T �l��1500��");

			events[4].fee = -500;
			strcpy(events[4].str, "�Q�ѥ����m�T	�l��500��");

			events[5].fee = -1000;
			strcpy(events[5].str, "���p�ߧ���s�i�y�C�d �l��1000��");

			events[6].fee = -500; // 500*�H�ơH
			strcpy(events[6].str, "�Фj�a�Y�j�\ �l��500��");

			events[7].fee = -2000;
			strcpy(events[7].str, "�a������	�l��2000��");

			events[8].fee = -1000;
			strcpy(events[8].str, "�Ať�L�w�R��? �l��1000��");

			events[9].fee = -1500;
			strcpy(events[9].str, "�ڭn���s�ڤ@��! �l��1500��");

			events[10].fee = +500;
			strcpy(events[10].str, "�a�W�ߨ�� ��o500��");

			events[11].fee = +1000;
			strcpy(events[11].str, "�J�즳���H ��o1000��");

			events[12].fee = +500;
			strcpy(events[12].str, "��Porn����P���� ��o500��");

			events[13].fee = +2000;
			strcpy(events[13].str, "�]������ ��o2000��");

			events[14].fee = +2000;
			strcpy(events[14].str, "�J��n���H ��o2000��");

			events[15].fee = +1000;
			strcpy(events[15].str, "§������������ ��o1000��");

			events[16].fee = +500;
			strcpy(events[16].str, "First Blood ��o500��");

			events[17].fee = +100;
			strcpy(events[17].str, "���ھ��Q�X�@�i�r��  ��o100��");

			events[18].fee = +500;
			strcpy(events[18].str, "�J��p�𪺦����H  ��o500��");

			events[19].fee = +500; //�H��or�H�ơH
			strcpy(events[19].str, "�ߨ줭�ʶ��o~  ��o500��");

		}
		EventInfo GetEvent(int num)
		{
			return events[num];
		}
};
