#pragma once
#include "main.h"
#include <vector>
#include<string>
#include"Good.h"
using namespace std;
class Skill;
class Good;
class Bag;
class Task;
class Role
{
public:
    Role(string name, int HP, int attack, int DEF, int Agility, double dodge, int life, int money, int level); //���캯��
    void showrole();
private:
    string name;
    int HP;          // Ѫ��
    int attack;      // ����
    int DEF;         // ����
    int Agility;     // ����
    double dodge;    // ����
    std::vector<std::unique_ptr<Skill>> Skill_vector; // ����
    int life; // ����
    std::unique_ptr<Good> weapon; // ������ֻ��װ��һ�ѣ�
    std::unique_ptr<Bag> bag; // ����
    int money; // ���
    std::unique_ptr<Task> task; // ����
    int level; // �ȼ�
    int EXP; // ����
    const int levelExp_Max[29] = { 6,12,18,24,30,36,42,48,54,60,69,78,87,96,105,114,123,132,141,150,162,174,186,198,210,225,240,270,300 }; // ÿ����Ӧ�ȼ�����߾���ֵ
};

//��ʼ·����:
//Ѫ��:50
//���� : 5
//���� : 1(�����˺� = ���� - ������Ѫ���۳�)
//���� : 4(�����Ⱥ���)
//���� : 20 % (����������, ��������һ��)
//���� : ��(���ڿ�ѧϰ�������)
//���� : 1 / 1
//���� : ��(������װ�����, ����ֻ��ӵ��һ��, ����洢������, ��������ʱ�л�)
//���� :
//��� : 10
//���� : ��������һֱ����(�Ҹ���), ֧������Ի�����
//���� : 1 / 10()