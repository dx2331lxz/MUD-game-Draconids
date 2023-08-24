#include"Map.h"
Map::Map()
:pos(1)
{
	search_map.insert(pair<string,int>("卡塞尔学院",0));
	search_map.insert(pair<string, int>("青铜城", 1));
	search_map.insert(pair<string, int>("北京", 2));
	search_map.insert(pair<string, int>("日本", 3));
	search_map.insert(pair<string, int>("俄罗斯", 4));
	search_map.insert(pair<string, int>("北极", 5));
	search_map.insert(pair<string, int>("仕兰中学", 6));
}
Map::~Map() {

}
void Map::ShowMap()
{
	cout << "           北极" << endl;
	cout << "             |  " << endl;
	cout << "             |   " << endl;
	cout << "          俄罗斯" << endl;
	cout << "        /       \\   " << endl;
	cout << "       /         \\   " << endl;
	cout << "      /           \\" << endl;
	cout << "   北京\t\t  日本" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  "<<posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "仕兰中学 \t   巴西" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t卡塞尔学院" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


}

void Map::move(string &str) {//根据输入地点来到不同位置,若输入错误,退出函数重新输入
	unordered_map<string, int>::iterator it = search_map.find(str);
	if (it != search_map.end()) {
		pos = (*it).second;
		cout << "当前来到" << str << endl;
	}
		
	else  cout << "该地点不存在,请重新输入" << endl;
}

void MapNode::AddChildren(MapNode* NewChildren)
{
	children.push_back(NewChildren);
}
//MapNode::MapNode(MapNode* root)
//{
	
//}
void TreeMap::AddNote(MapNode* newone,MapNode* parent)
{
	//MapNode* Newone(new MapNode(newone));
	parent->AddChildren(newone);
}


School_Map::School_Map()
	:pos()
{

}

void School_Map::showmap()
{
	cout << " |------------------------------------------|" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
}

void School_Map::move(string &action)
{
	if(pos[1])
}