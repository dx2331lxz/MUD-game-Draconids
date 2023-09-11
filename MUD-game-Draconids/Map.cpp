#include"Map.h"
Map::Map():pos(0)
{
	search_map.insert(pair<string, int>("������ѧԺ", 0));
	search_map.insert(pair<string, int>("��ͭ��", 1));
	search_map.insert(pair<string, int>("����", 2));
	search_map.insert(pair<string, int>("�ձ�", 3));
	search_map.insert(pair<string, int>("����˹", 4));
	search_map.insert(pair<string, int>("����", 5));
	search_map.insert(pair<string, int>("������ѧ", 6));
	search_map.insert(pair<string, int>("����", 7));


	string name1 = "����а��";
	vector<string>task1 = { "��....����˭","���������ŷ�ɥ�������µ�һɱ��ħ����а��","����....�Ұ���","һ����Ѫ����,��ô���׵�սʤ����.",
	"��Ը����Ҹ�����","����������Ը����"
	};
	string conversation1 = "��...����";
	Npc npc5(name1, task1, conversation1, 6);//����а����������ѧ

	string name2 = "�����ӳ�";
	vector<string>task2 = { "����,�������ϴ��鷳��","һ����������������,����˼�����ƻ�,����ͻ�����ȥ������,�������ǻ�����",
		"�������������о綾,�ͻ���������Ū����","����ֻ������Ѫ���ܾȰͻ�",
	"��ϣ���õ���İ���,ȥ�õ��������������Ѫ","����,��ȥ���,�ͻ��Ų��˶����" };
	string conversation2 = "on your left";
	Npc npc4(name2, task2, conversation2, 5);//�����ӳ��ڱ���

	string name3 = "���";
	vector<string>task3 = { "���Ǵ��,�ǵ����ƽ����TPC��GUTSС�Ӷ�Ա","ͬʱ,��Ҳ�ǵ��Ȱ�����","�������ȶ���˵:�ѵ���������������һ���˳е��𱣻����������ô?",
	"��������仰Ҳ������֪������:�ⲻ��������Ϊ�����ˣ���ֻ���������������¡�" ,"ȥ���������������,��Ϊһ������������."
	};
	string conversation3 = "����Ӯ���ˣ�����������";
	Npc npc2(name3, task3, conversation3, 3);//������ձ�

	string name4 = "ϣ�����ء��á�����";
	vector<string>task4 = { "��Ҫ�ҵ������ǵĹʹ����������������棬����Щ��ͭ����ʯ��ˮ�»��߸��������Ĺ����ﶼ����һö�˵�Ȼ��ͬʱ����,",
		"�������Ǹ�����������ͭ���Ͽ���Ⱥ����������縲�𣬴������һ�����������������","����,��ͭ��,ȥ��","Ϊ���������ҫ" };
	string conversation4 = "��ʷ���Ǹ����ĳ��֣�����Щ�˵��ڳ����£����ڸ����Ǳ��磬������ʷ���Ǳ�Ȼ.";
	Npc npc1(name4, task4, conversation4, 2);//�����ڱ���

	string name5 = "��ҹ��";
	vector<string>task5 = { "���С�����Ļƻ衯���������������֮�����ľ��ӺͶ�ħ��һ�𷢶������ߵ�ս��,",
		"�����Ļ�˵2012������̫���͵ľ�ͷ�����������µļ�Ԫ����Ϊһ�г��׽���",
	"�����˵�����޴������֮������֮�У����޼�������������죬ȫ������һ���糾��Ʈɢ��"
	,"�����Ҳ�����,����һ���а취���������,����������Ҳ������ֹ��",
	"�ҵ���֮��,��Ѱ����ɡ�" };
	string conversation5 = "���Լ�Ҳ���Ϲ��";
	Npc npc3(name5, task5, conversation5, 4);//��ҹ���ڶ���˹ 

	shared_ptr<Npc> npc1_ptr = make_shared<Npc>(npc1);
	allnpc.push_back(npc1_ptr);
	//searchNPC_map.insert(pair<string, int>("����", 0));
	shared_ptr<Npc> npc2_ptr = make_shared<Npc>(npc2);
	allnpc.push_back(npc2_ptr);
	//searchNPC_map.insert(pair<string, int>("�ձ�", 1));
	shared_ptr<Npc> npc3_ptr = make_shared<Npc>(npc3);
	allnpc.push_back(npc3_ptr);
	//searchNPC_map.insert(pair<string, int>("����˹", 2));
	shared_ptr<Npc> npc4_ptr = make_shared<Npc>(npc4);
	allnpc.push_back(npc4_ptr);
	//searchNPC_map.insert(pair<string, int>("����", 3));
	shared_ptr<Npc> npc5_ptr = make_shared<Npc>(npc5);
	allnpc.push_back(npc5_ptr);
	//searchNPC_map.insert(pair<string, int>("������ѧ", 4));
}
Map::~Map() {

}
void Map::ShowMap()
{
	cout << "          " << isthere(5) << "����" << endl;
	cout << "             |  " << endl;
	cout << "             |   " << endl;
	cout << "         " << isthere(4) << "����˹" << endl;
	cout << "        /       \\   " << endl;
	cout << "       /         \\   " << endl;
	cout << "      /           \\" << endl;
	cout << "   " << isthere(2) << "����\t  " << isthere(6) << "�ձ�" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  " << isthere(1) << posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "" << isthere(4) << "������ѧ \t   " << isthere(7) << "����" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t" << isthere(0) << "������ѧԺ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "*��ʾ����ǰ��λ��" << endl;
}

