#ifndef FIGHT_H
#define FIGHT_H


Role player; �� Enemy enemy; ��ʾս���Ľ�ɫ�͵��ˡ�
bool fightRound(); ����������ʾ��ǰ�غϵ�ս�������Ȼ�󷵻��Ƿ����ܡ�
void showFight(); ����������ʾս��״̬��
void enemyFight(); ������ʾ���˵����������
bool isFightEnd(); ���������ж�ս���Ƿ������
Role& endFight(); �������ڽ���ս������ս����Ľ�ɫ���أ����ܻḲ���������еĽ�ɫ��
Role& runEndFight(); �����������ܽ���ս����
void addMoney(int addMoney); ������ӽ�Ǯ��
void addFightEndGoods(int* addGoods, int* num); ���������Ʒ��
void addExp(int addExp); ������Ӿ��顣
void recoverHp(); ���ڻظ�����ֵ��
bool evadeAttack();�������ܹ�����
void GameEnd(); �����ж���Ϸ�Ƿ���������������������˳���
#endif