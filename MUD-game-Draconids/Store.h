#pragma once

#include"main.h"

using namespace std;

class Store {
public:
	Store();
	~Store();

	void showStores();						//显示商品列表并实现鼠标操作
	void storeToPlayer(Role &player);		
	void playerToStore(Role &player);
	bool showProductDetails(int i);			//进入对应的商品详情页

private:
	map<int, int> stores;

	//物品实例化
	Goods goods[14] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13};
};

