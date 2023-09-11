#include"introduce.h"
#include"main.h"
int index;

std::atomic<bool> enterPressed(false);

void KeyboardInputThread() {
    while (true) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            // Enter��������
            enterPressed.store(true);

            break;
        }
    }
}


//std::string backgroundSentence = "    ��ֻ��һ����ͨ���¶���������һ�����Կ�����ѧԺ�����Ÿı�����ƽ��������������Ѫ�����صĺ����£��ڰ�������ľ����£�����Ȼѡ����δ֪����ɫ��ֱ����������ʣ�İ�����ȵĴ������㻺��������ƽ�����й�С�����ϲ�ƽ��������֮·����ңԶ�Ŀ�����ѧԺȴ����͸�����أ�����ֵĿγ̡���Ц��ѧ�������Ľ�ʦ��������ͬѧ�ȡ�·���Ǹոս���ѧУ�������������Ĺ��¡����ǣ���֮��������սҲ��ʼ�ˣ��ȼ����ԡ����鿼�顢��ͼ��������������Ҳ������ˮ��¶����������ɴ"; // �滻Ϊ���ĳ��ı�
//backgroundSentence = "   ·���ǣ���ס�����֣�����һ�����ܱ��ܴ�ѧϰ���������Ǵ������Ϸ����������ס�����������ҡ��к����������Ѫͳ������ѧԺ��ŵŵ��Ҳ�����ǣ�������ȥ����ѧУ��ϲ���໨������������ͬ��һ���߸�˧�����ˣ����Ա�ʧ��������£�ŵŵ����������������������������ѹȫ����·����ҲΪ֮�㵹������ŵŵȴ��������������·�����ϴ�����Ů���ѡ�·���󣬼ľ���·�������е�ħ��ֻҪ·����������������ף����Ϳ���ʵ��·���ǵ��κ�Ը����";


void print_introduce(string backgroundSentence) {
    std::thread keyboardThread;
    cout << "��Ctrl������" << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN); // ��������Ϊ��ɫ
    cout << "��������" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//��������Ϊ��ɫ
    
    keyboardThread = std::thread(KeyboardInputThread); // ����������������߳�
    index = 0;

    while (index < backgroundSentence.length() && !enterPressed.load()) {
        std::cout << backgroundSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    keyboardThread.join();

    // ��ʾʣ���ı�������еĻ���
    while (index < backgroundSentence.length()) {
        std::cout << backgroundSentence[index++];
    }

    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�ָ�Ĭ����ɫ
    enterPressed.store(false);
}

void introduce() {
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//��������Ϊ��ɫ


    //std::string backgroundSentence = "    ��ֻ��һ����ͨ���¶���������һ�����Կ�����ѧԺ�����Ÿı�����ƽ��������������Ѫ�����صĺ����£��ڰ�������ľ����£�����Ȼѡ����δ֪����ɫ��ֱ����������ʣ�İ�����ȵĴ������㻺��������ƽ�����й�С�����ϲ�ƽ��������֮·����ңԶ�Ŀ�����ѧԺȴ����͸�����أ�����ֵĿγ̡���Ц��ѧ�������Ľ�ʦ��������ͬѧ�ȡ�·���Ǹոս���ѧУ�������������Ĺ��¡����ǣ���֮��������սҲ��ʼ�ˣ��ȼ����ԡ����鿼�顢��ͼ��������������Ҳ������ˮ��¶����������ɴ";
    //index = 0;

    //while (index < backgroundSentence.length()) {
    //    std::cout << backgroundSentence[index++];
    //    std::cout.flush();
    //    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //}//��������
    print_introduce("��ֻ��һ����ͨ���¶���������һ�����Կ�����ѧԺ�����Ÿı�����ƽ��������������Ѫ�����صĺ����£��ڰ�������ľ����£�����Ȼѡ����δ֪����ɫ��ֱ����������ʣ�İ�����ȵĴ������㻺��������ƽ�����й�С�����ϲ�ƽ��������֮·����ңԶ�Ŀ�����ѧԺȴ����͸�����أ�����ֵĿγ̡���Ц��ѧ�������Ľ�ʦ��������ͬѧ�ȡ�·���Ǹոս���ѧУ�������������Ĺ��¡����ǣ���֮��������սҲ��ʼ�ˣ��ȼ����ԡ����鿼�顢��ͼ��������������Ҳ������ˮ��¶����������ɴ");
    
    // �ȴ��û�����Enter������
    std::cout << "������Alt������..." << endl;
    while (true) {
        if (GetAsyncKeyState(VK_RMENU) & 0x8000) {
            break;
        }
    }
    system("cls");
    print_introduce("·���ǣ���ס�����֣�����һ�����ܱ��ܴ�ѧϰ���������Ǵ������Ϸ����������ס�����������ҡ��к����������Ѫͳ������ѧԺ��ŵŵ��Ҳ�����ǣ�������ȥ����ѧУ��ϲ���໨������������ͬ��һ���߸�˧�����ˣ����Ա�ʧ��������£�ŵŵ����������������������������ѹȫ����·����ҲΪ֮�㵹������ŵŵȴ��������������·�����ϴ�����Ů���ѡ�·���󣬼ľ���·�������е�ħ��ֻҪ·����������������ף����Ϳ���ʵ��·���ǵ��κ�Ը����");
    std::cout << "������Alt������..." << endl;
    while (true) {
        if (GetAsyncKeyState(VK_RMENU) & 0x8000) {
            break;
        }
    }
    system("cls");
    
    print_introduce("�����ϵ�������,������������Ѫͳ������,��ͬ��Ѫͳ�������������,������ͬ������.����Ѫͳ���ȵĲ�ͬ��Ϊ:S��,A��,B��,C��,D��.Ѫͳ�޷��ı�,������ȴ�����Ž�ɫ�ĳɳ����ɳ�.����ĵ����Ǻ������Լ������ĸ�����,�Ĵ�����.����ӡ��������ʱ�п������Ѳ�ͳ������,�������Ų�ͬ����������,�����Ŀ���������Ĵ�����,�������硣 ��������·������ݲ���, ѪͳΪS��, Ѫͳ��û�и����������������, ȴΪ�˴�����һ�����е�ħ��, ·����ֻҪ�����ķ�֮һ���������Ϳ���ʵ���κ�Ը������·���ǲ�����������Ҫͨ���Լ���Ŭ������������");
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
    //map.Map_find();
    //map.move();
    //cout << map.GetPosition();
}