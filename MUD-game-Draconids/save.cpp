#include "save.h"

void save(Role& character, std::set<std::unique_ptr<Skill>>& Skill_vector, std::string& skillData,Bag& Bag) {
    std::ofstream out_roleFile("roleData.txt");

    if (out_roleFile.is_open()) {
        out_roleFile << character.getname() << "\n";
        out_roleFile << character.getHP() << "\n";
        out_roleFile << character.getAttack() << "\n";
        out_roleFile << character.getDEF() << "\n";
        out_roleFile << character.getAgility() << "\n";
        out_roleFile << character.getlife() << "\n";
        out_roleFile << character.getmoney() << "\n";
        out_roleFile << character.getlevel() << "\n";
        out_roleFile << character.getEXP() << "\n";
        out_roleFile.close();
    }
    else {
        std::cout << "存档失败  \n";
    }



    //std::ofstream out_skillFile("skillData.txt", std::ios::binary);
    //if (!out_skillFile)
    //{
    //    std::cerr << "存档失败  \n ";
    //}

    //// 写入Skill_vector的大小到文件
    //size_t size = Skill_vector.size();
    //out_skillFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    //// 对于Skill_vector中的每个元素，逐个写入成员变量的值到文件
    ////for (const auto& skill : Skill_vector)
    ////{
    ////    out_skillFile.write(skill->get_name().c_str(), skill->get_name().size() + 1); // 注意：这里写入了null终止符
    ////    out_skillFile.write(skill->get_effect().c_str(), skill->get_effect().size() + 1);
    ////    out_skillFile.write(skill->get_introduce().c_str(), skill->get_introduce().size() + 1);
    ////}
    //out_skillFile.close();
    //std::cout << "存档成功" << std::endl;
    


    //ofstream out_bagFile("SaveBag.dat", ios_base::binary);

    //if ( !out_bagFile ) {
    //    cout << "无法打开保存文件！" << endl;
    //    cout << "保存失败！" << endl;
    //}
    //else
    //{
    //    for (const auto& i : Bag.getMapBags()) {
    //        out_bagFile << i.first << ' ' << i.second << ' ';
    //    }
    //    cout << "保存成功！" << endl;
    //}
    //out_bagFile.close();

 }