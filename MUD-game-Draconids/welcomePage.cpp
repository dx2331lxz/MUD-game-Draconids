#include <iostream>
#include <thread>
#include "main.h"
#include <stdlib.h>

//��ӭ����
void welcomePage() {
    std::cout << "                                                                                   " << std::endl;
    std::cout << "                 0                                                                 " << std::endl;
    std::cout << "                 0        00                  0         0                          " << std::endl;
    std::cout << "                 0         00                 0         0  00000000                " << std::endl;
    std::cout << "         000000000000000000000000        000000000000  0                           " << std::endl;
    std::cout << "               0    00                       0          0  0000000                 " << std::endl;
    std::cout << "               0    00                       0         0      0                    " << std::endl;
    std::cout << "               0    00                       0  0000    0000000000000              " << std::endl;
    std::cout << "              0     00     0                0      0          0                    " << std::endl;
    std::cout << "              0     00    0                 0      0         0 0                   " << std::endl;
    std::cout << "              0     00   0                 0      0         0   0                  " << std::endl;
    std::cout << "             0         0            0    0      0         0      0                 " << std::endl;
    std::cout << "            0        0  0000000000000           0        0        0                " << std::endl;
    std::cout << "___________________________________________________________________________________" << std::endl;
    std::cout << "|���ְ桶���塷                                                                   |" << std::endl;
    std::cout << "|��Ϸ���ܣ�һ���򵥵�����RPG��Ϸ                                                  |" << std::endl;
    std::cout << "|�汾��1.0                                                                        |" << std::endl;
    std::cout << "|_________________________________________________________________________________|" << std::endl;
    std::cout << std::endl;
    std::string startSentence = "1���µĿ�ʼ   2������ս��   3���˳���Ϸ";
    int index = 0;


    while (index < startSentence.length()) {
        std::cout << startSentence[index++];
        std::cout.flush();//�����������������ַ�
        std::this_thread::sleep_for(std::chrono::milliseconds(50));//ʹ����ֹͣ50ms
    }
    //�ӳ�50ms����ַ�
    std::cout << std::endl;
    int startChoose = 0;
    cin >> startChoose;
    //if (startChoose == 1) {
    //    // ���ļ�
    //    std::ofstream outFile("role.dat", std::ios::binary);

    //    // �����������д���ļ�
    //    if (outFile.is_open()) {
    //        // д������
    //        int nameLength = Role.name.length();
    //        outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(int));
    //        outFile.write(Role.name.c_str(), nameLength);

    //        // д��HP
    //        outFile.write(reinterpret_cast<char*>(&Role.HP), sizeof(int));
    //        
    //        // д�빥��
    //        outFile.write(reinterpret_cast<char*>(&Role.attack), sizeof(int));

    //        // д�����
    //        outFile.write(reinterpret_cast<char*>(&Role.DEF), sizeof(int));

    //        // д������
    //        outFile.write(reinterpret_cast<char*>(&Role.Agility), sizeof(int));

    //        // д������
    //        outFile.write(reinterpret_cast<char*>(&Role.dodge), sizeof(double));

    //        // д������
    //        outFile.write(reinterpret_cast<char*>(&Role.life), sizeof(int));

    //        // д����
    //        outFile.write(reinterpret_cast<char*>(&Role.money), sizeof(int));

    //        // д��ȼ�
    //        outFile.write(reinterpret_cast<char*>(&Role.level), sizeof(int));

    //        // д�뾭��
    //        outFile.write(reinterpret_cast<char*>(&Role.EXP), sizeof(int));

    //        // �ر��ļ�
    //        outFile.close();

    //    }
    //    else {
    //        std::cerr << "�浵ʧ�ܣ�" << std::endl;
    //    }
    //}
    //}// �����µĴ浵������introduce����ʼ��Ϸ
    //if (startChoose == 2) {

    //}//��ȡ�ɵĴ浵����ʼ��Ϸ
    if (startChoose == 3) {
        std::string byeSentence = "�ٻ�";
        index = 0;

        while (index < byeSentence.length()) {
            std::cout << byeSentence[index++];
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << std::endl;
        std::string quitSentence = "press any key to quit...";
        index = 0;

        while (index < quitSentence.length()) {
            std::cout << quitSentence[index++];
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << std::endl;
        getchar();
        exit(0);
    }//�˳���Ϸ
}