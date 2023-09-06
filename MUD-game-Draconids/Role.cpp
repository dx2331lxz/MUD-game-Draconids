#include"Role.h"

Role::Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level):name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), life(life), money(money), level(level), EXP(0)
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
    cout << "����: " << life << "\t\t\t";
    cout << "����: " << EXP << endl;
    cout << endl;
}

int Role::showskill()
{
    int size = 0;
    if (Skill_vector.size() == 0) {
        cout << "���ܲ�����" << endl;
    }
    else {
        // ʹ�õ��������� set
        for (const unique_ptr<Skill>& element : Skill_vector) {
            cout << size + 1 << ". ";
            size++;
            element->show();
        }
    }
    return Skill_vector.size();
}

int Role::Addskill(unique_ptr<Skill> skill)
{
    //auto it = std::find(Skill_vector.begin(), Skill_vector.end(), skill);
    //if (it != Skill_vector.end()) {
    //    std::cout << "�����ظ���Ӽ���" << std::endl;
    //}
    //else {
    //    cout << "��ӳɹ�" << endl;
    //    Skill_vector.push_back(skill);
    //}
    //return Skill_vector.size();
    auto result = Skill_vector.insert(std::move(skill));

    if (result.second) {
        std::cout << "��ӳɹ�" << std::endl;
    }
    else {
        std::cout << "�����ظ���Ӽ���" << std::endl;
    }

    return Skill_vector.size();
}
// TODO: ��Ӷ�ս�߼���Ŀǰʹ�ü��ܺͼ��ܽ���֮��û�ж�ս��
void Role::Useskill(int choose)
{
    if (showskill()) {
    }
    else
    {
        cout << "ѡ������Ҫʹ�õļ���(ֻ���ܼ���ǰ�������)��" << endl;
        cin >> choose;
        if (choose == 0) {
            cout << "��������������ļ���" << endl;
        }
        int i = 0;

        switch (choose)
        {
        case 1: {
            // ʹ�õ��������� set ������Ԫ��
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 1) {
                    element->Motor_skill_start(*this);
                    element->Motor_skill_end(*this);
                }
            }
            break;
        }
        case 2: {
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 2) {
                    element->Motor_skill_start(*this);
                    element->Motor_skill_end(*this);
                }
            }
            break;
        }
        case 3:
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 3) {
                    element->Motor_skill_start(*this);
                    element->Motor_skill_end(*this);
                }
            }
            break;
        default:
            cout << "��������������ļ���" << endl;
            break;
        }
    }
    
}
#include "Role.h"

// ... (������Ա�����Ķ���)

void Role::addExp(int addExp) {
    EXP += addExp;
    auto level_ = level;
    for (int i = 0; i < 29; i++) {
        if (levelExp_Max[i] <= EXP) {

            level = i + 1;
        }
    }
    if (level_ < level) {
        cout << "���������� ��ϲ���Ѿ�����" << level << "��������" << endl;
    }
}

void Role::addMoney(int addMoney) {
    money += addMoney;
}

int Role::getAgility() const {
    return Agility;
}

int Role::getAttack() const {
    return attack;
}

int Role::getDEF() const {
    return DEF; 
}

int Role::getHP() const {
    return HP;
}

string Role::getname()
{
    return string(name);
}

int Role::getlife()
{
    return life;
}

int Role::getmoney()
{
    return money;
}

int Role::getlevel()
{
    return level;
}

int Role::getEXP()
{
    return EXP;
}


void Role::recoverHP(int amount) {
    HP += amount;
    if (HP > 100) {
        HP = 100;
    }
}

void Role::takeDamage(int damage) {
    HP -= damage;
    if (HP < 0) {
        HP = 0;
    }
}
