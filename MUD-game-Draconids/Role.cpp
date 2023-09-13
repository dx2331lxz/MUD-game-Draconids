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
    // ʹ�õ��������� set
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
        if (level < 3) {
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
    cout << endl << "�õ��ˣ�" << endl;

    bag.showGoods(goodsId, num);
    //for (int i = 0; goodsId[i] >= 0; i++)
    //    if (goodsId[i] == 6 || goodsId[i] == 8 || goodsId[i] == 19) {
    //        task.setGoods(goods[goodsId[i]]);
    //        task.setIsTaskEnd();
    //    }
    //if (bag.getGoodsNum() > 14) {
    //    cout << "�����������޷���ӡ�" << endl;
    //}
    //else if (bag.getGoodsNum() + num[0] + num[1] + num[2] + num[3] > 14) {
    //    cout << "����ʣ���λ���㣬�޷���ȫ��ӡ�" << endl;
    //    cout << "��������" << 14 - bag.getGoodsNum() << "����" << endl;
    //    cout << "��ѡ��Ҫ��ӵ���Ʒ��";
    //    for (int chioce = 0; num[chioce] == 0 || bag.getGoodsNum() >= 14;) {
    //        cin >> chioce;
    //        if (num[chioce] + bag.getGoodsNum() > 14) {
    //            bag.addGoods(goodsId[chioce], 14 - bag.getGoodsNum());
    //            cout << "�ɹ����" << 14 - bag.getGoodsNum() << "����������" << endl << endl;
    //        }
    //        else {
    //            bag.addGoods(goodsId[chioce], num[chioce]);
    //            cout << "�ɹ����" << num[chioce] << "����������" << endl << endl;
    //        }
    //    }
    //}
    //else {
        for (int i = 0; goodsId[i] >= 0; i++)
            bag.addGoods(goodsId[i], num[i]);
        cout << "ȫ���ɹ���ӵ�������" << endl << endl;
   /* }*/
}

void Role::addSaveGoodsToBag(int goodsId, int num) {
    bag.addGoods(goodsId, num);
}

void Role::addGoodsToBag(int goodsId, int num) {
    cout << endl << "�õ��ˣ�" << endl;

    bag.showGoods(goodsId, num);
    //if (bag.getGoodsNum() > 14) {
    //    cout << "�����������޷���ӡ�" << endl;
    //}
    //else if (bag.getGoodsNum() + num > 14) {
    //    cout << "����ʣ���λ���㣬�޷���ȫ��ӡ�" << endl;
    //    cout << "��������" << 14 - bag.getGoodsNum() << "����" << endl;
    //    cout << "��ѡ��Ҫ��ӵ���Ʒ��";
    //    for (int chioce = 0; num == 0 || bag.getGoodsNum() >= 14;) {
    //        cin >> chioce;
    //        if (num + bag.getGoodsNum() > 14) {
    //            bag.addGoods(goodsId, 14 - bag.getGoodsNum());
    //            cout << "�ɹ����" << 14 - bag.getGoodsNum() << "����������" << endl << endl;
    //        }
    //        else {
    //            bag.addGoods(goodsId, num);
    //            cout << "�ɹ����" << num << "����������" << endl << endl;
    //        }
    //    }
    //}
    //else {
        bag.addGoods(goodsId, num);
        cout << "ȫ���ɹ���ӵ�������" << endl << endl;
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
        cout << "�Ƿ�ʹ��ҩƷ��	1.��	2.��" << endl;
        int choice;
        int num1;
        cin >> choice;
        if (choice == 2)
            return;
        if (choice == 1) {
            cout << "��ѡ��Ҫʹ�õ�ҩƷ��" << endl;
            for (int i = bag.getGoodsNum(); i > 0; i--) {
                for (int j = 12; j < 14; j++)
                    if (getBagWhichGoodsId(i) == j){
                        cout << i << "." << '\t' << goods[getBagWhichGoodsId(i)].getName() << '\t' << getBagWhichGoodsNum(i) << " ��" << endl;
                        num1 = getBagWhichGoodsNum(i);
                    }
            }
            cout << "0.ȡ��" << endl;
            int choiceGoodsId, choiceGoodsNum;
            while (true) {
                cin >> choiceGoodsId;
                if (choiceGoodsId < 0 || choiceGoodsId > bag.getGoodsNum())
                    cout << "ѡ�����������ѡ��" << endl;
                else break;
            }
   
            choiceGoodsId = getBagWhichGoodsId(choiceGoodsId);
            cout << "��ѡ��ʹ�ö��٣�����0ȡ������" << endl;
            cin >> choiceGoodsNum;
            if (num1 < choiceGoodsNum) {
                cout << "����ӵ�����������Զ����Ŀ�ʹ���������:" << num1 << endl;
                choiceGoodsNum = num1;
            }
            subGoodsToBag(choiceGoodsId, choiceGoodsNum);//��ȥʹ�õ���Ʒ
            if(choiceGoodsNum)
            cout << "�ɹ�ʹ��ҩƷ��";
            if (choiceGoodsId == 12 || choiceGoodsId == 13) {
                for (int i = choiceGoodsNum; i > 0; i--)
                    setHealth(goods[choiceGoodsId].getAddHP() + getHealth());
                cout << "���ָ�" << goods[choiceGoodsId].getAddHP() * choiceGoodsNum << "��Ѫ����" << endl;
                if (getHealth() == 100) cout << "�ѵ�����Ѫ״̬��(HP = 100)" << endl;
                cout << endl;
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
    cout << "��ǰ��װ��:" << endl;
    cout << "����:";
    if (weapon == -1) {
        cout << "��" << endl;
    }
    else {
        cout << goods[weapon].getName() << endl;
    }
    cout << "����:";
    if (clothes == -1) {
        cout << "��" << endl;
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
    cout << "��װ�� " << goods[id].getName() << endl;
}

void Role::removeEquip(int id)
{
    if (goods[id].getType() == 0) {
        if (weapon == -1) {
            cout << "��ǰ������" << endl;
        }
        setAttack(getAttack() - goods[id].getAddAttack());
        weapon = -1;
    }
    else if (goods[id].getType() == 1) {
        if (clothes == -1) {
            cout << "��ǰ�޷���" << endl;
        }
        setDefend(getDEF() - goods[id].getAddDefend());
        clothes = -1;
    }
    bag.addGoods(id, 1);
    cout << "�ѻ��� " << goods[id].getName() << endl;
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