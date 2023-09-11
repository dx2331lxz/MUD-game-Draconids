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
int Role::showskill()
{
    int size = 0;
    int count = 0;
    // 使用迭代器遍历 set
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
        // 使用迭代器遍历 set 并访问元素
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 1) {
                if (!element->get_is_can_use()) {
                    cout << "获得技能" << endl;
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
                    cout << "获得技能" << endl;
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
                    cout << "获得技能" << endl;
                    element->show();
                }
                element->can();
            }
        }
        return 1;
    default:
        cout << "并不存在您输入的技能" << endl;
        break;
    }
}
// TODO: 添加对战逻辑（目前使用技能和技能结束之间没有对战）
void Role::Useskill(Role& enemy)
{
    int choose = 0;
    if (!showskill()) {
        cout << "您没有技能可以使用" << endl;
    }
    else {
        cout << "选择你想要使用的技能(只接受技能前面的数字)：" << endl;
        cin >> choose;
        if (choose == 0) {
            cout << "并不存在您输入的技能" << endl;
        }
        int i = 0;
        switch (choose)
        {
        case 1: {
            // 使用迭代器遍历 set 并访问元素
            for (const unique_ptr<Skill>& element : Skill_vector) {
                i++;
                if (i == 1) {
                    cout << "您使用了1技能";
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
                    cout << "您使用了2技能";
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
                    cout << "您使用了3技能";
                    element->Motor_skill_start(*this, enemy);
                    element->Motor_skill_end(*this, enemy);
                }
            }
            break;
        default:
            cout << "并不存在您输入的技能" << endl;
            break;
        }
    }
    
}


// ... (其他成员函数的定义)

void Role::addExp(int addExp) {
    EXP += addExp;
    auto level_ = level;
    for (int i = 0; i < 29; i++) {
        if (levelExp_Max[i] <= EXP) {

            level = i + 1;
        }
    }
    if (level_ < level) {
        cout << "生啦生啦， 恭喜你已经到达" << level << "级啦！！" << endl;
        
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
//增加防御
void Role::setDEF(int i) {
    DEF = i;
}