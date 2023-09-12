#include"main.h"
#include <string>

//int main()
//{
//    welcomePage();
//	shared_ptr<MapNode> root=make_shared< MapNode>();
//	
//	TreeMap map(root);
//
//	map.showmap();
//	system("pause");
//
//	return 0;
//}

bool ctrlPressed = false;
bool pPressed = false;


void KeyboardInputThread(Role& character) {
	while (true) {
		if (_kbhit()) { // 检查是否有键盘输入
			char key = _getch(); // 获取键盘输入字符

			if (key == 16) { // 16 是Ctrl的ASCII码
				ctrlPressed = true;
			}
			else if (ctrlPressed && key == 112) { // 112 是P的ASCII码
				pPressed = true;
			}
			else {
				ctrlPressed = false;
				pPressed = false;
			}

			if (ctrlPressed && pPressed) {
				menu(character);
				ctrlPressed = false;
				pPressed = false;
			}
		}
	}
}



void print() {
	string sentence = ".....";
	int index = 0;
	std::random_device rd;
	std::mt19937 gen(rd());

	// 定义整数范围
	int min = 2;
	int max = 4;

	// 创建一个整数分布对象
	std::uniform_int_distribution<> dist(min, max);

	// 生成随机整数并输出
	int randomNumber = dist(gen);
	for (int i = 0; i < randomNumber; i++) {
		index = 0;
		
		while (index < sentence.length()) {
			std::cout << sentence[index++];
			std::cout.flush();//立刻输出缓冲区里的字符
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//使程序停止50ms
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 延时50毫秒
		std::cout << "\b\b\b\b\b";
		for (int i = 0; i < 5; i++) {
			std::cout << " "; // 输出空格覆盖之前输出的"....."
		}
		std::cout << "\b\b\b\b\b";
	}
}


void fight(Role& character, Role& enemy) {
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
	fight.endFight();
}

int choose(Map& map, Role & character) {
	
	if (map.GetPosition() == 0 || map.GetPosition() == 1) {
		cout << "1. 寻找NPC 2. 传送至地图别处 3. 退出地图 4. 进入学院 5. 个人主页" << endl;
	}
	else {
		cout << "1. 寻找NPC 2. 传送至地图别处 3. 退出地图 4. 个人主页" << endl;
	}
	int i;
	cin >> i;
	switch (i)
	{
	case 1: {
		map.Map_find();
		break;
	}
	case 2: {
		map.move();
		map.ShowMap();
		break;
	}
	case 3:
		return false;
	case 4: {
		if (map.GetPosition() == 0) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "正在进入小世界";
			print();
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			School_Map school_map;
			school_map.move(character);
		}
		else if(map.GetPosition() == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "正在进入小世界";
			print();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			TreeMap treemap;
			treemap.showmap();
			treemap.go(character);
		}
		else {
			menu(character);
		}
		break;
	}
	case 5:
		menu(character);
		break;
	default:
		cout << "你干嘛~~，诶呦" << endl;
		break;
	}
	return true;
}

void show1() { cout << "choice1\n"; }
void show2() { cout << "choice2\n"; }


//
// // 启动检测键盘输入的线程


int main() {
	std::thread keyboardThread1;
	PlaySound(L"daoguang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	welcomePage();
	loading();
	PlaySound(NULL, 0, SND_PURGE);
	PlaySound(L"kaichang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	introduce();

	for (int i = 0; i < 2; i++) {
		std::cout << ""; // 输出空格覆盖之前输出的"....."
	}
	std::cout << "\b\b";
	//this_thread::sleep_for(std::chrono::seconds(20));
	 //初始化人物信息
	string name;
	cout << "输入身份：";

	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	character.showrole();
	PlaySound(NULL, 0, SND_PURGE);
	// 初始化地图
	PlaySound(L"daoguang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << "欢迎来到 ****" << endl;
	cout << endl;
	Map map;
	map.ShowMap();
	cout << endl;
	while (true)
	{
		if (!choose(map, character)) {
			break;
		}
	}

	return 0;
}
