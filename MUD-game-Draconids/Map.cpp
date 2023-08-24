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

	shared_ptr<Npc> npc1=make_shared<Npc>();
	allnpc.push_back(npc1);
	searchNPC_map.insert(pair<string, int>("����", 0));
	shared_ptr<Npc> npc2 = make_shared<Npc>();
	allnpc.push_back(npc2);
	searchNPC_map.insert(pair<string, int>("�ձ�", 1));
	shared_ptr<Npc> npc3 = make_shared<Npc>();
	allnpc.push_back(npc3);
	searchNPC_map.insert(pair<string, int>("����˹", 2));
	shared_ptr<Npc> npc4 = make_shared<Npc>();
	allnpc.push_back(npc4);
	searchNPC_map.insert(pair<string, int>("����", 3));
	shared_ptr<Npc> npc5 = make_shared<Npc>();
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
MapNode::MapNode(unique_ptr<Role>& role, shared_ptr<MapNode> left, shared_ptr<MapNode> right)
	:role(move(role)),left(left),right(right)
{

}
//TreeMap::TreeMap()
//:root(nullptr),now(nullptr){}
TreeMap::TreeMap(shared_ptr<MapNode> root)
	:root(root),now(root)
{
	shared_ptr<MapNode> new_L =make_shared<MapNode>();
	shared_ptr<MapNode> new_R = make_shared<MapNode>();

	root->left = new_L;
	root->right = new_R;
	shared_ptr<MapNode> new_LL = make_shared<MapNode>();
	shared_ptr<MapNode> new_RR = make_shared<MapNode>();
	new_L->left = new_LL;
	new_R->right = new_RR;
	shared_ptr<MapNode> new_LR = make_shared<MapNode>();
	shared_ptr<MapNode> new_RL = make_shared<MapNode>();
	new_L->right = new_LR;
	new_R->left = new_RL;
	shared_ptr<MapNode> new_End = make_shared<MapNode>();
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


char MapNode::IsThere()
{
	if (isthere)
		return '*';
	else
		return'0';
}

shared_ptr<MapNode> MapNode::goaway()//�뿪ʱ����
{
	cout << "������L\\R�뿪:" << endl;
	char choice;
	do {
		cin >> choice;
		if (choice == 'L' && this->left)
		{
			isthere = false;
			this->left->Getthere();
			return this->left;
		}
		else if (choice == 'R' && this->right)
		{
			isthere = false;
			this->right->Getthere();
			return this->right;
		}
		else
			cout << "��������,����������" << endl;
	} while (1);
}