#include <iostream>
#include <thread>
#include "main.h"
#include <stdlib.h>

//��ӭ����
void welcomePage() {
    int n = 0;
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
    


    while (n < startSentence.length()) {
        std::cout << startSentence[n++];
        std::cout.flush();//�����������������ַ�
        std::this_thread::sleep_for(std::chrono::milliseconds(50));//ʹ����ֹͣ50ms
    }
    //�ӳ�50ms����ַ�
    std::cout << std::endl;
   
}