string Map::move() {//��������ص�������ͬλ��,���������,�˳�������������
	while (1)
	{
		ShowMap();
		cout << "������ǰ��λ��:" << endl;
		string str;
		cin >> str;
		unordered_map<string, int>::iterator it = search_map.find(str);
		if (it != search_map.end()) {
			pos = (*it).second;
			cout << "��ǰ����" << str << endl;
			return str;
		}
		else  cout << "�õص㲻����,����������" << endl;
	}

}

char Map::isthere(int a)
{
	if (pos == a)
		return'*';
	return ' ';
}

//void Map::Map_find()//��map�в���npc
//{
//	if (pos == 0) {
//		cout << "*****" << endl;
//	}
//
//	if (searchNPC_map[pos])
//		allnpc[pos - 2]->GetTask();
//	/*cout << "��ǰ��ͼ����Npc:" << allnpc[(*it).second]->GetName();
//	if (it != searchNPC_map.end())
//	{
//		cout << ",�Ƿ�����Ի�?" << endl;
//		cout << "������Y/N" << endl;
//		char choice;
//		cin >> choice;
//		if (choice == 'Y')
//			allnpc[(*it).second]->GetTask();
//	}*/
//
//
//}
void Map::Map_find()//��map�в���npc
{
	if (pos == 0) {
		cout << "�ҵ�npc������Ϊ����" << endl;
		cout << "ѧԺ����,ǰ����ͭ��,նɱ�������塣" << endl;
	}


	if (searchNPC_map[pos]) {
		cout << "�ҵ�npc������Ϊ��" << allnpc[pos - 2]->GetName() << endl;
		while (1) {
			cout << "ѡ�1.talk��2.task,3.leave" << endl;
			string choice;
			cin >> choice;
			if (choice == "talk")
				allnpc[pos - 2]->conversation();
			else if (choice == "task")
				allnpc[pos - 2]->GetTask();
			else if (choice == "leave")
				break;
			else
				cout << "�����������������" << endl;
		}
	}

	/*cout << "��ǰ��ͼ����Npc:" << allnpc[(*it).second]->GetName();
	if (it != searchNPC_map.end())
	{
		cout << ",�Ƿ�����Ի�?" << endl;
		cout << "������Y/N" << endl;
		char choice;
		cin >> choice;
		if (choice == 'Y')
			allnpc[(*it).second]->GetTask();
	}*/


}



School_Map::School_Map()

{
	pos[0] = 0;
	pos[1] = 0;
}

char School_Map::isthere(int x, int y)
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
	cout << " |          " << isthere(0, 0) << "          |    " << isthere(0, 1) << "\t\t    | " << endl;
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


bool fight(Role& character, Role& enemy) {
	FightSystem fight(character, enemy);
	while (true)
	{
		if (fight.fightRound()) {
			fight.addround();
		}
		else
		{
			break;
		}
	}
	bool i;
	i = fight.endFight();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	return i;
}

