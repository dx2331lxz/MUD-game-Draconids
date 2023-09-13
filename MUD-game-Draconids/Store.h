#pragma once

#include"main.h"

using namespace std;

class Store {
public:
	Store();
	~Store();

	void showStores();						//��ʾ��Ʒ�б�ʵ��������
	void storeToPlayer(Role &player);		
	void playerToStore(Role &player);
	bool showProductDetails(int i);			//�����Ӧ����Ʒ����ҳ

private:
	map<int, int> stores;

	//��Ʒʵ����
	Goods goods[14] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13};
};

