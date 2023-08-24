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

int Role::showskill()
{
    int size = 0;
    if (Skill_vector.size() == 0) {
        cout << "技能不存在" << endl;
    }
    else {
        // 使用迭代器遍历 set
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
    //    std::cout << "不可重复添加技能" << std::endl;
    //}
    //else {
    //    cout << "添加成功" << endl;
    //    Skill_vector.push_back(skill);
    //}
    //return Skill_vector.size();
    auto result = Skill_vector.insert(std::move(skill));

    if (result.second) {
        std::cout << "添加成功" << std::endl;
    }
    else {
        std::cout << "不可重复添加技能" << std::endl;
    }

    return Skill_vector.size();
}
// TODO: 添加对战逻辑（目前使用技能和技能结束之间没有对战）
void Role::Useskill(int choose)
{
    if (showskill()) {
    }
    else
    {
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
            cout << "并不存在您输入的技能" << endl;
            break;
        }
    }
    
}
