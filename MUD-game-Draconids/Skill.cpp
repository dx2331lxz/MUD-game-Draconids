#include "Skill.h"


Skill::Skill()
{
}

Skill::~Skill()
{
}

void Skill::show()
{
	cout << "技能名称：" << name << endl;
	cout << "技能介绍：" << introduce << endl;
	cout << "技能效果：" << effect << endl;
}

GUI::GUI():Skill("言灵·鬼胜", "攻击提升100%(只能释放一次)", "该言灵的有效范围是释放者自身，释放者命令自己的身体完全忘记疼痛，从而发挥出极限的力量")
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



SHEN::SHEN():Skill("言灵·深血","若被攻击, 则扣除敌方血量(或者降低其攻击)","使自己带有毒性")
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

XI::XI():Skill("言灵·吸血镰", "释放一次攻击1.5倍伤害, 吸收攻击力30% 血量", "我tm吸吸吸， 没有一滴血是自己的")
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