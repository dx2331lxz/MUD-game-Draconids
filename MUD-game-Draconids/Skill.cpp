#include "Skill.h"
#include "Role.h"
#include <iostream>
#include"main.h"
#include"fight.h"



class FightSystem;
void Skill::show()
{
    cout << "技能名称：" << name << endl;
    cout << "技能介绍：" << introduce << endl;
    cout << "技能效果：" << effect << endl;
}
void Skill::can()
{
    is_can_use = true;
}
bool Skill::get_is_can_use()
{
    return is_can_use;
}
Skill::Skill()
{
}

Skill::~Skill()
{
}



GUI::GUI():Skill("言灵·鬼胜", "攻击提升100%(只能释放一次)", "该言灵的有效范围是释放者自身，释放者命令自己的身体完全忘记疼痛，从而发挥出极限的力量")
{
}

void GUI::Motor_skill_start(Role& role, Role& enemy)
{
    role.attack = role.attack * 2;
    FightSystem fs(role,enemy); // 创建 FightSystem 的对象，或者从其他地方获取已有的对象

    // 调用 playerAttack
    fs.playerAttack();

}

void GUI::Motor_skill_end(Role& role, Role& enemy)
{
    role.attack = role.attack / 2;
}



SHEN::SHEN():Skill("言灵·深血","自己受伤爆发巨额伤害","该言灵对自己和敌人同时造成伤害")
{
}

void SHEN::Motor_skill_start(Role& role, Role& enemy)
{
    role.HP -= 5;
    role.attack += 5;
    FightSystem fs(role, enemy); // 创建 FightSystem 的对象，或者从其他地方获取已有的对象

    // 调用 playerAttack
    fs.playerAttack();
}

void SHEN::Motor_skill_end(Role& role, Role& enemy)
{
    role.attack -= 5;
}

XI::XI():Skill("言灵·吸血镰", "释放一次攻击1.5倍伤害, 吸收攻击力30% 血量", "我tm吸吸吸， 没有一滴血是自己的")
{
}

void XI::Motor_skill_start(Role& role, Role& enemy)
{
    role.attack = role.attack * 2;
    FightSystem fs(role, enemy); // 创建 FightSystem 的对象，或者从其他地方获取已有的对象

    // 调用 playerAttack
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