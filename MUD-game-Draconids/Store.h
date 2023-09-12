#ifndef STORE_H
#define STORE_H

#include <iostream>  
#include <map>  
#include "Goods.h"
#include "Bag.h"
#include "Role.h"

using namespace std;

class Store {
public:
	Store();
	~Store();

	void showStores();
	void storeToPlayer(Role &player);		//����һ���Ѿ��������ı���
	void playerToStore(Role &player);
	bool showProductDetails(int i);

private:
	map<int, int> stores;

	//��Ʒʵ����
	Goods goods[14] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13};
};
#endif
