#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "Store.h"
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //������ⰴ���ĵ���¼�

void CloseQuickEditMode()
{
	HANDLE hIn;
	unsigned long mode;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hIn, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	SetConsoleMode(hIn, mode);
}

Store::Store()
{
	for (int i = 0; i < 14; ++i)
	{
		stores.insert(pair<int, int>(i, 999));//�̵���Ʒ��ʼ�� ����Ϊ999
	}

}

Store::~Store()
{
}

//void Store::showStores()
//{
//	cout << left << setw(17) << "��ƷID" << setw(76) << left << "����" << " �۸�" << endl;
//	map<int, int>::iterator iter;
//	int i = 0;//��Ʒ���
//	for (iter = stores.begin(); iter != stores.end(); ++iter)
//	{
//		cout <<left<<setw(2) <<i << "." <<setw(10)<< goods[iter->first].getName() << "   "
//			<<setw(76)<< goods[iter->first].getDesc() << "   "
//			<< goods[iter->first].getPriceBuy() << endl;
//
//		++i;//��Ʒ���
//	}
//}
void Store::showStores() {
	system("cls");
	bool exitProgram = false; // ���Ƴ����Ƿ��˳�
	//----------�Ƴ����ٱ༭ģʽ(����win10�û�)----------
	CloseQuickEditMode();
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prevMode;
	GetConsoleMode(hInput, &prevMode);
	SetConsoleMode(hInput, ENABLE_MOUSE_INPUT);

	INPUT_RECORD inputBuffer;
	DWORD eventsRead;
	while (!exitProgram) {

		cout << left << setw(17) << "��ƷID" << setw(76) << left << "����" << " �۸�" << endl;
		map<int, int>::iterator iter;
		int i = 0;//��Ʒ���
		for (iter = stores.begin(); iter != stores.end(); ++iter)
		{
			cout << left << setw(2) << i + 1 << "." << setw(30) << left << goods[iter->first].getName() << setw(80) << left << goods[iter->first].getDesc() << goods[iter->first].getPriceBuy() << endl;
			++i;//��Ʒ���
		}
		cout << "15.�˳�" << endl;
		int mouseY;
		//----------ѭ�����----------
		while (true) {
			ReadConsoleInput(hInput, &inputBuffer, 1, &eventsRead);
			if (inputBuffer.EventType == MOUSE_EVENT && inputBuffer.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
				mouseY = inputBuffer.Event.MouseEvent.dwMousePosition.Y;
			}
			if (showProductDetails(y)) {
				exitProgram = true;
				break;
			}
		}
		sleep(20);
	}
	SetConsoleMode(hInput, prevMode);
}

bool Store::showProductDetails(int y) {
		map<int, int>::iterator iter = stores.begin();
		for (int Y = 1; iter != stores.end(); ++iter) {
			if (y < Y) break;
			Y ++;
		}
		if (iter == stores.end()) return false;
		else{
			system("cls");
			cout << left << goods[iter->first].getName() << endl;
			cout << goods[iter->first].getDesc() << endl;
			cout << goods[iter->first].getPriceBuy() << endl;
			if (goods[iter->first].getType() == 0) cout << "  �����ӳɣ�" << goods[iter->first].getAddAttack() << "  " << "�����ӳɣ�" << goods[iter->first].getAddDefend() << "  " << "���ݼӳɣ�" << goods[iter->first].getAddAGI() << endl;
			else if (goods[iter->first].getType() == 1) cout << "  Ѫ���ӳɣ�" << goods[iter->first].getAddMaxHP() << "  " << "�����ӳɣ�" << goods[iter->first].getAddDefend() << "  " << "���ݼӳɣ�" << goods[iter->first].getAddAGI() << endl;
			else
				cout << "  �ָ�Ѫ��" << goods[iter->first].getAddHP();
			cout << "�Ҽ��˳���Ʒ��ϸ��ʾ����"
				if (KEY_DOWN(VK_RBUTTON)) return true;
		}
}

Role Store::storeToPlayer(Role player){
	int goodsId, goodsNum;
	cout << "������Ҫ�������ƷID��" << endl;
	cin >> goodsId;
	if (goodsId == 15) return player;
	cout << "������Ҫ���������(����0�˳�)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	int totalPrice = int(goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= totalPrice)
	{
		player.addGoodsToBag(goodsId, goodsNum);
		player.setMoney(player.getMoney() - totalPrice);
		cout << "����ɹ�" << endl;
		cout << "��� " << goods[goodsId].getName() << " * " << goodsNum;
	}
	else
	{
		cout << "��Ǯ����,����ʧ��" << endl;
	}
	return player;
}

Role Store::playerToStore(Role player)
{
	int goodsId, goodsNum;
	cout << "������Ҫ��������ƷID(����22�˳�)" << endl;
	cin >> goodsId;
	if (goodsId == 22) return player;
	cout << "������Ҫ����������(����0�˳�)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	if (player.subGood00sToBag(goodsId, goodsNum)) {
		int totalPrice = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + totalPrice);
		cout << "���۳ɹ�" << endl;
		cout << "��ý�Ǯ:" << totalPrice << endl;
	}
	else {
		cout << "�޴���Ʒ������ʧ�ܣ�" << endl;
	}
	return player;
}
