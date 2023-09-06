#pragma once
#include"main.h"
#include<string>
#include"Role.h"
class Role;
using namespace std;
class Skill
{
public:
	Skill();
	Skill(string name, string effect, string introduce):name(name),effect(effect), introduce(introduce) {};
	~Skill();
	// ʹ�ü���
	virtual void Motor_skill_start(Role& role) = 0;
	// ʹ�ü��ܽ���
	virtual void Motor_skill_end(Role& role) = 0;
	// չʾ���ܣ����ƣ����ܣ�Ч����
	void show();
	string getname();
	string geteffect();
	string getintroduce();
private:
	string name;
	string effect;
	string introduce;
};


class GUI:public Skill
{
public:
	GUI();
	virtual void Motor_skill_start(Role& role);
	virtual void Motor_skill_end(Role& role);

private:
	
};
//���顤��ʤ ���ܣ����������Ч��Χ���ͷ��������ͷ��������Լ���������ȫ������ʹ���Ӷ����ӳ����޵�����
//Ч�� : ������һ�غ�����100 % (ֻ���ͷ�һ��)
//���顤��Ѫ ���� : Ч����ʹ�Լ����ж���
//Ч�� : ��������, ��۳��з�Ѫ��(���߽����乥��),
//���顤��Ѫ��
//Ч�� : �ͷ�һ�ι���1.5���˺�, ����30% Ѫ��.
class SHEN:public Skill
{
public:
	SHEN();
	virtual void Motor_skill_start(Role& role);
	virtual void Motor_skill_end(Role& role);

private:

};

class XI : public Skill
{
public:
	XI();
	virtual void Motor_skill_start(Role& role);
	virtual void Motor_skill_end(Role& role);
private:
	int atteck;
};

