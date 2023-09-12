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

void Skill::can()
{
    is_can = true;
}

bool Skill::get_is_can()
{
    return is_can;
}


GUI::GUI() :Skill("���顤��ʤ", "��������100%(ֻ���ͷ�һ��)", "���������Ч��Χ���ͷ��������ͷ��������Լ���������ȫ������ʹ���Ӷ����ӳ����޵�����")
{
}

void GUI::Motor_skill_start(Role& role, Role& enemy)
{
    role.attack = role.attack * 2;
    FightSystem fs(role, enemy); // ���� FightSystem �Ķ��󣬻��ߴ������ط���ȡ���еĶ���

    // ���� playerAttack
    fs.playerAttack();

}

void GUI::Motor_skill_end(Role& role, Role& enemy)
{
    role.attack = role.attack / 2;
}



SHEN::SHEN() :Skill("���顤��Ѫ", "�Լ����˱����޶��˺�", "��������Լ��͵���ͬʱ����˺�")
{
}

void SHEN::Motor_skill_start(Role& role, Role& enemy)
{
    role.HP -= 5;
    role.attack += 5;
    FightSystem fs(role, enemy); // ���� FightSystem �Ķ��󣬻��ߴ������ط���ȡ���еĶ���

    // ���� playerAttack
    fs.playerAttack();
}

void SHEN::Motor_skill_end(Role& role, Role& enemy)
{
    role.attack -= 5;
}

XI::XI() :Skill("���顤��Ѫ��", "�ͷ�һ�ι���1.5���˺�, ���չ�����30% Ѫ��", "��tm�������� û��һ��Ѫ���Լ���")
{
}

void XI::Motor_skill_start(Role& role, Role& enemy)
{
    role.attack = role.attack * 2;
    FightSystem fs(role, enemy); // ���� FightSystem �Ķ��󣬻��ߴ������ط���ȡ���еĶ���

    // ���� playerAttack
    role.HP += static_cast<int>(role.attack * 0.3);
    if (role.HP > 100) {
        role.HP = 100;
    }
    atteck = role.attack;
    role.attack = static_cast<int>(role.attack * 1.5);
    fs.playerAttack();
}

void XI::Motor_skill_end(Role& role, Role& enemy)
{
    role.attack = role.attack / 2;
}
