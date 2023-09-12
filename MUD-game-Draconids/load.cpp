#include"load.h"



Role& load() {
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
       return character;
    }
    else {
        std::cout << "读取失败\n";
    }

    //ifstream fileBag("SaveBag.dat", ios_base::in | ios_base::binary);

    //for (int key2 = 14; !fileBag.eof();  ) {
    //    
    //    int ID;
    //    int number;
    //    fileBag >> ID >> number;
    //    if (key2 == ID)
    //        break;
    //    //character  bag.addSaveGoodsToBag(key, value);


    //}
    //fileBag.close();

}