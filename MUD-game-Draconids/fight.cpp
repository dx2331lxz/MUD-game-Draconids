#include "Fight.h"
#include <iostream>
#include <cstdlib> // �������������
#include "Skill.h" // ���� Skill ͷ�ļ�
using namespace std;

Fight::Fight(Role& player, Enemy& enemy) : player(player), enemy(enemy), round(1), hurt(0) {}

bool Fight::fightRound() {
    cout << "�� " << round << " �غ�" << endl;

    cout << "��ѡ���ж���" << endl;
    cout << "1. ��ͨ����" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        playerAttack();
        break;
    case 2:
        // ���ü�����غ���
        break;
    case 3:
        cout << "��ѡ�������ˡ�" << endl;
        return true; // ����
    default:
        cout << "��Ч��ѡ�񣬼���ս����" << endl;
        break;
    }

    if (isFightEnd()) {
        return false;
    }
    enemyAttack();

    return false; // ����ս��
}

void Fight::playerAttack() {
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDefense();
    int damage = max(playerAttack - enemyDefense, 0);

    enemy.takeDamage(damage);
    cout << "���ʹ����ͨ�����Ե������ " << damage << " �˺���" << endl;
}

void Fight::enemyAttack() {
    int enemyAttack = enemy.getAttack();
    int playerDefense = player.getDefense();
    int damage = max(enemyAttack - playerDefense, 0);

    if (evadeAttack()) {
        cout << "��������˵��˵Ĺ�����" << endl;
        return;
    }
    player.takeDamage(damage);
    cout << "����ʹ����ͨ������������ " << damage << " �˺���" << endl;
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
        cout << "ս��ʧ�ܡ�" << endl;
    }
    else {
        cout << "��ϲ����Ӯ����ս����" << endl;
        addExp(100); // ��Ӿ���ֵ
    }
    return player;
}

Role& Fight::runEndFight() {
    cout << "��ѡ�������ˡ�" << endl;
    return player;
}

void Fight::addMoney(int addMoney) {
    player.addMoney(addMoney);
    cout << "������ " << addMoney << " ��Ǯ��" << endl;
}

void Fight::addFightEndGoods(int* addGoods, int* num) {
    // �����Ʒ����ҵı���
    // ���� addGoods �� num ���ܱ�ʾ��õ���Ʒ ID ������
    // ���� Goods ��ͱ���ϵͳ��ʵ�����ʵ���ⲿ��
}

void Fight::addExp(int addExp) {
    player.addExp(addExp);
    cout << "������ " << addExp << " ����ֵ��" << endl;
}

void Fight::recoverHp() {
    player.recoverHP();
    cout << "��ָ���һЩ����ֵ��" << endl;
}
void Fight::playerAttack() {
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDefense();
    int damage = max(playerAttack - enemyDefense, 0);

    double vampireRate = player.getVampireRate();
    int vampireAmount = static_cast<int>(damage * vampireRate);

    enemy.takeDamage(damage);
    player.recoverHP(vampireAmount); // �����������Իظ�����ֵ
    cout << "���ʹ����ͨ�����Ե������ " << damage << " �˺�����ȡ�� " << vampireAmount << " ����ֵ��" << endl;
}


void Fight::GameEnd() {
    if (player.getHP() <= 0) {
        cout << "��Ϸ������" << endl;
        exit(0);
    }
}
