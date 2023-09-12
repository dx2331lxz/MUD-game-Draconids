#include"introduce.h"
#include"main.h"
int index;

std::atomic<bool> enterPressed(false);

void KeyboardInputThread() {
    while (true) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            // Ctrl��������
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



COORD getXY()							//ͨ��WindowsAPI������ȡ����λ��
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    //���ñ�׼��������ù��������Ϣ

    return COORD{ pBuffer.dwCursorPosition.X, pBuffer.dwCursorPosition.Y };
    //��װΪ��ʾ�����COORD�ṹ
}

COORD getScrnInfo()										//��ȡ����̨���ڻ�������С
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);		//��ñ�׼����豸���
    CONSOLE_SCREEN_BUFFER_INFO scBufInf;				//����һ�����ڻ�������Ϣ�ṹ��

    GetConsoleScreenBufferInfo(hStd, &scBufInf);		//��ȡ���ڻ�������Ϣ

    return scBufInf.dwSize;								//���ش��ڻ�������С
}

void moveXY(COORD pstn)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pstn);
    //ͨ����׼���������ƹ���λ��
}

void clearDisplay(COORD firstPst, COORD lastPst)		//���������Ļ���ݣ���firstPst���굽lastPst����֮�������
{
    int yDValue(lastPst.Y - firstPst.Y);					//��¼��ĩλ���������ֵ�����Ƶ�������

    COORD size(getScrnInfo());								//��¼Ŀǰ����̨��������С

    moveXY(firstPst);							//�ƶ���굽��λ��
    for (int y(0); y <= yDValue; y++)			//һ��ѭ�������������
    {
        for (int x(firstPst.X); x <= size.X; x++)			//����ѭ�������ظ����
        {
            std::cout << ' ';						//���һ���ո�������ԭ���ݣ��ﵽ���Ч��
            int px;									//��¼��굱ǰλ�õĺ�����
            if (x != size.X)
                px = x + 1;
            else
                px = 0;
            if (y == yDValue && px == lastPst.X)		//����ĩλ�����Աȣ��ﵽĩλ�ü��˳�ѭ��
                break;
        }
    }
    moveXY(firstPst);
}

void loading()									//�ȴ����棬ģ�⶯̬����������
{
    COORD headPst(getXY());						//��¼���λ�ã����ڽ������������������
    HANDLE hStd(GetStdHandle(STD_OUTPUT_HANDLE));
    CONSOLE_CURSOR_INFO  cInfo;
    GetConsoleCursorInfo(hStd, &cInfo);			//��ȡ�����Ϣ�ľ��
    cInfo.bVisible = false;						//�޸Ĺ��ɼ���
    SetConsoleCursorInfo(hStd, &cInfo);			//���ù�겻�ɼ�

    std::cout << "��ȴ�";
    COORD firstPst;								//�洢������꣬Ϊ������̵�
    COORD lastPst;

    int n(0);									//ģ�����������
    int m(0);									//��¼��������������
    srand((unsigned)time(NULL));				//ȡʱ����Ϊ��������ӣ�����α�����
    while (n < 100)								//�ﵽ�ϺõĶ�̬Ч��
    {
        m = n / 5;
        n += rand() % 14 + 1;
        if (n < 100)
        {
            for (int i(n / 5 - m); i > 0; i--)
                std::cout << "��";
            firstPst = getXY();						//��ȡ���ǰ����
            std::cout << n << "%";					//����ٷֱȽ�����
            lastPst = getXY();						//��ȡ���֮��Ĺ��λ��
        }
        else
        {
            n = 100;								//���ֵΪ100���ﵽ���˳�����
            std::cout << "��";
            std::cout << n << "%";
            lastPst = getXY();
            break;
        }

        Sleep(80);
        clearDisplay(firstPst, lastPst);		//�������ͼ�Σ����»���
    }

    clearDisplay(headPst, lastPst);				//���������ͼ��
    cInfo.bVisible = true;						//���ɼ��Ը�Ϊ�ɼ�
    SetConsoleCursorInfo(hStd, &cInfo);
}



// ���˲˵�

int menu(Role& character) {

    cout << "����: "<< character.getname() << endl;
    cout << "Ѫ��: ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED); // ��������Ϊ��ɫ
    
    
    for (int i = 0; i < int(character.getHP() / 10); i++) {
        cout << "��";
    }
    cout << character.getHP() << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�ָ�Ĭ����ɫ
    cout << "����: " << character.getEXP() << endl;
    cout << "����: ";
    character.showskill();
    cout << endl;
    return 1;
}