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
		if (_kbhit()) { // ����Ƿ��м�������
			char key = _getch(); // ��ȡ���������ַ�

			if (key == 16) { // 16 ��Ctrl��ASCII��
				ctrlPressed = true;
			}
			else if (ctrlPressed && key == 112) { // 112 ��P��ASCII��
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

	// ����������Χ
	int min = 2;
	int max = 4;

	// ����һ�������ֲ�����
	std::uniform_int_distribution<> dist(min, max);

	// ����������������
	int randomNumber = dist(gen);
	for (int i = 0; i < randomNumber; i++) {
		index = 0;
		
		while (index < sentence.length()) {
			std::cout << sentence[index++];
			std::cout.flush();//�����������������ַ�
			std::this_thread::sleep_for(std::chrono::milliseconds(200));//ʹ����ֹͣ50ms
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // ��ʱ50����
		std::cout << "\b\b\b\b\b";
		for (int i = 0; i < 5; i++) {
			std::cout << " "; // ����ո񸲸�֮ǰ�����"....."
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
		cout << "1. Ѱ��NPC 2. ��������ͼ�� 3. �˳���ͼ 4. ����ѧԺ 5. ������ҳ" << endl;
	}
	else {
		cout << "1. Ѱ��NPC 2. ��������ͼ�� 3. �˳���ͼ 4. ������ҳ" << endl;
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
			cout << "���ڽ���С����";
			print();
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			School_Map school_map;
			school_map.move(character);
		}
		else if(map.GetPosition() == 1)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "���ڽ���С����";
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
		cout << "�����~~������" << endl;
		break;
	}
	return true;
}

void show1() { cout << "choice1\n"; }
void show2() { cout << "choice2\n"; }


//
// // ����������������߳�


int main() {
	std::thread keyboardThread1;
	PlaySound(L"daoguang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	welcomePage();
	loading();
	PlaySound(NULL, 0, SND_PURGE);
	PlaySound(L"kaichang.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	introduce();

	for (int i = 0; i < 2; i++) {
		std::cout << ""; // ����ո񸲸�֮ǰ�����"....."
	}
	std::cout << "\b\b";
	//this_thread::sleep_for(std::chrono::seconds(20));
	 //��ʼ��������Ϣ
	string name;
	cout << "������ݣ�";

	cin >> name;
	Role character(name, 100, 10, 10, 10, 1, 0, 1);
	//save(character,Skill_vector,skillData,bag);
	save(character);
	character.showrole();
	PlaySound(NULL, 0, SND_PURGE);
	// ��ʼ����ͼ
	PlaySound(L"lhh.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	PlaySound(NULL, 0, SND_PURGE);
	PlaySound(L"welcome.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	PlaySound(NULL, 0, SND_PURGE);
	cout << "��ӭ���������ش�½" << endl;
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
