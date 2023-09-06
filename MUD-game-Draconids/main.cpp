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
	string name;
	cout << "ÊäÈëÉí·Ý£º" << endl;
	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	character.showrole();
	return 0;
}
