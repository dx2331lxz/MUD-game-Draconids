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
	search_map.insert(pair<string, int>("巴西", 7));

	Npc* npc1 = new Npc();
	allnpc.push_back(npc1);
	searchNPC_map.insert(pair<string, int>("北京", 0));
	Npc* npc2 = new Npc();
	allnpc.push_back(npc2);
	searchNPC_map.insert(pair<string, int>("日本", 1));
	Npc* npc3 = new Npc();
	allnpc.push_back(npc3);
	searchNPC_map.insert(pair<string, int>("俄罗斯", 2));
	Npc* npc4 = new Npc();
	allnpc.push_back(npc4);
	searchNPC_map.insert(pair<string, int>("北极", 3));
	Npc* npc5 = new Npc();
	allnpc.push_back(npc5);
	searchNPC_map.insert(pair<string, int>("仕兰中学", 4));
	

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



void Map::Map_find(string& str)//在map中查找npc
{
	unordered_map<string, int>::iterator it = searchNPC_map.find(str);
	
	cout << "当前地图存在Npc:" << allnpc[(*it).second]->GetName();
	if (it != searchNPC_map.end())
	{
		cout << ",是否与其对话?" << endl;
		cout << "请输入Y/N" << endl;
		char choice;
		cin >> choice;
		if (choice == 'Y')
			allnpc[(*it).second]->GetTask();
	}
	
	
}










School_Map::School_Map()
	
{
	pos[0] = 0;
	pos[1] = 0;
}

char School_Map::isthere(int x,int y)
{
	if (x == pos[0] && y == pos[1])
		return '*';
	else
		return ' ';
}
void School_Map::showmap()
{
	cout << " |------------------------------------------|" << endl;
	cout << " |         教室        |       训练室       |" << endl;
	cout << " |          "<< isthere(0, 0)   <<"          |    "<<isthere(0, 1)<<"\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |         地窖        |       装备库       |" << endl;
	cout << " |          " << isthere(1, 0) << "          |    " << isthere(1, 1) << "\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |        休息室       |       图书馆       |" << endl;
	cout << " |          " << isthere(2, 0) << "          |    " << isthere(2, 1) << "\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
}

void School_Map::move(char action)//移动输入wasd 如果超出位置,只能在此地呆着
{
	if (pos[0] == 0 && action == 'w' ||pos[0] == 2 && action =='s'
		                             ||
		pos[1] == 0 && action == 'a' ||pos[1] == 1 && action=='d' )
	{
		return;
	}
	if (action == 'w')
		pos[0]++;
	else if (action == 's')
		pos[0]--;
	else if (action == 'a')
		pos[1]--;
	else pos[1]++;

}



MapNode::MapNode()
	:left(nullptr),right(nullptr),role(nullptr){}
MapNode::MapNode(Role* role, MapNode* left, MapNode* right)
	:role(role),left(left),right(right)
{

}
TreeMap::TreeMap() {}
TreeMap::TreeMap(MapNode* root)
	:root(root)
{
	MapNode* new_L = new MapNode();
	MapNode* new_R = new MapNode();

	root->left = new_L;
	root->right = new_R;
	MapNode* new_LL = new MapNode();
	MapNode* new_RR = new MapNode();
	new_L->left = new_LL;
	new_R->right = new_RR;
	MapNode* new_LR = new MapNode();
	MapNode* new_RL = new MapNode();
	new_L->right = new_LR;
	new_R->left = new_RL;
	MapNode* new_End = new MapNode();
	new_LL->right = new_End;
	new_LR->right = new_End;
	new_RL->left = new_End;
	new_RR->left = new_End;
}

void TreeMap::showmap()
{
	cout << "             "<<root->IsThere()<<"                      " << endl;
	cout << "            / \\                     " << endl;
	cout << "           "<< root->left->IsThere() <<"   "<< root->right->IsThere() <<"                     " << endl;
	cout << "          /\\  / \\                     " << endl;
	cout << "         "<< root->left->left->IsThere() <<"  "<< root->left->right->IsThere() <<" "<< root->right -> left->IsThere() <<"  "<< root->right->right->IsThere() <<"                    " << endl;
	cout << "         \\  | |  /                   " << endl;
	cout << "          \\ | | /  " << endl;
	cout << "           \\| |/                    " << endl;
	cout << "             "<< root->left->left->right->IsThere() <<"                       " << endl;
}