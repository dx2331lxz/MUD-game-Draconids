#include"main.h"


int main()
{
    welcomePage();
	shared_ptr<MapNode> root=make_shared< MapNode>();
	
	TreeMap map(root);

	map.showmap();
	system("pause");

	return 0;
}


