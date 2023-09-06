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



int main() {
	string name;
	cout << "输入身份：" << endl;
	cin >> name;
	Map map;
	map.ShowMap();
	map.Map_find();
	map.move();
	map.Map_find();
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	Role enemy_beijing("周口店人", 10, 1, 1, 0, 1, 0, 1);
	character.showrole();

	//fight(character, enemy_beijing);
	
	return 0;
}
