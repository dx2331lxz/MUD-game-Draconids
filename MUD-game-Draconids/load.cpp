#include"load.h"



void load(Role& character, std::set<std::unique_ptr<Skill>>& Skill_vector, std::string& skillData, Bag& Bag) {
    std::ifstream in_roleFile("roleData.txt");
    if (in_roleFile.is_open()) {
        std::string name;
        int HP, attack, DEF, Agility, dodge, life, money, level, EXP;

        // 从文件中读取角色信息
        in_roleFile >> name;
        in_roleFile >> HP;
        in_roleFile >> attack;
        in_roleFile >> DEF;
        in_roleFile >> Agility;
        in_roleFile >> dodge;
        in_roleFile >> life;
        in_roleFile >> money;
        in_roleFile >> level;
        in_roleFile >> EXP;

        // 将读入的信息存入角色对象
       Role character(name, HP, attack, DEF, Agility, life, money, level);
       character.addExp(EXP);
        in_roleFile.close();
    }
    else {
        std::cout << "读取失败\n";
    }

    std::ifstream in_skillFile("skillData.txt");

    if (in_skillFile.is_open()) {
        std::string name, effect, introduce;
        while (in_skillFile >> name >> effect >> introduce) {
            // 在此处处理读取到的数据
            // 处理完成后，将 Skill 对象存储到相应的容器中
            Skill_vector.insert(std::make_unique<GUI>());
            Skill_vector.insert(std::make_unique<SHEN>());
            Skill_vector.insert(std::make_unique<XI>());
        }
        in_skillFile.close();
    }
    else {
        std::cout << "读取失败\n";
    }


    ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);

    for (int key2 = 24; !fileBag.eof();) {

        int key;
        int value;
        fileBag >> key >> value;
        if (key2 == key)
            break;
        //character  bag.addSaveGoodsToBag(key, value);
        key2 = key;

    }
    fileBag.close();

}