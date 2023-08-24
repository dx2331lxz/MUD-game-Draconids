#ifndef FIGHT_H
#define FIGHT_H


Role player; 和 Enemy enemy; 表示战斗的角色和敌人。
bool fightRound(); 函数用于显示当前回合的战斗情况，然后返回是否逃跑。
void showFight(); 函数用于显示战斗状态。
void enemyFight(); 函数表示敌人的随机攻击。
bool isFightEnd(); 函数用于判断战斗是否结束。
Role& endFight(); 函数用于结束战斗，将战斗后的角色返回，可能会覆盖主程序中的角色。
Role& runEndFight(); 函数用于逃跑结束战斗。
void addMoney(int addMoney); 用于添加金钱。
void addFightEndGoods(int* addGoods, int* num); 用于添加物品。
void addExp(int addExp); 用于添加经验。
void recoverHp(); 用于回复生命值。
bool evadeAttack();用于闪避攻击。
void GameEnd(); 用于判断游戏是否结束，如果结束，程序会退出。
#endif