#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<memory>
#include<map>
#include<unordered_map>
//����ͼ�ֳɲ�ͬ�Ŀ�,���տ�Ĳ�ͬ�������
class Map
{
public:
	Map();
	~Map();
	int GetPosition()//��ȡ��ǰ����λ��
	{
		return pos;
	}
	void ShowMap();
	void move(string &str);

private:
	int pos;
	unordered_map<string, int>search_map;
	vector<string> posname = { "������ѧԺ","��ͭ��","����","�ձ�","����˹","����","������ѧ" };
};

class MapNode
{
public:
	 
private:

};
