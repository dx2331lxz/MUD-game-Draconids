#include"introduce.h"
#include"main.h"
int index;

std::atomic<bool> enterPressed(false);

void KeyboardInputThread() {
    while (true) {
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            // Ctrl键被按下
            enterPressed.store(true);

            break;
        }
    }
}


//std::string backgroundSentence = "    你只是一个普通的懵懂高中生，一封来自卡塞尔学院的来信改变了你平淡的人生。在热血与神秘的呼唤下，在爱与梦想的抉择下，你毅然选择了未知。黑色的直升机划过天际，陌生国度的大门向你缓缓开启，平凡的中国小孩走上不平凡的屠龙之路。而遥远的卡塞尔学院却处处透着神秘－－奇怪的课程、搞笑的学长、疯狂的教师、骄傲的同学等。路明非刚刚进入学校就遭遇了无数的怪事。但是，随之而来的挑战也开始了，等级考试、言灵考验、地图搜索。龙的世界也终于在水下露出了神秘面纱"; // 替换为您的长文本
//backgroundSentence = "   路明非，记住他名字，主角一个。很笨很蠢学习很渣，但是打电脑游戏很厉害。寄住在叔叔婶婶家。有很优秀的龙类血统，所以学院派诺诺（也是主角）来接他去他们学校，喜欢班花陈雯雯，但被同班一个高富帅抢走了，在自卑失恋的情况下，诺诺开法拉利接走了他，御姐气场力压全场，路明非也为之倾倒，但是诺诺却早已名花有主是路明非老大凯撒的女朋友。路鸣泽，寄居在路明非心中的魔鬼，只要路明非用灵魂与他交易，他就可以实现路明非的任何愿望。";


void print_introduce(string backgroundSentence) {
    std::thread keyboardThread;
    cout << "按Ctrl键加速" << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN); // 设置字体为黄色
    cout << "背景介绍" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);//设置字体为绿色
    
    keyboardThread = std::thread(KeyboardInputThread); // 启动检测键盘输入的线程
    index = 0;

    while (index < backgroundSentence.length() && !enterPressed.load()) {
        std::cout << backgroundSentence[index++];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    keyboardThread.join();

    // 显示剩余文本（如果有的话）
    while (index < backgroundSentence.length()) {
        std::cout << backgroundSentence[index++];
    }

    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//恢复默认颜色
    enterPressed.store(false);
}

void introduce() {
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);//设置字体为黄色


    //std::string backgroundSentence = "    你只是一个普通的懵懂高中生，一封来自卡塞尔学院的来信改变了你平淡的人生。在热血与神秘的呼唤下，在爱与梦想的抉择下，你毅然选择了未知。黑色的直升机划过天际，陌生国度的大门向你缓缓开启，平凡的中国小孩走上不平凡的屠龙之路。而遥远的卡塞尔学院却处处透着神秘－－奇怪的课程、搞笑的学长、疯狂的教师、骄傲的同学等。路明非刚刚进入学校就遭遇了无数的怪事。但是，随之而来的挑战也开始了，等级考试、言灵考验、地图搜索。龙的世界也终于在水下露出了神秘面纱";
    //index = 0;

    //while (index < backgroundSentence.length()) {
    //    std::cout << backgroundSentence[index++];
    //    std::cout.flush();
    //    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //}//背景介绍
    print_introduce("你只是一个普通的懵懂高中生，一封来自卡塞尔学院的来信改变了你平淡的人生。在热血与神秘的呼唤下，在爱与梦想的抉择下，你毅然选择了未知。黑色的直升机划过天际，陌生国度的大门向你缓缓开启，平凡的中国小孩走上不平凡的屠龙之路。而遥远的卡塞尔学院却处处透着神秘－－奇怪的课程、搞笑的学长、疯狂的教师、骄傲的同学等。路明非刚刚进入学校就遭遇了无数的怪事。但是，随之而来的挑战也开始了，等级考试、言灵考验、地图搜索。龙的世界也终于在水下露出了神秘面纱");
    
    // 等待用户按下Enter键继续
    std::cout << "按下右Alt键继续..." << endl;
    while (true) {
        if (GetAsyncKeyState(VK_RMENU) & 0x8000) {
            break;
        }
    }
    system("cls");
    print_introduce("路明非，记住他名字，主角一个。很笨很蠢学习很渣，但是打电脑游戏很厉害。寄住在叔叔婶婶家。有很优秀的龙类血统，所以学院派诺诺（也是主角）来接他去他们学校，喜欢班花陈雯雯，但被同班一个高富帅抢走了，在自卑失恋的情况下，诺诺开法拉利接走了他，御姐气场力压全场，路明非也为之倾倒，但是诺诺却早已名花有主是路明非老大凯撒的女朋友。路鸣泽，寄居在路明非心中的魔鬼，只要路明非用灵魂与他交易，他就可以实现路明非的任何愿望。");
    std::cout << "按下右Alt键继续..." << endl;
    while (true) {
        if (GetAsyncKeyState(VK_RMENU) & 0x8000) {
            break;
        }
    }
    system("cls");
    
    print_introduce("世界上的人类中,产生含有龙族血统的人类,不同的血统会提高身体素质,带来不同的能力.根据血统纯度的不同分为:S级,A级,B级,C级,D级.血统无法改变,但能力却会随着角色的成长而成长.世界的敌人是黑龙王以及它的四个孩子,四大龙王.被封印的他们随时有可能苏醒并统治世界,它们有着不同的龙族子民,人类的目标是消灭四大龙王,拯救世界。 其中男主路明非身份不详, 血统为S级, 血统并没有给他带来特殊的能力, 却为了带来了一个心中的魔鬼, 路明泽。只要交换四分之一的生命，就可以实现任何愿望。但路明非不想死，他想要通过自己的努力消灭龙王。");
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
    //map.Map_find();
    //map.move();
    //cout << map.GetPosition();
}



