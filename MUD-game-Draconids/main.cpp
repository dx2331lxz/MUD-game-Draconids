#include"main.h"

int main()
{
	MapNode* root=new MapNode();
	root->Getthere();
	TreeMap map(root);
	map.showmap();
	system("pause");
	return 0;
}