void School_Map::move(Role& character)//�ƶ�����wasd,e�˳� �������λ��,ֻ���ڴ˵ش���
{
	Role enemy("����", 10, 1, 1, 1, 1, 10, 1);
	while (true) {
		system("cls");
		showmap();
		cout << "����wasd�ƶ�,����e�˳�" << endl;
		char action;
		cin >> action;
		if (pos[0] == 0 && action == 'w' || pos[0] == 2 && action == 's'
			||
			pos[1] == 0 && action == 'a' || pos[1] == 1 && action == 'd')
		{
			cout << "��������,����������." << endl;
		}
		else
		{
			if (action == 'w')
				pos[0]--;
			else if (action == 's')
				pos[0]++;
			else if (action == 'a')
				pos[1]--;
			else if (action == 'd')
				pos[1]++;
			else return;
		}
		if ((isthere(2, 0) == '*') && (enemy.getHP() != 0)) {
			cout << "�������˵���, �������¼���ѡ���������֣���" << endl;
			while (true)
			{
				cout << "1. �鿴������Ϣ 2. ����ս�� 3. �뿪" << endl;
				int foo = 0; // ����ѭ���Ƿ����
				int choice = 0;
				cin >> choice;
				switch (choice)
				{
				case 1:
					enemy.showrole();
					break;
				case 2:
					if (fight(character, enemy)) {
						foo = 1;
					}
					break;
				case 3:
					foo = 1;
					break;
				default:
					cout << "����"<< endl;
					break;
				}
				if (foo) {
					break;
				}
			}

		}
	}
}



MapNode::MapNode(string name)
	:left(nullptr), right(nullptr), role(nullptr),name(name) {}
MapNode::MapNode(unique_ptr<Role>& role, shared_ptr<MapNode> left, shared_ptr<MapNode> right)
	:role(move(role)), left(left), right(right)
{

}
string MapNode::getname()
{
	return string(name);
}
//TreeMap::TreeMap()
//:root(nullptr),now(nullptr){}
TreeMap::TreeMap()
{
	root = make_shared<MapNode>("root");
	now = root;
	shared_ptr<MapNode> new_L = make_shared<MapNode>("new_L");
	shared_ptr<MapNode> new_R = make_shared<MapNode>("new_R");

	root->left = new_L;
	root->right = new_R;
	shared_ptr<MapNode> new_LL = make_shared<MapNode>("new_LL");
	shared_ptr<MapNode> new_RR = make_shared<MapNode>("new_RR");
	new_L->left = new_LL;
	new_R->right = new_RR;
	shared_ptr<MapNode> new_LR = make_shared<MapNode>("new_LR");
	shared_ptr<MapNode> new_RL = make_shared<MapNode>("new_RL");
	new_L->right = new_LR;
	new_R->left = new_RL;
	shared_ptr<MapNode> new_End = make_shared<MapNode>("new_End");
	new_LL->right = new_End;
	new_LR->right = new_End;
	new_RL->left = new_End;
	new_RR->left = new_End;
	init();
}

void TreeMap::showmap()
{
	cout << "             " << root->IsThere() << "                      " << endl;
	cout << "            / \\                     " << endl;
	cout << "           " << root->left->IsThere() << "   " << root->right->IsThere() << "                     " << endl;
	cout << "          /\\  / \\                     " << endl;
	cout << "         " << root->left->left->IsThere() << "  " << root->left->right->IsThere() << " " << root->right->left->IsThere() << "  " << root->right->right->IsThere() << "                    " << endl;
	cout << "         \\  | |  /                   " << endl;
	cout << "          \\ | | /  " << endl;
	cout << "           \\| |/                    " << endl;
	cout << "             " << root->left->left->right->IsThere() << "                       " << endl;
}


char MapNode::IsThere()
{
	if (isthere == true)
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

void TreeMap::go(Role& character) {
	while (true)
	{
		if (now->getname() == "new_End") {
			cout << "��ϲ��ͨ������ͭ�ǵ����������ڽ��㴫�ͳ�С����.....";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			break;
		}
		now = now->goaway();
		if (now->getname() == "new_L") {
			cout << "�������˵���, �������¼���ѡ���������֣���" << endl;
			Role enemy("����", 10, 1, 1, 1, 1, 10, 1);
			while (true)
			{
				cout << "1. �鿴������Ϣ 2. ����ս�� 3. �뿪" << endl;
				int foo = 0; // ����ѭ���Ƿ����
				int choice = 0;
				cin >> choice;
				switch (choice)
				{
				case 1:
					enemy.showrole();
					break;
				case 2:
					if (fight(character, enemy)) {
						foo = 1;
					}
					break;
				case 3:
					foo = 1;
					break;
				default:
					cout << "����" << endl;
					break;
				}
				if (foo) {
					break;
				}
			}
		}
		showmap();
	}
}
