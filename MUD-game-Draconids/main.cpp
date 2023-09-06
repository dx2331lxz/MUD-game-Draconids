#include"main.h"
#include <string>

//int main()
//{
//    welcomePage();
//	shared_ptr<MapNode> root=make_shared< MapNode>();
//	
//	TreeMap map(root);
//
//	map.showmap();
//	system("pause");
//
//	return 0;
//}

void fight(Role& character, Role& enemy) {
	FightSystem fight(character, enemy);
	while (true)
	{
		if (fight.fightRound()) {
			fight.addround();
		}
		else
		{
			break;
		}
	}
	fight.endFight();
}

int choose(Map& map) {
	cout << "1. Ѱ��NPC 2. ��������ͼ�� 3. �˳���ͼ" << endl;
	int i;
	cin >> i;
	switch (i)
	{
	case 1: {
		map.Map_find();
		break;
	}
	case 2: {
		map.move();
		map.ShowMap();
		break;
	}
	case 3:
		return false;
	default:
		cout << "�����~~������" << endl;
		break;
	}
	return true;
}

int main() {
	// ��ʼ��������Ϣ
	string name;
	cout << "������ݣ�" << endl;
	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	character.showrole();
	// ��ʼ����ͼ
	cout << "��ӭ���� ****" << endl;
	cout << endl;
	Map map;
	map.ShowMap();
	cout << endl;
	while (true)
	{
		if (!choose(map)) {
			break;
		}
	}
	Role enemy_beijing("�ܿڵ���", 10, 1, 1, 0, 1, 0, 1);
	
	//fight(character, enemy_beijing);

	
	return 0;
}
