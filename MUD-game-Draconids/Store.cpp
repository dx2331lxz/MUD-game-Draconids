#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "Store.h"
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

using namespace std;

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
	for (int i = 0; i < 22; ++i)
	{
		stores.insert(pair<int, int>(i, 999));//商店物品初始化 数量为999
	}

}

Store::~Store()
{
}

//void Store::showStores()
//{
//	cout << left << setw(17) << "物品ID" << setw(76) << "描述" << "价格" << endl;
//	map<int, int>::iterator iter;
//	int i = 0;//物品序号
//	for (iter = stores.begin(); iter != stores.end(); ++iter)
//	{
//		cout << left << setw(2) << i << "." << setw(10) << goods[iter->first].getName() << "   "
//			<< setw(76) << goods[iter->first].getDesc() << "   "
//			<< goods[iter->first].getPriceBuy() << endl;
//		if (goods[iter->first].getType() == 0) cout << "  攻击加成：" << goods[iter->first].getAddAttack() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
//		else if (goods[iter->first].getType() == 1) cout << "  血量加成：" << goods[iter->first].getAddMaxHP() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
//		else
//			cout << "  恢复血量" << goods[iter->first].getAddHP();
//		++i;//物品序号
//	}
//}
void Store::showStores() {
	bool exitProgram = false; // 控制程序是否退出
	SetConsoleMode(hInput, ENABLE_MOUSE_INPUT);
	while (!exitProgram) {
		system("cls");
		cout << left << setw(17) << "物品ID" << setw(76) << left << "描述" << " 价格" << endl;
		map<int, int>::iterator iter;
		int i = 0;//物品序号
		for (iter = stores.begin(); iter != stores.end(); ++iter)
		{
			cout << left << setw(2) << i + 1 << "." << setw(10) << goods[iter->first].getName() << "   " << setw(76) << goods[iter->first].getDesc() << "   " << goods[iter->first].getPriceBuy() << endl;
			++i;//物品序号
		}
		cout << "22.退出" << endl;
		//----------移除快速编辑模式(对于win10用户)----------
		CloseQuickEditMode();
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		DWORD prevMode;
		GetConsoleMode(hInput, &prevMode);
		

		INPUT_RECORD inputBuffer;
		DWORD eventsRead;

		//----------循环检测----------
		while (true) {
			ReadConsoleInput(hInput, &inputBuffer, 1, &eventsRead);
			if (inputBuffer.EventType == MOUSE_EVENT) {
				int mouseX = inputBuffer.Event.MouseEvent.dwMousePosition.X;
				int mouseY = inputBuffer.Event.MouseEvent.dwMousePosition.Y;
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
		iter[4];
		for (int Y = 顶部下坐标; iter != stores.end(); ++iter) {
			if (y < Y) break;
			Y + 行间距;
		}
		if (iter == stores.end()) return false;
		else{
			system("cls");
			cout << left << goods[iter->first].getName() << endl;
			cout << goods[iter->first].getDesc() << endl;
			cout << goods[iter->first].getPriceBuy() << endl;
			if (goods[iter->first].getType() == 0) cout << "  攻击加成：" << goods[iter->first].getAddAttack() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
			else if (goods[iter->first].getType() == 1) cout << "  血量加成：" << goods[iter->first].getAddMaxHP() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
			else
				cout << "  恢复血量" << goods[iter->first].getAddHP();
			cout << "右键退出商品详细显示界面"
				if (KEY_DOWN(VK_RBUTTON)) return true;
		}
}

Role Store::storeToPlayer(Role player){
	int goodsId, goodsNum;
	cout << "请输入要购买的物品ID号" << endl;
	cin >> goodsId;
	if (goodsId == 22) return player;
	cout << "请输入要购买的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	int totalPrice = int(goods[goodsId].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= totalPrice)
	{
		player.addGoodsToBag(goodsId, goodsNum);
		player.setMoney(player.getMoney() - totalPrice);
		cout << "购买成功" << endl;
		cout << "获得 " << goods[goodsId].getName() << " * " << goodsNum;
	}
	else
	{
		cout << "金钱不足,购买失败" << endl;
	}
	return player;
}

Role Store::playerToStore(Role player)
{
	int goodsId, goodsNum;
	cout << "请输入要卖出的物品ID(输入22退出)" << endl;
	cin >> goodsId;
	if (goodsId == 22) return player;
	cout << "请输入要卖出的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return player;
	if (player.subGood00sToBag(goodsId, goodsNum)) {
		int totalPrice = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + totalPrice);
		cout << "出售成功" << endl;
		cout << "获得金钱:" << totalPrice << endl;
	}
	else {
		cout << "无此物品，出售失败！" << endl;
	}
	return player;
}
