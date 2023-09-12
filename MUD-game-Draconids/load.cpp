#include"load.h"



void load(Role& character, const std::vector<std::unique_ptr<Skill>>& Skill_vector, const std::string& skillData, Bag& Bag) {
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
            Skill skill(name, effect, introduce);

            // 处理完成后，将 Skill 对象存储到相应的容器中
            Skill_vector.push_back(skill);
        }
        in_skillFile.close();
    }
    else {
        std::cout << "读取失败\n";
    }

    std::ifstream in_bagFile("bagData.txt");

    if (in_bagFile.is_open()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 2; j++) {
                in_bagFile >> Bag.saveGoods[i][j];
            }
        }
        in_bagFile.close();
    }
    else {
        std::cout << "读取失败\n";
    }
}