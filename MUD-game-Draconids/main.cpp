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
	Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };
start:
	if (map.GetPosition() == 0 || map.GetPosition() == 1) {
		cout << "1. Ѱ��NPC 2. ��������ͼ�� 3. �˳���ͼ 4. ����ѧԺ 5. ������ҳ 7.���� 8.װ��" << endl;
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
	case 7:
		system("cls");
		character.showBag();		//��ʾ����
		character.useDrug();		//�Ƿ�ʹ��ҩƷ
		cout << endl;
		cout << "����1�˳���";
		
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
		cout << "1.����װ��		2.ȡ��װ��		3.�˳�" << endl;
		int choiceEquip;
		cin >> choiceEquip;
		if (choiceEquip == 1) {
			character.showBag();
			cout << "��ѡ��Ҫ���ϵ�װ��(14.ȡ��)" << endl;
			int id;
			cin >> id;
			if (id >= 14 || id < 0)
				goto start;
			character.wearEquip(id);
			character.getBag().reduceGoods(id, 1);
		}
		if (choiceEquip == 2) {
			cout << "������Ҫ���µ�װ��" << endl;
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
	character.showrole();
	PlaySound(NULL, 0, SND_PURGE);
	// ��ʼ����ͼ
	cout << "��ӭ���� ****" << endl;
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
