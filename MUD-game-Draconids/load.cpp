#include"load.h"



Role load() {
    std::ifstream in_roleFile("./roleData.txt");
    if (in_roleFile.is_open()) {

        string name;
        int HP, attack, DEF, Agility, life, money, level, EXP, Weapon, size;
        // ���ļ��ж�ȡ��ɫ��Ϣ
        //in_roleFile >> name;
        //in_roleFile >> HP;
        //in_roleFile >> attack;
        //in_roleFile >> DEF;
        //in_roleFile >> Agility;
        //in_roleFile >> life;
        //in_roleFile >> money;
        //in_roleFile >> level;
        //in_roleFile >> EXP;
        in_roleFile >> name >> HP >> attack >> DEF >> Agility >> life >> money >> level >> EXP >> Weapon >>size;
        
        // ���������Ϣ�����ɫ����
        Role character(name, HP, attack, DEF, Agility, life, money, level);
        character.set_skill(size);
        character.setWeapon(Weapon);
        character.addExp(EXP);
        in_roleFile.close();
        return character;
    }
    else {
        std::cout << "��ȡʧ��\n";
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