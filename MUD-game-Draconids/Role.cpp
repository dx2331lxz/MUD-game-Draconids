#include"Role.h"

Role::Role(string name, int HP, int attack, int DEF, int Agility, double dodge, int life, int money, int level):name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), dodge(dodge), life(life), money(money), level(level), EXP(0)
{
    Skill_vector.insert(make_unique<XI>());
    Skill_vector.insert(make_unique<SHEN>());
    Skill_vector.insert(make_unique<GUI>());
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
int Role::showskill()
{
    int size = 0;
    int count = 0;
    // ʹ�õ��������� set
    for (const unique_ptr<Skill>& element : Skill_vector) {
        
        size++;
        if (element->get_is_can_use()) {
            cout << size << ". ";
            element->show();
            count = 1;
        }
    }
    return count;
}

int Role::Addskill(int choose)
{
    int i = 0;
    switch (choose)
    {
    case 1: {
        // ʹ�õ��������� set ������Ԫ��
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 1) {
                if (!element->get_is_can_use()) {
                    cout << "��ü���" << endl;
                    element->show();
                }
                element->can();
            }
        }
        return 1;
    }
    case 2: {
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 2) {
                if (!element->get_is_can_use()) {
                    cout << "��ü���" << endl;
                    element->show();
                }
                element->can();
            }
        }
        return 1;
    }
    case 3:
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 3) {
                if (!element->get_is_can_use()) {
                    cout << "��ü���" << endl;
                    element->show();
                }
                element->can();
            }
        }
        return 1;
    default:
        cout << "��������������ļ���" << endl;
        break;
    }
}
// TODO: ��Ӷ�ս�߼���Ŀǰʹ�ü��ܺͼ��ܽ���֮��û�ж�ս��
void Role::Useskill(Role& enemy)
{
    int choose = 0;
    if (!showskill()) {
        cout << "��û�м��ܿ���ʹ��" << endl;
    }
    else {
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
                    cout << "��ʹ����1����";
                    element->Motor_skill_start(*this, enemy);
                    element->Motor_skill_end(*this, enemy);
                }
            }
            break;
        }
        case 2: {
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 2) {
                    cout << "��ʹ����2����";
                    element->Motor_skill_start(*this, enemy);
                    element->Motor_skill_end(*this, enemy);
                }
            }
            break;
        }
        case 3:
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 3) {
                    cout << "��ʹ����3����";
                    element->Motor_skill_start(*this, enemy);
                    element->Motor_skill_end(*this, enemy);
                }
            }
            break;
        default:
            cout << "��������������ļ���" << endl;
            break;
        }
    }
    
}


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
        
        if (level > 4 && level < 7) {
            Addskill(1);
        }
        else if(level < 10) {
            Addskill(1);
            Addskill(2);
        }
        else {
            Addskill(1);
            Addskill(2);
            Addskill(3);
        }
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
void Role::increaseDEF(int defenseIncrease) {
    DEF += defenseIncrease;
}
//���ӷ���
void Role::setDEF(int i) {
    DEF = i;
}