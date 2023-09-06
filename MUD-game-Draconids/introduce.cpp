#include"introduce.h"
#include"main.h"
int index;

void introduce() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//设置字体为黄色
    cout << "背景介绍" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//设置字体为绿色
    std::string backgroundSentence = "    你只是一个普通的懵懂高中生，一封来自卡塞尔学院的来信改变了你平淡的人生。在热血与神秘的呼唤下，在爱与梦想的抉择下，你毅然选择了未知。黑色的直升机划过天际，陌生国度的大门向你缓缓开启，平凡的中国小孩走上不平凡的屠龙之路。而遥远的卡塞尔学院却处处透着神秘－－奇怪的课程、搞笑的学长、疯狂的教师、骄傲的同学等。路明非刚刚进入学校就遭遇了无数的怪事。但是，随之而来的挑战也开始了，等级考试、言灵考验、地图搜索。龙的世界也终于在水下露出了神秘面纱";
    index = 0;

    while (index < backgroundSentence.length()) {
        std::cout << backgroundSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//背景介绍
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//恢复默认颜色
    system("pause");
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//设置字体为黄色
    cout << "人物介绍" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //设置字体为绿色
    std::string roleSentence = "   路明非，记住他名字，主角一个。很笨很蠢学习很渣，但是打电脑游戏很厉害。寄住在叔叔婶婶家。有很优秀的龙类血统，所以学院派诺诺（也是主角）来接他去他们学校，喜欢班花陈雯雯，但被同班一个高富帅抢走了，在自卑失恋的情况下，诺诺开法拉利接走了他，御姐气场力压全场，路明非也为之倾倒，但是诺诺却早已名花有主是路明非老大凯撒的女朋友。路鸣泽，寄居在路明非心中的魔鬼，只要路明非用灵魂与他交易，他就可以实现路明非的任何愿望。";
    index = 0;
    while (index < roleSentence.length()) {
        std::cout << roleSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//人物介绍
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//恢复默认颜色
    system("pause");
    system("cls");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//设置字体为黄色
    cout << "设定介绍" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//设置字体为绿色
    std::string setSentence = "    世界上的人类中,产生含有龙族血统的人类,不同的血统会提高身体素质,带来不同的能力.根据血统纯度的不同分为:S级,A级,B级,C级,D级.血统无法改变,但能力却会随着角色的成长而成长.世界的敌人是黑龙王以及它的四个孩子,四大龙王.被封印的他们随时有可能苏醒并统治世界,它们有着不同的龙族子民,人类的目标是消灭四大龙王,拯救世界。 其中男主路明非身份不详, 血统为S级, 血统并没有给他带来特殊的能力, 却为了带来了一个心中的魔鬼, 路明泽。只要交换四分之一的生命，就可以实现任何愿望。但路明非不想死，他想要通过自己的努力消灭龙王。";
    index = 0;
    while (index < setSentence.length()) {
        std::cout << setSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }//设定介绍
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//恢复默认颜色
    system("pause");
    system("cls");
}



void choose(Map& map) {
    cout << "选择 1. 进入地图" << endl;
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
        map.ShowMap();
        break;
    default:
        cout << "你干嘛~~，哎呦！！" << endl;
        break;
    }
    
    cout << map.GetPosition();
}