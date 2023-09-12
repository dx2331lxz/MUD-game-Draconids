#include"Map.h"
Map::Map():pos(0)
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
	cout << "   " << isthere(2) << "北京\t  " << isthere(3) << "日本" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  " << isthere(1) << posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "" << isthere(6) << "仕兰中学 \t   " << isthere(7) << "巴西" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t" << isthere(0) << "卡塞尔学院" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "*表示您当前的位置" << endl;
}

string Map::move() {//根据输入地点来到不同位置,若输入错误,退出函数重新输入
	while (1)
	{
		ShowMap();
		cout << "请输入前往位置:" << endl;
		string str;
		cin >> str;
		unordered_map<string, int>::iterator it = search_map.find(str);
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

//void Map::Map_find()//在map中查找npc
//{
//	if (pos == 0) {
//		cout << "*****" << endl;
//	}
//
//	if (searchNPC_map[pos])
//		allnpc[pos - 2]->GetTask();
//	/*cout << "当前地图存在Npc:" << allnpc[(*it).second]->GetName();
//	if (it != searchNPC_map.end())
//	{
//		cout << ",是否与其对话?" << endl;
//		cout << "请输入Y/N" << endl;
//		char choice;
//		cin >> choice;
//		if (choice == 'Y')
//			allnpc[(*it).second]->GetTask();
//	}*/
//
//
//}
void Map::Map_find()//在map中查找npc
{
	if (pos == 0) {
		
		cout << "找到npc，姓名为：零" << endl;
		cout << "学院任务,前往青铜城,斩杀复苏龙族。" << endl;
		PlaySound(L"NPC1.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		std::this_thread::sleep_for(std::chrono::seconds(7));
		PlaySound(NULL, 0, SND_PURGE);
	}


	if (searchNPC_map[pos]) {
		cout << "找到npc，姓名为：" << allnpc[pos - 2]->GetName() << endl;
		while (1) {
			cout << "选项：talk" << endl;
			cout << "选项：task" << endl;
			cout << "选项：leave" << endl;
			cout << "请输入选项：" << endl;

			string choice;
			cin >> choice;
			if (choice == "talk")
				allnpc[pos - 2]->conversation();
			else if (choice == "task")
				allnpc[pos - 2]->GetTask();
			else if (choice == "leave")
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		}
	}

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

void School_Map::move(Role& character)//移动输入wasd,e退出 如果超出位置,只能在此地呆着
{
	Role enemy("怪兽", 10, 1, 1, 1, 1, 10, 1);
	while (true) {
		system("cls");
		cout << "鼠标左键选择进入房间，鼠标右键退出选择界面" << endl;
		Sleep(1000);
		if (!school_map_show()) {
			system("cls");
			break;
		}
		
		/*showmap();
		cout << "输入wasd移动,输入e退出" << endl;
		char action;
		cin >> action;
		if (pos[0] == 0 && action == 'w' || pos[0] == 2 && action == 's'
			||
			pos[1] == 0 && action == 'a' || pos[1] == 1 && action == 'd')
		{
			cout << "输入有误,请重新输入." << endl;
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
		}*/
		if ((pos[0]==2&&pos[1]==0) && (enemy.getHP() != 0)) {
			system("cls");
			cout << "你遇到了敌人, 你有以下几种选择（输入数字）：" << endl;
			while (true)
			{
				cout << "1. 查看敌人信息 2. 与他战斗 3. 离开" << endl;
				int foo = 0; // 决定循环是否结束
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
					cout << "别闹"<< endl;
					break;
				}
				if (foo) {
					break;
				}
			}
			
		}
		else if (pos[0] == 1 && pos[1] == 1) {

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



void TreeMap::go(Role& character) {
	while (true)
	{
		if (now->getname() == "new_End") {
			cout << "恭喜你通过了青铜城的试炼，正在将你传送出小世界";
			print();
			cout << endl;
			break;
		}
		now = now->goaway();
		if (now->getname() == "new_L") {
			cout << "你遇到了敌人, 你有以下几种选择（输入数字）：" << endl;
			Role enemy("凯撒", 10, 1, 1, 1, 1, 10, 1);
			while (true)
			{
				cout << "1. 查看敌人信息 2. 与他战斗 3. 离开" << endl;
				int foo = 0; // 决定循环是否结束
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
					cout << "别闹" << endl;
					break;
				}
				if (foo) {
					break;
				}
			}
		}

		if (now->getname() == "new_RL") {
			cout << "你遇到了敌人, 你有以下几种选择（输入数字）：" << endl;
			Role enemy("阿巴巴怪", 10, 4, 1, 1, 1, 10, 1);
			while (true)
			{
				cout << "1. 查看敌人信息 2. 与他战斗 3. 离开" << endl;
				int foo = 0; // 决定循环是否结束
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
					cout << "别闹" << endl;
					break;
				}
				if (foo) {
					break;
				}
			}
		}

		if (now->getname() == "new_RR") {
			cout << "你遇到了敌人, 你有以下几种选择（输入数字）：" << endl;
			Role enemy("猩红石像", 18, 6, 3, 1, 1, 10, 1);
			while (true)
			{
				cout << "1. 查看敌人信息 2. 与他战斗 3. 离开" << endl;
				int foo = 0; // 决定循环是否结束
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
					cout << "别闹" << endl;
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


bool School_Map::school_map_show()
{
	initgraph(400, 480, EX_SHOWCONSOLE);
	IMAGE img;
	loadimage(&img, L"./school_map.png", 400, 480);
	putimage(0, 0, &img);
	//int pos[2] = { 0,0 };//school——map自带pos，进入成员方法后删除
	while (true) {
		wchar_t s1[] = L"教室";//宽字符，特殊编码
		wchar_t s2[] = L"训练室";
		wchar_t s3[] = L"地窖";
		wchar_t s4[] = L"装备库";
		wchar_t s5[] = L"休息室";
		wchar_t s6[] = L"图书馆";
		if (pos[0] == 0 && pos[1] == 0)
		{
			settextcolor(RED);
			outtextxy(80, 60, s1);
			settextcolor(WHITE);
		}

		else
			outtextxy(80, 60, s1);
		if (pos[0] == 0 && pos[1] == 1)
		{
			settextcolor(RED);
			outtextxy(280, 60, s2);
			settextcolor(WHITE);
		}
		else
			outtextxy(280, 60, s2);
		if (pos[0] == 1 && pos[1] == 0)
		{
			settextcolor(RED);
			outtextxy(80, 240, s3);
			settextcolor(WHITE);
		}

		else
			outtextxy(80, 240, s3);
		if (pos[0] == 1 && pos[1] == 1)
		{
			settextcolor(RED);
			outtextxy(280, 240, s4);
			settextcolor(WHITE);
		}

		else
			outtextxy(280, 240, s4);
		if (pos[0] == 2 && pos[1] == 0)
		{
			settextcolor(RED);
			outtextxy(80, 400, s5);
			settextcolor(WHITE);
		}
		else
			outtextxy(80, 400, s5);
		if (pos[0] == 2 && pos[1] == 1)
		{
			settextcolor(RED);
			outtextxy(280, 400, s6);
			settextcolor(WHITE);
		}
		else
			outtextxy(280, 400, s6);

		while (!MouseHit())  // 等待鼠标事件发生
		{
			// 在此处添加其他需要执行的代码
		}

		MOUSEMSG msg = GetMouseMsg();  // 获取鼠标消息
		while (msg.uMsg != WM_LBUTTONDOWN && msg.uMsg != WM_RBUTTONDOWN)
		{
			while (!MouseHit())  // 等待鼠标事件发生
			{
				// 在此处添加其他需要执行的代码
			}

			msg = GetMouseMsg();  // 获取鼠标消息
		}

		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 0 && msg.x <= 200 && msg.y >= 0 && msg.y <= 160) {
				pos[0] = 0;
				pos[1] = 0;
				closegraph();
				return true;
				;
			}
			else if (msg.x > 200 && msg.x <= 400 && msg.y >= 0 && msg.y <= 160) {

				pos[0] = 0;
				pos[1] = 1;
				closegraph();
				return true;
			}
			else if (msg.x >= 0 && msg.x <= 200 && msg.y > 160 && msg.y <= 320) {
				pos[0] = 1;
				pos[1] = 0;
				closegraph();
				return true;
			}
			else if (msg.x > 200 && msg.x <= 400 && msg.y > 160 && msg.y <= 320) {
				pos[0] = 1;
				pos[1] = 1;
				closegraph();
				return true;
			}
			else if (msg.x >= 0 && msg.x <= 200 && msg.y > 320 && msg.y <= 480) {
				pos[0] = 2;
				pos[1] = 0;
				closegraph();
				return true;
			}
			else {
				pos[0] = 2;
				pos[1] = 1;
				closegraph();
				return true;
			}
		default:
			closegraph();
			return false;
		}
	}
}
