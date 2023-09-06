#include "Fight.h"
#include <iostream>
#include <cstdlib> // �������������
#include "Skill.h" // ���� Skill ͷ�ļ�
#include "Role.h"  // ���� Role ͷ�ļ�
using namespace std;

FightSystem::FightSystem(Role& player, Role& enemy)
    : player(player), enemy(enemy), round(1), hurt(0)
{
}

bool FightSystem::fightRound()
{
    cout << "�� " << round << " �غ�" << endl;

    cout << "��ѡ���ж���" << endl;
    cout << "1. ��ͨ����" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����" << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
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

    if (isFightEnd())
    {
        return false;
    }
    enemyAttack();

    return false; // ����ս��
}

void FightSystem::playerAttack()
{
    int playerAttack = player.getAttack();
    int enemyDefense = enemy.getDEF(); // ʹ�ý�ɫ�ķ�������
    int damage = max(playerAttack - enemyDefense, 0);


    enemy.takeDamage(damage);

    cout << "���ʹ����ͨ�����Ե������ " << damage << endl;
}

void FightSystem::enemyAttack()
{
    int enemyAttack = enemy.getAttack();
    int playerDefense = player.getDEF(); // ʹ�ý�ɫ�ķ�������
    int damage = max(enemyAttack - playerDefense, 0);

    if (evadeAttack())
    {
        cout << "��������˵��˵Ĺ�����" << endl;
        return;
    }
    player.takeDamage(damage);
    cout << "����ʹ����ͨ������������ " << damage << " �˺���" << endl;
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

Role& FightSystem::endFight()
{
    if (player.getHP() <= 0)
    {
        cout << "ս��ʧ�ܡ�" << endl;
    }
    else
    {
        cout << "��ϲ����Ӯ����ս����" << endl;
        addExp(100); // ���Ӿ���ֵ
    }
    return player;
}

Role& FightSystem::runEndFight()
{
    cout << "��ѡ�������ˡ�" << endl;
    return player;
}

void FightSystem::addMoney(int addMoney)
{
    player.addMoney(addMoney);
    cout << "������ " << addMoney << " ��Ǯ��" << endl;
}

void FightSystem::addFightEndGoods(int* addGoods, int* num)
{
    // ������Ʒ����ҵı���
    // ���� addGoods �� num ���ܱ�ʾ��õ���Ʒ ID ������
    // ���� Goods ��ͱ���ϵͳ��ʵ�����ʵ���ⲿ��
}

void FightSystem::addExp(int addExp)
{
    player.addExp(addExp);
    cout << "������ " << addExp << " ����ֵ��" << endl;
}

void FightSystem::recoverHp()
{
    player.recoverHP(100);
    cout << "��ָ���һЩ����ֵ��" << endl;
}

void FightSystem::GameEnd()
{
    if (player.getHP() <= 0)
    {
        cout << "��Ϸ������" << endl;
        exit(0);
    }
}