#pragma once
#include "main.h"
#include <vector>
#include<string>
#include"Bag.h"
#include"Goods.h"
#include<set>
#include <algorithm>
using namespace std;
class Skill;
class Goods;

class Task;


class Bag;


class Role
{
public:
    Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level); //���캯��
    Role(const Role &role);
    // չʾ��ɫ��Ϣ
    void showrole();
    // չʾ��ɫ����
    int showskill();
    // ��Ӽ���
    void Addskill(int choose = 0);
    // ʹ�ü���
    void Useskill(Role& enemy);
    int get_skill();
    void set_skill(int size);
 // ��������ΪRole��Ԫ��
    friend class GUI;
    friend class SHEN;
    friend class XI;
    void addExp(int addExp);
    void addMoney(int addMoney);

    int getAgility() const;
    void setAgility(int a);

    int getAttack() const;
    void setAttack(int a);

    int getDEF() const;
    void setDefend(int d);

    int getHP() const;
    string getname();
    int getlife();
    void setMoney(int m);
    int getMoney();
    
    int getlevel();
    int getEXP();
    void recoverHP(int amount);
    void takeDamage(int damage);

    void addSaveGoodsToBag(int goodId, int num);

    Bag getBag();
    void showBag();
    int getBagWhichGoodsId(int whichGoods);			//�õ��������whichGoods����Ʒ
    int getBagWhichGoodsNum(int whichGoods);
    //��ʾ����
    void addGoodsToBag(int* goodsId, int* num);//���뱳��,����Ӧ���������
    void addGoodsToBag(int goodsId, int num);
    bool subGoodsToBag(int goodsId, int num);	//���ٱ��������Ʒ
    void setBag(Bag &bags);
    void newBag();


    void useDrug();
    int getHealth();
    int getHealth_max();
    void setHealth(int hp);

    void showEquip();//չʾ��ǰװ��
    void wearEquip(int id);//����װ��
    void removeEquip(int id);//����װ��

    int getWeapon();
    void setWeapon(int w);
    int getClothes();
    void setClothes(int c);
private:
    string name;
    int HP;          // Ѫ��
    int attack;      // ����
    int DEF;         // ����
    int Agility;     // ����
    std::set<std::unique_ptr<Skill>> Skill_vector; // ����  find
    int life; // ����
    int weapon=-1; // ������ֻ��װ��һ�ѣ�
    int clothes=-1; // ������ֻ��װ��һ�ѣ�
    Bag bag; // ����
    int money; // ���
    //Task& task; // ����
    int level; // �ȼ� 
    int EXP; // ����
    
    const int levelExp_Max[29] = { 6,12,18,24,30,36,42,48,54,60,69,78,87,96,105,114,123,132,141,150,162,174,186,198,210,225,240,270,300 }; // ÿ����Ӧ�ȼ�����߾���ֵ
    Goods goods[14] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13 };
};



//��ʼ·����:
//Ѫ��:50
//���� : 5
//���� : 1(�����˺� = ���� - ������Ѫ���۳�)
//���� : 4(�����Ⱥ���)
//���� : 20 % (����������, ��������һ��)
//���� : ��(���ڿ�ѧϰ�������)
//���� : 1 / 1
//���� : ��(������װ�����, ����ֻ��ӵ��һ��, ����洢������, ��������ʱ�л�)
//���� :
//��� : 10
//���� : ��������һֱ����(�Ҹ���), ֧������Ի�����
//���� : 1 / 10()