COORD getXY()							//通过WindowsAPI函数获取光标的位置
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    //利用标准输出句柄获得光标坐标信息

    return COORD{ pBuffer.dwCursorPosition.X, pBuffer.dwCursorPosition.Y };
    //封装为表示坐标的COORD结构
}

COORD getScrnInfo()										//获取控制台窗口缓冲区大小
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);		//获得标准输出设备句柄
    CONSOLE_SCREEN_BUFFER_INFO scBufInf;				//定义一个窗口缓冲区信息结构体

    GetConsoleScreenBufferInfo(hStd, &scBufInf);		//获取窗口缓冲区信息

    return scBufInf.dwSize;								//返回窗口缓冲区大小
}

void moveXY(COORD pstn)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pstn);
    //通过标准输出句柄控制光标的位置
}

void clearDisplay(COORD firstPst, COORD lastPst)		//清除部分屏幕内容，从firstPst坐标到lastPst坐标之间的内容
{
    int yDValue(lastPst.Y - firstPst.Y);					//记录首末位置纵坐标差值，控制迭代次数

    COORD size(getScrnInfo());								//记录目前控制台缓冲区大小

    moveXY(firstPst);							//移动光标到首位置
    for (int y(0); y <= yDValue; y++)			//一层循环控制清除行数
    {
        for (int x(firstPst.X); x <= size.X; x++)			//二层循环避免重复清除
        {
            std::cout << ' ';						//输出一个空格来覆盖原内容，达到清除效果
            int px;									//记录光标当前位置的横坐标
            if (x != size.X)
                px = x + 1;
            else
                px = 0;
            if (y == yDValue && px == lastPst.X)		//与光标末位置作对比，达到末位置即退出循环
                break;
        }
    }
    moveXY(firstPst);
}

void loading()									//等待界面，模拟动态进度条过程
{
    COORD headPst(getXY());						//记录最初位置，便于结束后清除进度条内容
    HANDLE hStd(GetStdHandle(STD_OUTPUT_HANDLE));
    CONSOLE_CURSOR_INFO  cInfo;
    GetConsoleCursorInfo(hStd, &cInfo);			//获取光标信息的句柄
    cInfo.bVisible = false;						//修改光标可见性
    SetConsoleCursorInfo(hStd, &cInfo);			//设置光标不可见

    std::cout << "请等待";
    COORD firstPst;								//存储光标坐标，为清除做铺垫
    COORD lastPst;

    int n(0);									//模拟进度条数字
    int m(0);									//记录进度条方块总数
    srand((unsigned)time(NULL));				//取时间作为随机数种子，避免伪随机数
    while (n < 100)								//达到较好的动态效果
    {
        m = n / 5;
        n += rand() % 14 + 1;
        if (n < 100)
        {
            for (int i(n / 5 - m); i > 0; i--)
                std::cout << "█";
            firstPst = getXY();						//获取输出前坐标
            std::cout << n << "%";					//输出百分比进度条
            lastPst = getXY();						//获取输出之后的光标位置
        }
        else
        {
            n = 100;								//最大值为100，达到则退出操作
            std::cout << "█";
            std::cout << n << "%";
            lastPst = getXY();
            break;
        }

        Sleep(80);
        clearDisplay(firstPst, lastPst);		//清除现有图形，重新绘制
    }

    clearDisplay(headPst, lastPst);				//清除进度条图形
    cInfo.bVisible = true;						//光标可见性改为可见
    SetConsoleCursorInfo(hStd, &cInfo);
}



// 个人菜单




int menu(Role& character) {

    cout << "姓名: "<< character.getname() << endl;
    cout << "血量: ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED); // 设置字体为红色
    
    
    for (int i = 0; i < int(character.getHP() / 10); i++) {
        cout << "█";
    }
    cout << character.getHP() << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//恢复默认颜色
    cout << "经验: " << character.getEXP() << endl;
    cout << "技能: ";
    character.showskill();
    return 1;
}