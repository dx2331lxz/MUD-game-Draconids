#include <iostream>
#include <thread>
#include "main.h"
#include <stdlib.h>

//欢迎界面
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
    std::cout << "|文字版《龙族》                                                                   |" << std::endl;
    std::cout << "|游戏介绍：一个简单的文字RPG游戏                                                  |" << std::endl;
    std::cout << "|版本：1.0                                                                        |" << std::endl;
    std::cout << "|_________________________________________________________________________________|" << std::endl;
    std::cout << std::endl;
    std::string startSentence = "1、新的开始   2、继续战斗   3、退出游戏";
    int index = 0;


    while (index < startSentence.length()) {
        std::cout << startSentence[index++];
        std::cout.flush();//立刻输出缓冲区里的字符
        std::this_thread::sleep_for(std::chrono::milliseconds(50));//使程序停止50ms
    }
    //延迟50ms输出字符
    std::cout << std::endl;
    int startChoose = 0;
    cin >> startChoose;
    if (startChoose == 1) {
        // 打开文件
        std::ofstream outFile("role.dat", std::ios::binary);

        // 将对象的数据写入文件
        if (outFile.is_open()) {
            // 写入姓名
            int nameLength = Role.name.length();
            outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(int));
            outFile.write(Role.name.c_str(), nameLength);

            // 写入HP
            outFile.write(reinterpret_cast<char*>(&Role.HP), sizeof(int));
            
            // 写入攻击
            outFile.write(reinterpret_cast<char*>(&Role.attack), sizeof(int));

            // 写入防御
            outFile.write(reinterpret_cast<char*>(&Role.DEF), sizeof(int));

            // 写入敏捷
            outFile.write(reinterpret_cast<char*>(&Role.Agility), sizeof(int));

            // 写入闪避
            outFile.write(reinterpret_cast<char*>(&Role.dodge), sizeof(double));

            // 写入生命
            outFile.write(reinterpret_cast<char*>(&Role.life), sizeof(int));

            // 写入金币
            outFile.write(reinterpret_cast<char*>(&Role.money), sizeof(int));

            // 写入等级
            outFile.write(reinterpret_cast<char*>(&Role.level), sizeof(int));

            // 写入经验
            outFile.write(reinterpret_cast<char*>(&Role.EXP), sizeof(int));

            // 关闭文件
            outFile.close();

        }
        else {
            std::cout << "存档失败！" << std::endl;
        }
    }
    }// 建立新的存档，进入introduce，开始游戏
    if (startChoose == 2) {

    }//读取旧的存档，开始游戏
    if (startChoose == 3) {
        std::string byeSentence = "再会";
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
    }//退出游戏
}