#include "Fight.h"
#include <iostream>
#include <cstdlib> // 用于生成随机数
#include "Skill.h" // 包含 Skill 头文件
#include "Role.h"  // 包含 Role 头文件
using namespace std;

FightSystem::FightSystem(Role& player, Role& enemy)
    : player(player), enemy(enemy), round(1), hurt(0)
{
}

bool FightSystem::fightRound()
{
    cout << "第 " << round << " 回合" << endl; 
    enemy.showrole();
    cout << "请选择行动：" << endl;
    cout << "1. 普通攻击" << endl;
    cout << "2. 技能" << endl;
    cout << "3. 逃跑" << endl;

    int choice1,choice2;
    cin >> choice1;

    switch (choice1)
    {
    case 1:
        playerAttack();
        break;
    case 2:
        cout << "请选择你要使用的技能 ";        // todo 调用技能相关函数
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            Skill::show();
            GUI::Skill;
            break;
        case 2:
            break;
        case 3:
            break;
        }
        break;
    case 3:
        cout << "你选择逃跑了。" << endl;
        whetherrun = 1;
        return false; // 逃跑
    default:
        cout << "无效的选择，继续战斗。" << endl;
        break;
    }

    if (isFightEnd())
    {
        return false;
    }
    enemyAttack();

    return true; // 继续战斗
}

void FightSystem::playerAttack()
{
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDEF(); // 使用角色的防御属性
    int damage = max(playerAttack - enemyDefense, 0);


    enemy.takeDamage(damage);

    cout << "玩家使用普通攻击对敌人造成 " << damage << endl;
}

void FightSystem::enemyAttack()
{
    int enemyAttack = enemy.getAttack();
    int playerDefense = player.getDEF(); // 使用角色的防御属性
    int damage = max(enemyAttack - playerDefense, 0);

    if (evadeAttack())
    {
        cout << "玩家闪避了敌人的攻击！" << endl;
        return;
    }
    player.takeDamage(damage);
    cout << "敌人使用普通攻击对玩家造成 " << damage << " 伤害。" << endl;
}

int FightSystem::addround()
{
    return ++round;
}

bool FightSystem::evadeAttack()
{
    int evadeChance = rand() % 100;
    if (evadeChance < player.getAgility() * 3)
    {
        return true;
    }
    return false;
}

bool FightSystem::isFightEnd()
{
    return player.getHP() <= 0 || enemy.getHP() <= 0;
}

bool FightSystem::endFight()
{
    if (enemy.getHP() > 0)
    {
        cout << "战斗失败。" << endl;
        return false;
    }
    else
    {
        cout << "恭喜！你赢得了战斗。" << endl;
        addExp(20); // 添加经验值
        return true;
    }
}


Role& FightSystem::runEndFight()
{
    cout << "你选择逃跑了。" << endl;
    return player;
}

void FightSystem::addMoney(int addMoney)
{
    player.addMoney(addMoney);
    cout << "你获得了 " << addMoney << " 金钱。" << endl;
}

void FightSystem::addFightEndGoods(int* addGoods, int* num)
{
    // 添加物品到玩家的背包
    // 参数 addGoods 和 num 可能表示获得的物品 ID 和数量
    // 根据 Goods 类和背包系统的实际情况实现这部分
}

void FightSystem::addExp(int Exp)
{
    player.addExp(Exp);
    cout << "你获得了 " << Exp << " 经验值。" << endl;
}

void FightSystem::recoverHp()
{
    player.recoverHP(10);
    cout << "你恢复了一些生命值。" << endl;
}

void FightSystem::GameEnd()
{
    if (player.getHP() <= 0)
    {
        cout << "游戏结束。" << endl;
        exit(0);
    }
}
