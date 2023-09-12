#include"Role.h"


Role::Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level) :name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), life(life), money(money), level(level), EXP(0) {

    Skill_vector.insert(std::make_unique<GUI>());
    Skill_vector.insert(std::make_unique<SHEN>());
    Skill_vector.insert(std::make_unique<XI>());
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
    int count = 0;
    // ʹ�õ��������� set
    for (const unique_ptr<Skill>& element : Skill_vector) {
        
        size++;
        if (element->get_is_can()) {
            cout << size << ". ";
            element->show();
            count = 1;
        }
    }
    return count;
}

void Role::Addskill(int choose)
{
    int i = 0;

    switch (choose)
    {
    case 1: {
        // ʹ�õ��������� set ������Ԫ��
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 1) {
                if (!element->get_is_can()) {
                    cout << "��ϲ���ü��ܣ�" << endl;
                    element->show();
                }
                element->can();
            }
        }
        break;
    }
    case 2: {
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (!element->get_is_can()) {
                cout << "��ϲ���ü��ܣ�" << endl;
                element->show();
            }
            element->can();
        }
        break;
    }
    case 3:
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (!element->get_is_can()) {
                cout << "��ϲ���ü��ܣ�" << endl;
                element->show();
            }
            element->can();
        }
        break;
    default:
        cout << "��������������ļ���" << endl;
        break;
    }
}
// TODO: ��Ӷ�ս�߼���Ŀǰʹ�ü��ܺͼ��ܽ���֮��û�ж�ս��
void Role::Useskill(Role& enemy)
{
    if (!showskill()) {
        cout << "����δѧϰ�κμ���" << endl;
    }
    else
    {
        int choose = 0;
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
        if(level < 3){
        }
        else if (level >= 3 && level < 10) {
            Addskill(1);
        }
        else if (level <= 16) {
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
