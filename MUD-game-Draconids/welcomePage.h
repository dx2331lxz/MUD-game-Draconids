#include <iostream>
#include <thread>
#include "main.h"

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
    std::string sentence = "1、新的开始   2、继续战斗   3、退出游戏";
    int index = 0;

    while (index < sentence.length()) {
        std::cout << sentence[index++];
        std::cout.flush();//立刻输出缓冲区里的字符
        std::this_thread::sleep_for(std::chrono::milliseconds(50));//使程序停止50ms
    }

    //延迟50ms输出字符

    std::cout << std::endl;
}