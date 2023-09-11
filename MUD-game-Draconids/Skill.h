#pragma once

#include <string>
#include "Role.h"

class Skill {
public:
	Skill(const std::string& name, int damage, const std::string& description);

	const std::string& getName() const;
	int getDamage() const;
	const std::string& getDescription() const;

	void useSkill(Role& attacker, Role& target) const;

private:
	std::string name;
	int damage;
	std::string description;
};

#endif // SKILL_H
/*#include"main.h"
#include<string>
#include"Role.h"
class Role;
using namespace std;
class Skill
{
public:
	Skill();
	Skill(string name, string effect, string introduce):name(name),effect(effect), introduce(introduce), is_can(false) {};
	~Skill();
	// 使用技能
	virtual void Motor_skill_start(Role& role, Role& enemy) = 0;
	// 使用技能结束
	virtual void Motor_skill_end(Role& role, Role& enemy) = 0;
	// 展示技能（名称，介绍，效果）
	void show();
	void can();
	bool get_is_can();
private:
	string name;
	string effect;
	string introduce;
	bool is_can;
};


class GUI:public Skill
{
public:
	GUI();
	virtual void Motor_skill_start(Role& role, Role& enemy);
	virtual void Motor_skill_end(Role& role, Role& enemy);

private:
	
};
//言灵·鬼胜 介绍：该言灵的有效范围是释放者自身，释放者命令自己的身体完全忘记疼痛，从而发挥出极限的力量
//效果 : 攻击下一回合提升100 % (只能释放一次)
//言灵·深血 介绍 : 效果：使自己带有毒性
//效果 : 若被攻击, 则扣除敌方血量(或者降低其攻击),
//言灵·吸血镰
//效果 : 释放一次攻击1.5倍伤害, 吸收30% 血量.
class SHEN:public Skill
{
public:
	SHEN();
	virtual void Motor_skill_start(Role& role, Role& enemy);
	virtual void Motor_skill_end(Role& role, Role& enemy);

private:

};

class XI : public Skill
{
public:
	XI();
	virtual void Motor_skill_start(Role& role, Role& enemy);
	virtual void Motor_skill_end(Role& role, Role& enemy);
private:
	int atteck;
};
*/
