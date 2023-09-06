#include"Map.h"
Map::Map():pos(1)
{
	search_map.insert(pair<string, int>("卡塞尔学院", 0));
	search_map.insert(pair<string, int>("青铜城", 1));
	search_map.insert(pair<string, int>("北京", 2));
	search_map.insert(pair<string, int>("日本", 3));
	search_map.insert(pair<string, int>("俄罗斯", 4));
	search_map.insert(pair<string, int>("北极", 5));
	search_map.insert(pair<string, int>("仕兰中学", 6));
	search_map.insert(pair<string, int>("巴西", 7));


	string name1 = "火云邪神";
	vector<string>task1 = { "我....我是谁","我是令人闻风丧胆的天下第一杀人魔火云邪神","但是....我败了","一个混血龙族,那么轻易的战胜了我.",
	"你愿意帮我复仇吗","这是我最后的愿望了"
	};
	string conversation1 = "我...输了";
	Npc npc5(name1, task1, conversation1, 6);//火云邪神在仕兰中学

	string name2 = "美国队长";
	vector<string>task2 = { "勇者,我们遇上大麻烦了","一条龙出现在市中心,造成了极大的破坏,我与巴基奉命去击败他,它被我们击退了",
		"但是那条龙带有剧毒,巴基被那条龙弄伤了","现在只有它的血才能救巴基",
	"我希望得到你的帮助,去得到那条翡翠绿龙的血","勇者,快去快回,巴基撑不了多久了" };
	string conversation2 = "on your left";
	Npc npc4(name2, task2, conversation2, 5);//美国队长在北极

	string name3 = "大古";
	vector<string>task3 = { "我是大古,是地球和平联盟TPC的GUTS小队队员","同时,我也是迪迦奥特曼","曾经丽娜对我说:难道奥特曼就有义务一个人承担起保护地球的责任么?",
	"现在我这句话也是你想知道的了:这不是义务，因为我是人，我只是在做我能做的事。" ,"去做你能做的事情吧,身为一个人能做的事."
	};
	string conversation3 = "根本赢不了？我听不懂。";
	Npc npc2(name3, task3, conversation3, 3);//大古在日本

	string name4 = "希尔伯特·让·昂热";
	vector<string>task4 = { "我要找到龙王们的故宫，把他们捆在里面，在那些青铜、岩石、水下或者浮在天空里的宫殿里都塞上一枚核弹然后同时引爆,",
		"我坐在那根钉死白王的铜柱上看这群爬行类的世界覆灭，大火像雨一样从天空里洒下来。","孩子,青铜城,去吧","为了人类的荣耀" };
	string conversation4 = "历史就是钢铁的车轮，总有些人垫在车轮下，对于个人是悲剧，对于历史则是必然.";
	Npc npc1(name4, task4, conversation4, 2);//昂热在北京

	string name5 = "守夜人";
	vector<string>task5 = { "神话中‘诸神的黄昏’，黑龙复活，从死人之国来的军队和恶魔们一起发动对生者的战争,",
		"玛雅文化说2012年第五个太阳纪的尽头，将不再有新的纪元，因为一切彻底结束",
	"佛教神话说三场巨大的灾难之后，三界之中，自无间地狱至第三禅天，全部毁灭，一切如尘埃飘散。"
	,"但是我不相信,人类一定有办法拯救自身的,哪怕是龙王也不能阻止。",
	"找到神话之书,找寻真相吧。" };
	string conversation5 = "我自己也是老怪物。";
	Npc npc3(name5, task5, conversation5, 4);//守夜人在俄罗斯 

	shared_ptr<Npc> npc1_ptr = make_shared<Npc>(npc1);
	allnpc.push_back(npc1_ptr);
	//searchNPC_map.insert(pair<string, int>("北京", 0));
	shared_ptr<Npc> npc2_ptr = make_shared<Npc>(npc2);
	allnpc.push_back(npc2_ptr);
	//searchNPC_map.insert(pair<string, int>("日本", 1));
	shared_ptr<Npc> npc3_ptr = make_shared<Npc>(npc3);
	allnpc.push_back(npc3_ptr);
	//searchNPC_map.insert(pair<string, int>("俄罗斯", 2));
	shared_ptr<Npc> npc4_ptr = make_shared<Npc>(npc4);
	allnpc.push_back(npc4_ptr);
	//searchNPC_map.insert(pair<string, int>("北极", 3));
	shared_ptr<Npc> npc5_ptr = make_shared<Npc>(npc5);
	allnpc.push_back(npc5_ptr);
	//searchNPC_map.insert(pair<string, int>("仕兰中学", 4));
}
Map::~Map() {

}
void Map::ShowMap()
{
	cout << "          " << isthere(5) << "北极" << endl;
	cout << "             |  " << endl;
	cout << "             |   " << endl;
	cout << "         " << isthere(4) << "俄罗斯" << endl;
	cout << "        /       \\   " << endl;
	cout << "       /         \\   " << endl;
	cout << "      /           \\" << endl;
	cout << "   " << isthere(2) << "北京\t  " << isthere(6) << "日本" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  " << isthere(1) << posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "" << isthere(4) << "仕兰中学 \t   " << isthere(7) << "巴西" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t" << isthere(0) << "卡塞尔学院" << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}

