#include"Role.h"
Role::Role(string name, int HP, int attack, int DEF, int Agility, double dodge, int life, int money, int level):name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), dodge(dodge), life(life), money(money), level(level), EXP(0)
{
}
void Role::showrole()
{
    cout << endl;
    cout << "��ǰ��������:" << endl;
    cout << "����: " << name << "\t\t";
    cout << "�ȼ�: " << level << endl;
    cout << "��Ѫ: " << HP << "\t\t";
    cout << "����: " << attack << "\t\t";
    cout << "����: " << DEF << "\t\t";
    cout << "��Ǯ: " << money << endl;
    cout << "����: " << Agility << "\t\t";
    cout << "����: " << dodge << "\t\t";
    cout << "����: " << life << "\t\t\t";
    cout << "����: " << EXP << endl;
    cout << endl;
}
