#include"Map.h"
Map::Map()
:pos(1)
{
	search_map.insert(pair<string,int>("������ѧԺ",0));
	search_map.insert(pair<string, int>("��ͭ��", 1));
	search_map.insert(pair<string, int>("����", 2));
	search_map.insert(pair<string, int>("�ձ�", 3));
	search_map.insert(pair<string, int>("����˹", 4));
	search_map.insert(pair<string, int>("����", 5));
	search_map.insert(pair<string, int>("������ѧ", 6));
	search_map.insert(pair<string, int>("����", 7));

	Npc* npc1 = new Npc();
	allnpc.push_back(npc1);
	searchNPC_map.insert(pair<string, int>("����", 0));
	Npc* npc2 = new Npc();
	allnpc.push_back(npc2);
	searchNPC_map.insert(pair<string, int>("�ձ�", 1));
	Npc* npc3 = new Npc();
	allnpc.push_back(npc3);
	searchNPC_map.insert(pair<string, int>("����˹", 2));
	Npc* npc4 = new Npc();
	allnpc.push_back(npc4);
	searchNPC_map.insert(pair<string, int>("����", 3));
	Npc* npc5 = new Npc();
	allnpc.push_back(npc5);
	searchNPC_map.insert(pair<string, int>("������ѧ", 4));
	

}
Map::~Map() {

}
void Map::ShowMap()
{
	cout << "           ����" << endl;
	cout << "             |  " << endl;
	cout << "             |   " << endl;
	cout << "          ����˹" << endl;
	cout << "        /       \\   " << endl;
	cout << "       /         \\   " << endl;
	cout << "      /           \\" << endl;
	cout << "   ����\t\t  �ձ�" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  "<<posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "������ѧ \t   ����" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t������ѧԺ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


}

void Map::move(string &str) {//��������ص�������ͬλ��,���������,�˳�������������
	unordered_map<string, int>::iterator it = search_map.find(str);
	if (it != search_map.end()) {
		pos = (*it).second;
		cout << "��ǰ����" << str << endl;
	}	
	else  cout << "�õص㲻����,����������" << endl;
}



void Map::Map_find(string& str)//��map�в���npc
{
	unordered_map<string, int>::iterator it = searchNPC_map.find(str);
	
	cout << "��ǰ��ͼ����Npc:" << allnpc[(*it).second]->GetName();
	if (it != searchNPC_map.end())
	{
		cout << ",�Ƿ�����Ի�?" << endl;
		cout << "������Y/N" << endl;
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
	cout << " |         ����        |       ѵ����       |" << endl;
	cout << " |          "<< isthere(0, 0)   <<"          |    "<<isthere(0, 1)<<"\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |         �ؽ�        |       װ����       |" << endl;
	cout << " |          " << isthere(1, 0) << "          |    " << isthere(1, 1) << "\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
	cout << " |        ��Ϣ��       |       ͼ���       |" << endl;
	cout << " |          " << isthere(2, 0) << "          |    " << isthere(2, 1) << "\t\t    | " << endl;
	cout << " |                     |                    |" << endl;
	cout << " |------------------------------------------|" << endl;
}

void School_Map::move(char action)//�ƶ�����wasd �������λ��,ֻ���ڴ˵ش���
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