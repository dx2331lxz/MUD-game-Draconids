#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<memory>
#include<map>
#include<unordered_map>
#include"Npc.h"
#include"Role.h"
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
	void Map_find(string& str);//��ѯ��ǰ��ͼ�ڵ�Npc
private:
	int pos;
	unordered_map<string, int>search_map;
	vector<string> posname = { "������ѧԺ","��ͭ��","����","�ձ�","����˹","����","������ѧ" };
	vector<Npc*> allnpc;//��ͼ�ϵ�����npcָ��
	unordered_map<string, int>searchNPC_map;//����npc�ı�,Ϊ�ص������
	
};

class School_Map {   //������ѧԺ��ͼ
public:
	School_Map();
	void showmap();
	void move(char action);//�ƶ�����wasd �������λ��,ֻ���ڴ˵ش���
	char isthere(int x,int y);//�ж������ʱ�ڲ�������,�����,����*
private:
	vector<vector<string>>posname = { {"����","ѵ����"},{"�ؽ�","װ����"},{"��Ϣ��","ͼ���"} };
	int pos[2];
};

class MapNode   //��ͭ��ר�õ�ͼ��
{
public:
	 //��ͬ������ָ��
	MapNode();
	MapNode(Role* role, MapNode* left, MapNode* right);
	MapNode* left;
	MapNode* right;
	//MapNode(MapNode *root);
	void Getthere()//����˵�ʱ����
	{
		isthere = true;
	}
	void goaway()//�뿪ʱ����
	{
		isthere = false;
	}
	char IsThere()
	{
		if (isthere)
			return '*';
		else
			return'0';
	}
private:
	Role* role;
	bool isthere=false;
};

class TreeMap {
public:
	TreeMap();
	TreeMap(MapNode* root);
	MapNode* GetRoot() {//������ڽڵ�
		return root;
	}
	void showmap();
private:
	MapNode* root;
};
