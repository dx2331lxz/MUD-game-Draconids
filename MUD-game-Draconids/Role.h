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
    Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level); //构造函数
    Role(const Role &role);
    // 展示角色信息
    void showrole();
    // 展示角色技能
    int showskill();
    // 添加技能
    void Addskill(int choose = 0);
    // 使用技能
    void Useskill(Role& enemy);
    int get_skill();
    void set_skill(int size);
 // 声明技能为Role友元类
    void increaseDEF(int defenseIncrease);//增加防御
    void setDEF(int i);//重置防御
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
    int getBagWhichGoodsId(int whichGoods);			//得到背包里第whichGoods件物品
    int getBagWhichGoodsNum(int whichGoods);
    //显示背包
    void addGoodsToBag(int* goodsId, int* num);//加入背包,重载应对两种情况
    void addGoodsToBag(int goodsId, int num);
    bool subGoodsToBag(int goodsId, int num);	//减少背包里的物品
    void setBag(Bag &bags);
    void newBag();


    void useDrug();
    int getHealth();
    int getHealth_max();
    void setHealth(int hp);

    void showEquip();//展示当前装备
    void wearEquip(int id);//穿上装备
    void removeEquip(int id);//脱下装备

    int getWeapon();
    void setWeapon(int w);
    int getClothes();
    void setClothes(int c);
private:
    string name;
    int HP;          // 血量
    int attack;      // 攻击
    int DEF;         // 防御
    int Agility;     // 敏捷
    std::set<std::unique_ptr<Skill>> Skill_vector; // 技能  find
    int life; // 生命
    int weapon=-1; // 武器（只能装备一把）
    int clothes=-1; // 武器（只能装备一把）
    Bag bag; // 背包
    int money; // 金币
    //Task& task; // 任务
    int level; // 等级 
    int EXP; // 经验
    
    const int levelExp_Max[29] = { 6,12,18,24,30,36,42,48,54,60,69,78,87,96,105,114,123,132,141,150,162,174,186,198,210,225,240,270,300 }; // 每个对应等级的最高经验值
    Goods goods[14] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13 };
};



//初始路明非:
//血量:50
//攻击 : 5
//防御 : 1(按照伤害 = 攻击 - 防御的血量扣除)
//敏捷 : 4(攻击先后手)
//闪避 : 20 % (男主能力差, 逃跑能力一流)
//技能 : 无(后期可学习多个技能)
//生命 : 1 / 1
//武器 : 无(武器可装备多把, 手中只可拥有一把, 多余存储背包中, 并可以随时切换)
//背包 :
//金币 : 10
//任务 : 主线任务一直存在(且更新), 支线任务对话增加
//经验 : 1 / 10()