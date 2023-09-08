#include "Skill.h"


Skill::Skill()
{
}

Skill::~Skill()
{
}

void Skill::show()
{
	cout << "�������ƣ�" << name << endl;
	cout << "���ܽ��ܣ�" << introduce << endl;
	cout << "����Ч����" << effect << endl;
}

GUI::GUI():Skill("���顤��ʤ", "��������100%(ֻ���ͷ�һ��)", "���������Ч��Χ���ͷ��������ͷ��������Լ���������ȫ������ʹ���Ӷ����ӳ����޵�����")
{
}

void GUI::Motor_skill_start(Role& role)
{
	role.attack = role.attack * 2;
}

void GUI::Motor_skill_end(Role& role)
{
	role.attack = role.attack / 2;
}



SHEN::SHEN():Skill("���顤��Ѫ","��������, ��۳��з�Ѫ��(���߽����乥��)","ʹ�Լ����ж���")
{
}

void SHEN::Motor_skill_start(Role& role)
{
	role.HP -= 5;
	role.attack -= 5;
}

void SHEN::Motor_skill_end(Role& role)
{
}

XI::XI():Skill("���顤��Ѫ��", "�ͷ�һ�ι���1.5���˺�, ���չ�����30% Ѫ��", "��tm�������� û��һ��Ѫ���Լ���")
{
}

void XI::Motor_skill_start(Role& role)
{
	role.HP += static_cast<int>(role.attack * 0.3);
	if (role.HP > 100) {
		role.HP = 100;
	}
	atteck = role.attack;
	role.attack = static_cast<int>(role.attack * 1.5);
}

void XI::Motor_skill_end(Role& role)
{
	role.attack = atteck;
}