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

class School_Map {   //������ѧԺ��ͼ
public:
	School_Map();
	void showmap();
	void move(string &action);
private:
	vector<vector<string>>posname = { {"����","ѵ����"},{"�ؽ�","װ����"},{"��Ϣ��","ͼ���"} };
	int pos[2];
};

class MapNode   //��ͭ��ר�õ�ͼ��
{
public:
	 //��ͬ������ָ��
	MapNode() {}
	//MapNode(MapNode *root);
	vector<MapNode*>& GetChildren()
	{
		return children;
	}
	void AddChildren(MapNode* NewChildren);
private:
	vector<MapNode*> children;//�洢���ڵĵ�ͼ�ڵ�
};


class TreeMap {
public:
	TreeMap()
		: root(nullptr)
	{}
	void AddNote(MapNode* newone,MapNode *parent);
private:
	MapNode* root;//���ڵ�洢���λ��
};