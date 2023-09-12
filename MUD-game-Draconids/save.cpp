#include "save.h"

void save(Role& character) {
    std::ofstream out_roleFile("roleData.txt");

    if (out_roleFile.is_open()) {
        //out_roleFile << character.getname() << "\n";
        //out_roleFile << character.getHP() << "\n";
        //out_roleFile << character.getAttack() << "\n";
        //out_roleFile << character.getDEF() << "\n";
        //out_roleFile << character.getAgility() << "\n";
        //out_roleFile << character.getlife() << "\n";
        //out_roleFile << character.getmoney() << "\n";
        //out_roleFile << character.getlevel() << "\n";
        //out_roleFile << character.getEXP() << "\n";
        out_roleFile << character.getname() << ' '
            << character.getHP() << ' '
            << character.getAttack() << ' '
            << character.getDEF() << ' '
            << character.getAgility() << ' '
            << character.getlife() << ' '
            << character.getmoney() << ' '
            << character.getlevel() << ' '
            << character.getEXP() << ' '
            << character.get_skill();
        out_roleFile.close();
    }
    else {
        std::cout << "�浵ʧ��  \n";
    }



    //std::ofstream out_skillFile("skillData.txt", std::ios::binary);
    //if (!out_skillFile)
    //{
    //    std::cerr << "�浵ʧ��  \n ";
    //}

    //// д��Skill_vector�Ĵ�С���ļ�
    //size_t size = Skill_vector.size();
    //out_skillFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    //// ����Skill_vector�е�ÿ��Ԫ�أ����д���Ա������ֵ���ļ�
    ////for (const auto& skill : Skill_vector)
    ////{
    ////    out_skillFile.write(skill->get_name().c_str(), skill->get_name().size() + 1); // ע�⣺����д����null��ֹ��
    ////    out_skillFile.write(skill->get_effect().c_str(), skill->get_effect().size() + 1);
    ////    out_skillFile.write(skill->get_introduce().c_str(), skill->get_introduce().size() + 1);
    ////}
    //out_skillFile.close();
    //std::cout << "�浵�ɹ�" << std::endl;
    


    //ofstream out_bagFile("SaveBag.dat", ios_base::binary);

    //if ( !out_bagFile ) {
    //    cout << "�޷��򿪱����ļ���" << endl;
    //    cout << "����ʧ�ܣ�" << endl;
    //}
    //else
    //{
    //    for (const auto& i : Bag.getMapBags()) {
    //        out_bagFile << i.first << ' ' << i.second << ' ';
    //    }
    //    cout << "����ɹ���" << endl;
    //}
    //out_bagFile.close();

 }