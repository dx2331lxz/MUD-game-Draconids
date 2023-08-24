#ifndef GOODS_H
#define GOODS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Goods
{
public:
	Goods(int id);
	~Goods();

	string getName();
	int getGoodsId();
	string getDesc();
	int getDescd();
	int getType();
	int getAddAttack();
	int getAddAPI();
	int getAddDefend();
	int getAddHP();
	int getAddMaxHP();
	int getPriceSell();
	int getPriceBuy();
	void showGoods();

private:
	string name;	//��Ʒ����
	int goodsId;
	string desc;	//��Ʒ����
	int type;//��Ʒ���ԣ�����-0������-1��ҩƷ-2
	int addAttack = 0;	//���ӹ���
	int addAPI = 0;	//��������
	int addDefend = 0;	//���ӷ���
	int addHP = 0;		//����Hp
	int addMaxHP = 0;	//����max HP
	int priceSell;
	int priceBuy;
};

//��Ʒʵ����
//Goods goods[24] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23 };

#endif