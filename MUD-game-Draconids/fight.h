#pragma once
#include "Role.h"
#include "Goods.h"
#include"main.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <thread>


class FightSystem {
public:
    FightSystem(Role& player, Role& enemy); // �޸�����Ĳ�������Ϊ Role&

    bool fightRound();    // ��ʾ��ǰ�غϵ�ս������������Ƿ�����
    void showFight();     // ��ʾս��״̬
    void enemyFight();    // ���˵��������
    bool isFightEnd();    // �ж�ս���Ƿ����
    bool endFight();     // ����ս��������ս����Ľ�ɫ�����ܸ����������еĽ�ɫ
    Role& runEndFight();  // ���ܽ���ս��
    void addMoney(int addMoney);    // ��ӽ�Ǯ
    void addFightEndGoods(int* addGoods, int* num);   // �����Ʒ
    void addExp(int Exp);    // ��Ӿ���
    void recoverHp();   // �ظ�����ֵ
    bool evadeAttack(); // ���ܹ���
    void playerAttack(); // ��������
    void GameEnd();     // �ж���Ϸ�Ƿ���������������������˳�
    void enemyAttack();
    int addround();
    void playWav(const char* wavFileName);

private:
    Role& player;   // ս���Ľ�ɫ
    Role& enemy;   // ս���ĵ��ˣ�ʹ�� Role ���ʵ��
    int round;      // �غ���
    double hurt;    // ս���������˺�ֵ
    Goods goods[24];    // ��Ʒ�б��������������е���
};