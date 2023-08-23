#include"main.h"


int main() {
	string name;
	cout << "ÊäÈë½ÇÉ«Ãû£º" << endl;
	cin >> name;
	Role character(name, 100, 10, 10,10, 0.1, 1, 0, 1);
	character.showrole();
	return 0;
}