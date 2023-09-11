#include "save.h"

void save(Role& character, const std::vector<std::unique_ptr<Skill>>& Skill_vector, const std::string& skillData,Bag& Bag) {
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
        std::cout << "�浵ʧ��  \n";
    }


        std::ofstream out_skillFile("skillData.txt", std::ios::binary);
        if (!out_skillFile)
        {
            std::cerr << "�浵ʧ��  \n ";
        }

        // д��Skill_vector�Ĵ�С���ļ�
        size_t size = Skill_vector.size();
        out_skillFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

        // ����Skill_vector�е�ÿ��Ԫ�أ����д���Ա������ֵ���ļ�
        for (const auto& skill : Skill_vector)
        {
            out_skillFile.write(skill->getname().c_str(), skill->getname().size() + 1); // ע�⣺����д����null��ֹ��
            out_skillFile.write(skill->geteffect().c_str(), skill->geteffect().size() + 1);
            out_skillFile.write(skill->getintroduce().c_str(), skill->getintroduce().size() + 1);
        }

        out_skillFile.close();
        std::cout << "�浵�ɹ�" << std::endl;
    


        ofstream fileBag("SaveBag.dat", ios_base::binary);

        if ( !fileBag ) {
            cout << "�޷��򿪱����ļ���" << endl;
            cout << "����ʧ�ܣ�" << endl;
        }
        else
        {
            for (const auto& i : Bag.getMapBags()) {
                fileBag << i.first << ' ' << i.second << ' ';
            }
            cout << "����ɹ���" << endl;
        }
        fileBag.close();

 }