#include "Skill.h"

#include "Skill.h"
#include "Role.h"

Skill::Skill(const std::string& name, int damage, int mpCost, const std::string& description)
	: name(name), damage(damage), mpCost(mpCost), description(description)
{
}

const std::string& Skill::getName() const {
	return name;
}

int Skill::getDamage() const {
	return damage;
}

int Skill::getMPCost() const {
	return mpCost;
}

const std::string& Skill::getDescription() const {
	return description;
}

void Skill::useSkill(Role& attacker, Role& target) const {
	// 根据技能名称执行相应的效果
	if (name == "龙之吐息") {
		// 龙之吐息对敌人造成伤害
		int damage = getDamage(); // 获取技能伤害
		target.takeDamage(damage);
		cout << attacker.getName() << " 使用 " << name << " 对 " << target.getName() << " 造成 " << damage << " 伤害。" << endl;
	}
	else if (name == "龙鳞护甲") {
		// 龙鳞护甲增加角色防御
		int defenseIncrease = getDamage(); // 这里使用伤害属性来表示防御增加值
		attacker.increaseDEF(defenseIncrease);
		cout << attacker.getName() << " 激活了 " << name << "，增加了 " << defenseIncrease << " 点防御力。" << endl;
	}
	else if (name == "龙吟咒语") {
		// 龙吟咒语降低对方防御但不能低于0
		int defenseDecrease = getDamage(); // 这里使用伤害属性来表示防御降低值
		int newDefense = max(target.getDEF() - defenseDecrease, 0); // 防御降低但不能低于0
		target.setDEF(newDefense); // 设置新的防御值
		cout << attacker.getName() << " 使用 " << name << " 对 " << target.getName() << " 释放咒语，降低了对方防御。" << endl;
	}
}


/*Skill::Skill()
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