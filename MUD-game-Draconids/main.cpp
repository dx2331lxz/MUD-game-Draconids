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

int main() {
	//welcomePage();
	////introduce();
	string name;
	cout << "ÊäÈëÉí·Ý£º" << endl;
	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	Map map;
	
	map.move();
	map.Map_find();
	system("pause");
	//character.showrole();
	//choose(map);
	return 0;
}
