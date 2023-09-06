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

int choose(Map& map, Role & character) {
	if (map.GetPosition() == 0) {
		cout << "1. 寻找NPC 2. 传送至地图别处 3. 退出地图 4. 进入学院" << endl;
	}
	else {
		cout << "1. 寻找NPC 2. 传送至地图别处 3. 退出地图" << endl;
	}
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
	case 4: {
		School_Map school_map;
		school_map.move(character);
		break;
	}
	default:
		cout << "你干嘛~~，诶呦" << endl;
		break;
	}
	return true;
}

int main() {
	// 初始化人物信息
	string name;
	cout << "输入身份：" << endl;
	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	character.showrole();
	// 初始化地图
	cout << "欢迎来到 ****" << endl;
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
	Role enemy_beijing("周口店人", 10, 1, 1, 0, 1, 0, 1);
	
	//fight(character, enemy_beijing);

	
	return 0;
}
