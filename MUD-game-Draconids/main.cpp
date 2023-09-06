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
    std::ofstream outFile("roleData.txt");
    if (outFile.is_open()) {
        outFile << Role.name << "\n";
        outFile << Role.HP << "\n";
        outFile << Role.attack << "\n";
        outFile << Role.DEF << "\n";
        outFile << Role.Agility << "\n";
        outFile << Role.dodge << "\n";
        outFile << Role.life << "\n";
        outFile << Role.money << "\n";
        outFile << Role.level << "\n";
        outFile << Role.EXP << "\n";
        outFile.close();
    }
    else {
        std::cout << "Unable to open file\n";
    }
	return 0;
}
