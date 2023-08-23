#include"Role.h"
Role::Role(string name, int HP, int attack, int DEF, int Agility, double dodge, int life, int money, int level):name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), dodge(dodge), life(life), money(money), level(level), EXP(0)
{
}
void Role::showrole()
{
    cout << endl;
    cout << "当前人物属性:" << endl;
    cout << "姓名: " << name << "\t\t";
    cout << "等级: " << level << endl;
    cout << "气血: " << HP << "\t\t";
    cout << "攻击: " << attack << "\t\t";
    cout << "防御: " << DEF << "\t\t";
    cout << "金钱: " << money << endl;
    cout << "敏捷: " << Agility << "\t\t";
    cout << "闪避: " << dodge << "\t\t";
    cout << "生命: " << life << "\t\t\t";
    cout << "经验: " << EXP << endl;
    cout << endl;
}
