#include"Role.h"

Role::Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level):name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), life(life), money(money), level(level), EXP(0)
{
    Skill_vector.insert(std::make_unique<GUI>());
    Skill_vector.insert(std::make_unique<SHEN>());
    Skill_vector.insert(std::make_unique<XI>());
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
        // 使用迭代器遍历 set 并访问元素
        for (const unique_ptr<Skill>& element : Skill_vector) {
            i++;
            if (i == 1) {
                if (!element->get_is_can()) {
                    cout << "恭喜你获得技能：" << endl;
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
                cout << "恭喜你获得技能：" << endl;
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
                cout << "恭喜你获得技能：" << endl;
                element->show();
            }
            element->can();
        }
        break;
    default:
        cout << "并不存在您输入的技能" << endl;
        break;
    }
}
// TODO: 添加对战逻辑（目前使用技能和技能结束之间没有对战）
void Role::Useskill(Role& enemy)
{
    if (!showskill()) {
        cout << "您还未学习任何技能" << endl;
    }
    else
    {
        int choose = 0;
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

int Role::getMoney()
{
    return money;
}

void Role::setMoney(int m) {
    money = m;
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

Bag Role::getBag() {
    return bag;
}

void Role::showBag() {
    bag.showBags();
}

int Role::getBagWhichGoodsId(int whichGoods) {
    return bag.getWhichGoodsId(whichGoods);

}

int Role::getBagWhichGoodsNum(int whichGoods) {
    return bag.getWhichGoodsNum(whichGoods);

}

void Role::addGoodsToBag(int* goodsId, int* num) {
    cout << endl << "得到了：" << endl;

    bag.showGoods(goodsId, num);
    /*for (int i = 0; goodsId[i] >= 0; i++)
        if (goodsId[i] == 6 || goodsId[i] == 8 || goodsId[i] == 19) {
            task.setGoods(goods[goodsId[i]]);
            task.setIsTaskEnd();
        }*/
    if (bag.getGoodsNum() > 14) {
        cout << "背包已满，无法添加。" << endl;
    }
    else if (bag.getGoodsNum() + num[0] + num[1] + num[2] + num[3] > 14) {
        cout << "背包剩余空位不足，无法完全添加。" << endl;
        cout << "你仅能添加" << 14 - bag.getGoodsNum() << "件。" << endl;
        cout << "请选择要添加的物品：";
        for (int chioce = 0; num[chioce] == 0 || bag.getGoodsNum() >= 14;) {
            cin >> chioce;
            if (num[chioce] + bag.getGoodsNum() > 14) {
                bag.addGoods(goodsId[chioce], 14 - bag.getGoodsNum());
                cout << "成功添加" << 14 - bag.getGoodsNum() << "件到背包！" << endl << endl;
            }
            else {
                bag.addGoods(goodsId[chioce], num[chioce]);
                cout << "成功添加" << num[chioce] << "件到背包！" << endl << endl;
            }
        }
    }
    else {
        for (int i = 0; goodsId[i] >= 0; i++)
            bag.addGoods(goodsId[i], num[i]);
        cout << "全部成功添加到背包！" << endl << endl;
    }
}



void Role::addGoodsToBag(int goodsId, int num) {
    cout << endl << "得到了：" << endl;

    bag.showGoods(goodsId, num);
    if (bag.getGoodsNum() > 14) {
        cout << "背包已满，无法添加。" << endl;
    }
    else if (bag.getGoodsNum() + num > 14) {
        cout << "背包剩余空位不足，无法完全添加。" << endl;
        cout << "你仅能添加" << 14 - bag.getGoodsNum() << "件。" << endl;
        cout << "请选择要添加的物品：";
        for (int chioce = 0; num == 0 || bag.getGoodsNum() >= 14;) {
            cin >> chioce;
            if (num + bag.getGoodsNum() > 14) {
                bag.addGoods(goodsId, 14 - bag.getGoodsNum());
                cout << "成功添加" << 14 - bag.getGoodsNum() << "件到背包！" << endl << endl;
            }
            else {
                bag.addGoods(goodsId, num);
                cout << "成功添加" << num << "件到背包！" << endl << endl;
            }
        }
    }
    else {
        bag.addGoods(goodsId, num);
        cout << "全部成功添加到背包！" << endl << endl;
    }
}

bool Role::subGoodsToBag(int goodsId, int num) {
    return bag.reduceGoods(goodsId, num);
}

void Role::setBag(Bag bags) {
    bag = bags;
}
