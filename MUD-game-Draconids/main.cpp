#include"main.h"


int main() {
	string name;
	cout << "�����ɫ����" << endl;
	cin >> name;
	Role character(name, 100, 10, 10,10, 0.1, 1, 0, 1);
	character.showrole();
	PlaySound(NULL, 0, SND_PURGE);




	// ��ʼ����ͼ
	cout << "��ӭ���� ****" << endl;
	cout << endl;
	Map map;
	map.ShowMap();
	cout << endl;
	while (true)
	{
		if (!choose(map, character)) {
			break;
		}
	}


	return 0;
}