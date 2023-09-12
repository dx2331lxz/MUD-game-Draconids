#include"Role.h"


Role::Role(string name, int HP, int attack, int DEF, int Agility, int life, int money, int level) :name(name), HP(HP), attack(attack), DEF(DEF), Agility(Agility), life(life), money(money), level(level), EXP(0) {

    Skill_vector.insert(std::make_unique<GUI>());
    Skill_vector.insert(std::make_unique<SHEN>());
    Skill_vector.insert(std::make_unique<XI>());
}

Role::Role(const Role& role):name(role.name),HP(role.HP),attack(role.attack), DEF(role.DEF), Agility(role.Agility), life(role.life), money(role.life), EXP(role.EXP), weapon(role.weapon)
{
    int i = 0;
    int count = 0;
    // 使用迭代器遍历 set
    for (const unique_ptr<Skill>& element : role.Skill_vector) {

        if (element->get_is_can()) {

            count ++;
        }
    }

    for (const unique_ptr<Skill>& element : Skill_vector) {
        i++;
        if (i <= count) {
            element->can();
        }
    }
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

int Role::get_skill()
{
    int count = 0;
    for (const unique_ptr<Skill>& element : Skill_vector) {

        if (element->get_is_can()) {

            count++;
        }
    }
    return count;
}

void Role::set_skill(int size)
{
    int i = 0;
    for (const unique_ptr<Skill>& element : Skill_vector) {
        i++;
        if (i <= size) {
            element->can();
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
    //for (int i = 0; goodsId[i] >= 0; i++)
    //    if (goodsId[i] == 6 || goodsId[i] == 8 || goodsId[i] == 19) {
    //        task.setGoods(goods[goodsId[i]]);
    //        task.setIsTaskEnd();
    //    }
    //if (bag.getGoodsNum() > 14) {
    //    cout << "背包已满，无法添加。" << endl;
    //}
    //else if (bag.getGoodsNum() + num[0] + num[1] + num[2] + num[3] > 14) {
    //    cout << "背包剩余空位不足，无法完全添加。" << endl;
    //    cout << "你仅能添加" << 14 - bag.getGoodsNum() << "件。" << endl;
    //    cout << "请选择要添加的物品：";
    //    for (int chioce = 0; num[chioce] == 0 || bag.getGoodsNum() >= 14;) {
    //        cin >> chioce;
    //        if (num[chioce] + bag.getGoodsNum() > 14) {
    //            bag.addGoods(goodsId[chioce], 14 - bag.getGoodsNum());
    //            cout << "成功添加" << 14 - bag.getGoodsNum() << "件到背包！" << endl << endl;
    //        }
    //        else {
    //            bag.addGoods(goodsId[chioce], num[chioce]);
    //            cout << "成功添加" << num[chioce] << "件到背包！" << endl << endl;
    //        }
    //    }
    //}
    //else {
        for (int i = 0; goodsId[i] >= 0; i++)
            bag.addGoods(goodsId[i], num[i]);
        cout << "全部成功添加到背包！" << endl << endl;
   /* }*/
}

void Role::addSaveGoodsToBag(int goodsId, int num) {
    bag.addGoods(goodsId, num);
}

void Role::addGoodsToBag(int goodsId, int num) {
    cout << endl << "得到了：" << endl;

    bag.showGoods(goodsId, num);
    //if (bag.getGoodsNum() > 14) {
    //    cout << "背包已满，无法添加。" << endl;
    //}
    //else if (bag.getGoodsNum() + num > 14) {
    //    cout << "背包剩余空位不足，无法完全添加。" << endl;
    //    cout << "你仅能添加" << 14 - bag.getGoodsNum() << "件。" << endl;
    //    cout << "请选择要添加的物品：";
    //    for (int chioce = 0; num == 0 || bag.getGoodsNum() >= 14;) {
    //        cin >> chioce;
    //        if (num + bag.getGoodsNum() > 14) {
    //            bag.addGoods(goodsId, 14 - bag.getGoodsNum());
    //            cout << "成功添加" << 14 - bag.getGoodsNum() << "件到背包！" << endl << endl;
    //        }
    //        else {
    //            bag.addGoods(goodsId, num);
    //            cout << "成功添加" << num << "件到背包！" << endl << endl;
    //        }
    //    }
    //}
    //else {
        bag.addGoods(goodsId, num);
        cout << "全部成功添加到背包！" << endl << endl;
  /*  }*/
}

bool Role::subGoodsToBag(int goodsId, int num) {
    return bag.reduceGoods(goodsId, num);
}

void Role::setBag(Bag &bags) {
    bag = bags;
}

void Role::newBag() {
    Bag bags;
    bag = bags;
}

void Role::useDrug() {
    if (bag.isUseDrug()) {
        cout << "是否使用药品：	1.是	2.否" << endl;
        int choice;
        cin >> choice;
        if (choice == 2)
            return;
        if (choice == 1) {
            cout << "请选择要使用的药品：" << endl;
            for (int i = bag.getGoodsNum(); i > 0; i--) {
                for (int j = 12; j < 14; j++)
                    if (getBagWhichGoodsId(i) == j)
                        cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " 件" << endl;
            }
            cout << "0.取消" << endl;
            int choiceGoodsId, choiceGoodsNum;
            while (true) {
                cin >> choiceGoodsId;
                if (choiceGoodsId < 0 || choiceGoodsId > bag.getGoodsNum())
                    cout << "选择错误，请重新选择！" << endl;
                else break;
            }
            choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
            cout << "请选择使用多少（输入0取消）：" << endl;
            cin >> choiceGoodsNum;
            subGoodsToBag(choiceGoodsId, choiceGoodsNum);
            cout << "成功使用药品！";
            if (choiceGoodsId == 12 || choiceGoodsId == 13) {
                for (int i = choiceGoodsNum; i > 0; i--)
                    setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
                cout << "共恢复" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "点血量。" << endl << endl;
            }
            if (choiceGoodsId == 0) return;
        }
    }
}

int Role::getHealth() {
    return HP;
}

int Role::getHealth_max() {
    return 100;
}

void Role::setHealth(int hp) {
    HP = hp;
    if (hp > 100)
        HP = 100;
    if (HP < 0)
        HP = 0;
}

void Role::showEquip()
{
    cout << "当前已装备:" << endl;
    cout << "武器:";
    if (weapon == -1) {
        cout << "无" << endl;
    }
    else {
        cout << goods[weapon].getName() << endl;
    }
    cout << "防具:";
    if (clothes == -1) {
        cout << "无" << endl;
    }
    else {
        cout << goods[clothes].getName() << endl;
    }
}

void Role::wearEquip(int id)
{
    if (goods[id].getType() == 0) {
        if (weapon != -1) {
            removeEquip(weapon);
        }
        setAttack(getAttack() + goods[id].getAddAttack());
        weapon = id;
    }
    else if (goods[id].getType() == 1) {
        if (clothes != -1) {
            removeEquip(clothes);
        }
        setDefend(getDEF() + goods[id].getAddDefend());
        setAgility(getAgility() + goods[id].getAddAGI());
        clothes = id;
    }
    bag.reduceGoods(id, 1);
    cout << "已装备 " << goods[id].getName() << endl;
}

void Role::removeEquip(int id)
{
    if (goods[id].getType() == 0) {
        if (weapon != -1) {
            cout << "当前无武器" << endl;
        }
        setAttack(getAttack() - goods[id].getAddAttack());
        weapon = -1;
    }
    else if (goods[id].getType() == 1) {
        if (clothes != -1) {
            cout << "当前无防具" << endl;
        }
        setDefend(getDEF() - goods[id].getAddDefend());
        clothes = -1;
    }
    bag.addGoods(id, 1);
    cout << "已换下 " << goods[id].getName() << endl;
}

int Role::getWeapon()
{
    return weapon;
}

void Role::setWeapon(int w)
{
    weapon = w;
}

int Role::getClothes()
{
    return clothes;
}

void Role::setClothes(int c)
{
    clothes = c;
}

void Role::setAttack(int a) {
    attack = a;
}

void Role::setDefend(int d) {
    DEF = d;
}
void Role::setAgility(int a) {
    Agility = a;
}