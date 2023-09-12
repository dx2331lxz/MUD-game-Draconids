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
	int n = 0;
	std::random_device rd;
	std::mt19937 gen(rd());

	// 定义整数范围
	int min = 2;
	int max = 4;

	// 创建一个整数分布对象
	std::uniform_int_distribution<> dist(min, max);

	// 生成随机整数并输出
	int randomNumber = dist(gen);
	int index;
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
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
start:
	if (map.GetPosition() == 0 || map.GetPosition() == 1) {
		cout << "1. 寻找NPC 2. 传送至地图别处 3. 退出地图 4. 进入学院 5. 个人主页 7.背包 8.装备" << endl;
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
		else if (map.GetPosition() == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			PlaySound(L"daoxuan.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			cout << "正在进入小世界";
			print();
			cout << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			PlaySound(NULL, 0, SND_PURGE);
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
	case 7:
		system("cls");
		character.showBag();		//显示背包
		character.useDrug();		//是否使用药品
		cout << endl;
		cout << "输入1退出：";
		
		while(1){
			int exit1 = 0;
			cin >> exit1;
			if (exit1 == 1) {
				system("cls");
				break;
			}
		}
		goto start;
		break;
	case 8:
		system("cls");
		character.showEquip();
		cout << "1.更换装备		2.取下装备		3.退出" << endl;
		int choiceEquip;
		cin >> choiceEquip;
		if (choiceEquip == 1) {
			character.showBag();
			cout << "请选择要换上的装备(14.取消)" << endl;
			int id;
			cin >> id;
			if (id >= 14 || id < 0)
				goto start;
			character.wearEquip(id);
			character.getBag().reduceGoods(id, 1);
		}
		if (choiceEquip == 2) {
			cout << "请输入要换下的装备" << endl;
			cout << "1." << goods[character.getWeapon()].getName() << endl;
			cout << "2." << goods[character.getClothes()].getName() << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				character.removeEquip(character.getWeapon());
				character.getBag().addGoods(character.getWeapon(), 1);
			}
			if (choice == 2)
			{
				character.removeEquip(character.getClothes());
				character.getBag().addGoods(character.getClothes(), 1);
			}
		}
		if (choiceEquip == 3)
			system("cls");
			goto start;
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
	int startChoose = 0;
	std::cin >> startChoose;
	PlaySound(NULL, 0, SND_PURGE);
	loading();

	//this_thread::sleep_for(std::chrono::seconds(20));
	 //初始化人物信息



	if (startChoose == 1) {



		// 建立新的存档，进入introduce，开始游戏

		PlaySound(L"kaichang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		introduce();

		for (int i = 0; i < 2; i++) {
			std::cout << ""; // 输出空格覆盖之前输出的"....."
		}
		std::cout << "\b\b";

		string name;
		cout << "输入身份：";

		cin >> name;
		Role character(name, 100, 10, 10, 10, 1, 0, 1);


		character.showrole();
		PlaySound(NULL, 0, SND_PURGE);
		// 初始化地图
		PlaySound(L"lhh.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		std::this_thread::sleep_for(std::chrono::seconds(3));
		PlaySound(NULL, 0, SND_PURGE);
		PlaySound(L"welcome.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		std::this_thread::sleep_for(std::chrono::seconds(4));
		PlaySound(NULL, 0, SND_PURGE);
		cout << "欢迎来到提瓦特大陆" << endl;
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
		save(character);
		return 0;
	}
	if (startChoose == 2) {

		Role character(load());

		ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);
		for (int key2 = 14; !fileBag.eof();) {

			int key;
			int value;
			fileBag >> key >> value;
			if (key2 == key)
				break;
			character.addSaveGoodsToBag(key, value);
			key2 = key;

		}
		fileBag.close();
		character.showrole();

		return 0;
	}
}