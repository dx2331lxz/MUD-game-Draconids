#include"introduce.h"
#include"main.h"
int index;

void introduce() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//��������Ϊ��ɫ
    cout << "��������" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//��������Ϊ��ɫ
    std::string backgroundSentence = "    ��ֻ��һ����ͨ���¶���������һ�����Կ�����ѧԺ�����Ÿı�����ƽ��������������Ѫ�����صĺ����£��ڰ�������ľ����£�����Ȼѡ����δ֪����ɫ��ֱ����������ʣ�İ�����ȵĴ������㻺��������ƽ�����й�С�����ϲ�ƽ��������֮·����ңԶ�Ŀ�����ѧԺȴ����͸�����أ�����ֵĿγ̡���Ц��ѧ�������Ľ�ʦ��������ͬѧ�ȡ�·���Ǹոս���ѧУ�������������Ĺ��¡����ǣ���֮��������սҲ��ʼ�ˣ��ȼ����ԡ����鿼�顢��ͼ��������������Ҳ������ˮ��¶����������ɴ";
    index = 0;

    while (index < backgroundSentence.length()) {
        std::cout << backgroundSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//��������
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�ָ�Ĭ����ɫ
    system("pause");
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//��������Ϊ��ɫ
    cout << "�������" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //��������Ϊ��ɫ
    std::string roleSentence = "   ·���ǣ���ס�����֣�����һ�����ܱ��ܴ�ѧϰ���������Ǵ������Ϸ����������ס�����������ҡ��к����������Ѫͳ������ѧԺ��ŵŵ��Ҳ�����ǣ�������ȥ����ѧУ��ϲ���໨������������ͬ��һ���߸�˧�����ˣ����Ա�ʧ��������£�ŵŵ����������������������������ѹȫ����·����ҲΪ֮�㵹������ŵŵȴ��������������·�����ϴ�����Ů���ѡ�·���󣬼ľ���·�������е�ħ��ֻҪ·����������������ף����Ϳ���ʵ��·���ǵ��κ�Ը����";
    index = 0;
    while (index < roleSentence.length()) {
        std::cout << roleSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//�������
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�ָ�Ĭ����ɫ
    system("pause");
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//��������Ϊ��ɫ
    cout << "�趨����" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//��������Ϊ��ɫ
    std::string setSentence = "    �����ϵ�������,������������Ѫͳ������,��ͬ��Ѫͳ�������������,������ͬ������.����Ѫͳ���ȵĲ�ͬ��Ϊ:S��,A��,B��,C��,D��.Ѫͳ�޷��ı�,������ȴ�����Ž�ɫ�ĳɳ����ɳ�.����ĵ����Ǻ������Լ������ĸ�����,�Ĵ�����.����ӡ��������ʱ�п������Ѳ�ͳ������,�������Ų�ͬ����������,�����Ŀ���������Ĵ�����,�������硣 ��������·������ݲ���, ѪͳΪS��, Ѫͳ��û�и����������������, ȴΪ�˴�����һ�����е�ħ��, ·����ֻҪ�����ķ�֮һ���������Ϳ���ʵ���κ�Ը������·���ǲ�����������Ҫͨ���Լ���Ŭ������������";
    index = 0;
    while (index < setSentence.length()) {
        std::cout << setSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//�趨����
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�ָ�Ĭ����ɫ
    system("pause");
    system("cls");
}



void choose(Map& map) {
    cout << "ѡ�� 1. �����ͼ" << endl;
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
        map.ShowMap();
        break;
    default:
        cout << "�����~~�����ϣ���" << endl;
        break;
    }
    
    cout << map.GetPosition();
}