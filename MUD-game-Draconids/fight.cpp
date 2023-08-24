#include "Fight.h"
#include <iostream>
#include <cstdlib> // 用于生成随机数
#include "Skill.h" // 包含 Skill 头文件
using namespace std;

Fight::Fight(Role& player, Enemy& enemy) : player(player), enemy(enemy), round(1), hurt(0) {}

bool Fight::fightRound() {
    cout << "第 " << round << " 回合" << endl;

    cout << "请选择行动：" << endl;
    cout << "1. 普通攻击" << endl;
    cout << "2. 技能" << endl;
    cout << "3. 逃跑" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        playerAttack();
        break;
    case 2:
        // 调用技能相关函数
        break;
    case 3:
        cout << "你选择逃跑了。" << endl;
        return true; // 逃跑
    default:
        cout << "无效的选择，继续战斗。" << endl;
        break;
    }

    if (isFightEnd()) {
        return false;
    }
    enemyAttack();

    return false; // 继续战斗
}

void Fight::playerAttack() {
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDefense();
    int damage = max(playerAttack - enemyDefense, 0);

    enemy.takeDamage(damage);
    cout << "玩家使用普通攻击对敌人造成 " << damage << " 伤害。" << endl;
}

void Fight::enemyAttack() {
    int enemyAttack = enemy.getAttack();
    int playerDefense = player.getDefense();
    int damage = max(enemyAttack - playerDefense, 0);

    if (evadeAttack()) {
        cout << "玩家闪避了敌人的攻击！" << endl;
        return;
    }
    player.takeDamage(damage);
    cout << "敌人使用普通攻击对玩家造成 " << damage << " 伤害。" << endl;
}

bool Fight::evadeAttack() {
    int evadeChance = rand() % 100;
    if (evadeChance < player.getAgility() * 3) {
        return true;
    }
    return false;
}

bool Fight::isFightEnd() {
    return player.getHP() <= 0 || enemy.getHP() <= 0;
}

Role& Fight::endFight() {
    if (player.getHP() <= 0) {
        cout << "战斗失败。" << endl;
    }
    else {
        cout << "恭喜！你赢得了战斗。" << endl;
        addExp(100); // 添加经验值
    }
    return player;
}

Role& Fight::runEndFight() {
    cout << "你选择逃跑了。" << endl;
    return player;
}

void Fight::addMoney(int addMoney) {
    player.addMoney(addMoney);
    cout << "你获得了 " << addMoney << " 金钱。" << endl;
}

void Fight::addFightEndGoods(int* addGoods, int* num) {
    // 添加物品到玩家的背包
    // 参数 addGoods 和 num 可能表示获得的物品 ID 和数量
    // 根据 Goods 类和背包系统的实际情况实现这部分
}

void Fight::addExp(int addExp) {
    player.addExp(addExp);
    cout << "你获得了 " << addExp << " 经验值。" << endl;
}

void Fight::recoverHp() {
    player.recoverHP();
    cout << "你恢复了一些生命值。" << endl;
}
void Fight::playerAttack() {
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDefense();
    int damage = max(playerAttack - enemyDefense, 0);

    double vampireRate = player.getVampireRate();
    int vampireAmount = static_cast<int>(damage * vampireRate);

    enemy.takeDamage(damage);
    player.recoverHP(vampireAmount); // 根据武器属性回复生命值
    cout << "玩家使用普通攻击对敌人造成 " << damage << " 伤害，吸取了 " << vampireAmount << " 生命值。" << endl;
}


void Fight::GameEnd() {
    if (player.getHP() <= 0) {
        cout << "游戏结束。" << endl;
        exit(0);
    }
}
