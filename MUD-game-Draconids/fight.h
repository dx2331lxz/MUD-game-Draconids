#pragma once
#include "Role.h"
#include "Goods.h"
#include"main.h"

class FightSystem {
public:
    FightSystem(Role& player, Role& enemy); // 修改这里的参数类型为 Role&

    bool fightRound();    // 显示当前回合的战斗情况，返回是否逃跑
    void showFight();     // 显示战斗状态
    void enemyFight();    // 敌人的随机攻击
    bool isFightEnd();    // 判断战斗是否结束
    bool endFight();     // 结束战斗，返回战斗后的角色，可能覆盖主程序中的角色
    Role& runEndFight();  // 逃跑结束战斗
    void addMoney(int addMoney);    // 添加金钱
    void addFightEndGoods(int* addGoods, int* num);   // 添加物品
    void addExp(int Exp);    // 添加经验
    void recoverHp();   // 回复生命值
    bool evadeAttack(); // 闪避攻击
    void playerAttack(); // 武器攻击
    void GameEnd();     // 判断游戏是否结束，如果结束，程序会退出
    void enemyAttack();
    int addround();

private:
    Role& player;   // 战斗的角色
    Role& enemy;   // 战斗的敌人，使用 Role 类的实例
    int round;      // 回合数
    double hurt;    // 战斗产生的伤害值
    Goods goods[24];    // 物品列表，根据你的需求进行调整
};