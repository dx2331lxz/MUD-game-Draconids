#include"Map.h"





Map::Map()
:pos(1)
{
	search_map.insert(pair<string,int>("������ѧԺ",0));
	search_map.insert(pair<string, int>("��ͭ��", 1));
	search_map.insert(pair<string, int>("����", 2));
	search_map.insert(pair<string, int>("�ձ�", 3));
	search_map.insert(pair<string, int>("����˹", 4));
	search_map.insert(pair<string, int>("����", 5));
	search_map.insert(pair<string, int>("������ѧ", 6));
}
Map::~Map() {

}
void Map::ShowMap()
{
	cout << "           ����" << endl;
	cout << "             |  " << endl;
	cout << "             |   " << endl;
	cout << "          ����˹" << endl;
	cout << "        /       \\   " << endl;
	cout << "       /         \\   " << endl;
	cout << "      /           \\" << endl;
	cout << "   ����\t\t  �ձ�" << endl;
	cout << "       \\          /" << endl;
	cout << "        \\        /" << endl;
	cout << "\t  "<<posname[1] << endl;
	cout << "       /\t  \\" << endl;
	cout << "      /\t\t   \\" << endl;
	cout << "������ѧ \t   ����" << endl;
	cout << "      \\ \t   /        " << endl;
	cout << "       \\ \t  /    " << endl;
	cout << "\t������ѧԺ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


}

void Map::move(string &str) {//��������ص�������ͬλ��,���������,�˳�������������
	unordered_map<string, int>::iterator it = search_map.find(str);
	if (it != search_map.end()) {
		pos = (*it).second;
		cout << "��ǰ����" << str << endl;
	}
		
	else  cout << "�õص㲻����,����������" << endl;
}