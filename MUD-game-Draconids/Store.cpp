#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "Store.h"
#include <Windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

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
		stores.insert(pair<int, int>(i, 999));//商店物品初始化 数量为999
	}

}

Store::~Store()
{
}

void Store::showStores() {
	system("cls");
	bool exitProgram = false; // 控制程序是否退出
	//----------移除快速编辑模式(对于win10用户)----------
	CloseQuickEditMode();
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prevMode;
	GetConsoleMode(hInput, &prevMode);
	SetConsoleMode(hInput, ENABLE_MOUSE_INPUT);

	INPUT_RECORD inputBuffer;
	DWORD eventsRead;

	bool canHandleLeftClick = true;
	bool choice = true;
	cout << left << setw(32) << "物品ID" << setw(80) << left << "描述" << " 价格" << endl;
	map<int, int>::iterator iter;
	int i = 0;//物品序号
	for (iter = stores.begin(); iter != stores.end(); ++iter)
	{
		cout << left << setw(2) << i + 1 << "." << setw(30) << left << goods[iter->first].getName() << setw(80) << left << goods[iter->first].getDesc() << goods[iter->first].getPriceBuy() << endl;
		++i;//物品序号
	}
	cout << "购买(输入15退出购买界面）" << endl;
	canHandleLeftClick = true; // 重置为 true，以允许处理左键事件
	//----------循环检测----------
	while (true) {
		ReadConsoleInput(hInput, &inputBuffer, 1, &eventsRead);
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
			int MouseY = inputBuffer.Event.MouseEvent.dwMousePosition.Y;
			if (MouseY > 14) {
				SetConsoleMode(hInput, prevMode);
				return;
			}
				
			else if (canHandleLeftClick) {
				showProductDetails(MouseY);
				canHandleLeftClick = false;
			}		
			break;
		}
	}
	SetConsoleMode(hInput, prevMode);
	showStores();
}


bool Store::showProductDetails(int y) {
	map<int, int>::iterator iter = stores.begin();
	for (int Y = 1; iter != stores.end(); ++iter) {
		if (y <= Y) break;
		Y++;
	}
	if (iter == stores.end()) return false;
	else {
		system("cls");
		cout << left << goods[iter->first].getName() << endl;
		cout << goods[iter->first].getDesc() << endl;
		cout << "价格  :" << goods[iter->first].getPriceBuy() << endl;
		if (goods[iter->first].getType() == 0) cout << "攻击加成：" << goods[iter->first].getAddAttack() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
		else if (goods[iter->first].getType() == 1) cout << "血量加成：" << goods[iter->first].getAddMaxHP() << "  " << "防御加成：" << goods[iter->first].getAddDefend() << "  " << "敏捷加成：" << goods[iter->first].getAddAGI() << endl;
		else
			cout << "恢复血量:" << goods[iter->first].getAddHP() << endl;
		cout << endl;
		cout << "按鼠标右键退出商品详细显示界面";
		while (true) {
			if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
				system("cls");
				return true;
			}
		}
	}
}

void Store::storeToPlayer(Role &player) {
	int goodsId, goodsNum;
	cout << "持有财产：" << player.getMoney()<<endl;
	cout << "请输入要购买的物品ID号" << endl;
	cin >> goodsId;
	if (goodsId >14 ) return;
	cout << "请输入要购买的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return;
	int totalPrice = int(goods[goodsId-1].getPriceBuy()) * int(goodsNum);
	if (player.getMoney() >= totalPrice)
	{
		player.addGoodsToBag(goodsId-1, goodsNum);
		player.setMoney(player.getMoney() - totalPrice);
		cout << "购买成功" << endl;
		cout << "获得 " << goods[goodsId-1].getName() << " * " << goodsNum<<endl;
	}
	else
	{
		cout << "金钱不足,购买失败" << endl;
	}
	return ;
}

void Store::playerToStore(Role &player)
{
	int goodsId, goodsNum;
	cout << "请输入要卖出的物品ID(输入15退出)" << endl;
	cin >> goodsId;
	if (goodsId >14 ) return ;
	cout << "请输入要卖出的数量(输入0退出)" << endl;
	cin >> goodsNum;
	if (goodsNum == 0) return ;
	if (player.subGoodsToBag(goodsId, goodsNum)) {
		int totalPrice = int(goods[goodsId].getPriceSell()) * int(goodsNum);

		player.setMoney(player.getMoney() + totalPrice);
		cout << "出售成功" << endl;
		cout << "获得金钱:" << totalPrice << endl;
	}
	else {
		cout << "无此物品，出售失败！" << endl;
	}
	return ;
}
