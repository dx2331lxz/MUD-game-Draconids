#ifndef FIGHT_H
#define FIGHT_H

#ifndef FIGHTSYSTEM_H
#define FIGHTSYSTEM_H

#include "Role.h"
#include "Enemy.h"
#include "Goods.h"

class FightSystem {
public:
    FightSystem(Role& player, Enemy& enemy);

    bool fightRound();    // ��ʾ��ǰ�غϵ�ս������������Ƿ�����
    void showFight();     // ��ʾս��״̬
    void enemyFight();    // ���˵��������
    bool isFightEnd();    // �ж�ս���Ƿ����
    Role& endFight();     // ����ս��������ս����Ľ�ɫ�����ܸ����������еĽ�ɫ
    Role& runEndFight();  // ���ܽ���ս��
    void addMoney(int addMoney);    // ��ӽ�Ǯ
    void addFightEndGoods(int* addGoods, int* num);   // �����Ʒ
    void addExp(int addExp);    // ��Ӿ���
    void recoverHp();   // �ظ�����ֵ
    bool evadeAttack(); // ���ܹ���
    void Fight::playerAttack()//��������
    void GameEnd();     // �ж���Ϸ�Ƿ���������������������˳�

private:
    Role& player;   // ս���Ľ�ɫ
    Enemy& enemy;   // ս���ĵ���
    int round;      // �غ���
    double hurt;    // ս���������˺�ֵ
    Goods goods[24];    // ��Ʒ�б��������������е���
};

#endif