string Map::move() {//根据输入地点来到不同位置,若输入错误,退出函数重新输入
	while (1)
	{
		ShowMap();
		cout << "请输入前往位置:" << endl;
		string str;
		cin >> str;
		unordered_map<string, int>::iterator it = search_map.find(posname[pos]);
		if (it != search_map.end()) {
			pos = (*it).second;
			cout << "当前来到" << str << endl;
			return str;
		}
		else  cout << "该地点不存在,请重新输入" << endl;
	}

}

char Map::isthere(int a)
{
	if (pos == a)
		return'*';
	return ' ';
}

void Map::Map_find()//在map中查找npc
{

	if (searchNPC_map[pos])
		allnpc[pos - 1]->GetTask();
	/*cout << "当前地图存在Npc:" << allnpc[(*it).second]->GetName();
	if (it != searchNPC_map.end())
	{
		cout << ",是否与其对话?" << endl;
		cout << "请输入Y/N" << endl;
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
	cout << " |         教室        |       训练室       |" << endl;
	cout << " |          " << isthere(0, 0) << "          |    " << isthere(0, 1) << "\t\t    | " << endl;
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

void School_Map::move()//移动输入wasd,e退出 如果超出位置,只能在此地呆着
{
	showmap();
	while (true) {
		cout << "输入wasd移动,输入e退出" << endl;
		char action;
		cin >> action;
		if (pos[0] == 0 && action == 'w' || pos[0] == 2 && action == 's'
			||
			pos[1] == 0 && action == 'a' || pos[1] == 1 && action == 'd')
		{
			cout << "输入有误,请重新输入." << endl;
		}
		if (action == 'w')
			pos[0]++;
		else if (action == 's')
			pos[0]--;
		else if (action == 'a')
			pos[1]--;
		else if (action == 'd')
			pos[1]++;
		else return;
	}


}



MapNode::MapNode()
	:left(nullptr), right(nullptr), role(nullptr) {}
MapNode::MapNode(unique_ptr<Role>& role, shared_ptr<MapNode> left, shared_ptr<MapNode> right)
	:role(move(role)), left(left), right(right)
{

}
//TreeMap::TreeMap()
//:root(nullptr),now(nullptr){}
TreeMap::TreeMap(shared_ptr<MapNode> root)
	:root(root), now(root)
{
	shared_ptr<MapNode> new_L = make_shared<MapNode>();
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
	if (isthere)
		return '*';
	else
		return'0';
}

shared_ptr<MapNode> MapNode::goaway()//离开时调用
{
	cout << "请输入L\\R离开:" << endl;
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
			cout << "输入有误,请重新输入" << endl;
	} while (1);
}