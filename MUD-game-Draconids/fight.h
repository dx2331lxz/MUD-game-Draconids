#pragma once

#include "Role.h"
#include "Enemy.h"
#include "Goods.h"

class FightSystem {
public:
    FightSystem(Role& player, Enemy& enemy);

    bool fightRound();    // 显示当前回合的战斗情况，返回是否逃跑
    void showFight();     // 显示战斗状态
    void enemyFight();    // 敌人的随机攻击
    bool isFightEnd();    // 判断战斗是否结束
    Role& endFight();     // 结束战斗，返回战斗后的角色，可能覆盖主程序中的角色
    Role& runEndFight();  // 逃跑结束战斗
    void addMoney(int addMoney);    // 添加金钱
    void addFightEndGoods(int* addGoods, int* num);   // 添加物品
    void addExp(int addExp);    // 添加经验
    void recoverHp();   // 回复生命值
    bool evadeAttack(); // 闪避攻击
    void Fight::playerAttack()//武器攻击
    void GameEnd();     // 判断游戏是否结束，如果结束，程序会退出

private:
    Role& player;   // 战斗的角色
    Enemy& enemy;   // 战斗的敌人
    int round;      // 回合数
    double hurt;    // 战斗产生的伤害值
    Goods goods[24];    // 物品列表，根据你的需求进行调整
};

#endif
