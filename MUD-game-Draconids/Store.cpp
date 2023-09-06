#include <iostream>
#include <string>
#include <vector>
#include<iomanip>
#include "Store.h"

using namespace std;

Store::Store()
{
	for (int i = 0; i < 24; ++i)
	{
		stores.insert(pair<int, int>(i, 999));//�̵���Ʒ��ʼ�� ����Ϊ999
	}

}

Store::~Store()
{
}

void Store::showStores()
{
	cout << left << setw(17) << "��ƷID" << setw(76) << "����" << "�۸�" << endl;
	map<int, int>::iterator iter;
	int i = 0;//��Ʒ���
	for (iter = stores.begin(); iter != stores.end(); ++iter)
	{
		cout << left << setw(2) << i << "." << setw(10) << goods[iter->first].getName() << "   "
			<< setw(76) << goods[iter->first].getDesc() << "   "
			<< goods[iter->first].getPriceBuy() << endl;
		if (getType() == 0) cout << "  �����ӳɣ�" << goods[iter->first].getAddAttack() << "  " << "�����ӳɣ�" << goods[iter->first].getAddDefend() << "  " << "���ݼӳɣ�" << goods[iter->first].getAddAPI() << endl;
		else if (getType() == 1) cout << "  Ѫ���ӳɣ�" << goods[iter->first].getAddMaxHP() << "  " << "�����ӳɣ�" << goods[iter->first].getAddDefend() << "  " << "���ݼӳɣ�" << goods[iter->first].getAddAPI() << endl;
		else
			cout << "  �ָ�Ѫ��" << goods[iter->first].getAddMP();
		++i;//��Ʒ���
	}
}

Role Store::storeToPlayer(Role player)
{
	int goodsId, goodsNum;
	cout << "22.�˳�" << endl;
	cout << "������Ҫ�������ƷID��" << endl;
	cin >> goodsId;
	if (goodsId == 22) return player;
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
	if (player.subGoodsToBag(goodsId, goodsNum)) {
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
