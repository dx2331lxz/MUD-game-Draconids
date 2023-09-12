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
#include"main.h"
#include<graphics.h>
#define SHOWCONSOLE 1

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
	string move();
	void Map_find();//��ѯ��ǰ��ͼ�ڵ�Npc
	char isthere(int);
private:
	int pos;

	unordered_map<string, int>search_map;//�洢�ص����ƺ������±�
	vector<string> posname = { "������ѧԺ","��ͭ��","����","�ձ�","����˹","����","������ѧ","����" };
	vector<int>searchNPC_map = { 0,0,1,1,1,1,1,0 };
	vector<shared_ptr<Npc>> allnpc;//��ͼ�ϵ�����npcָ��
	//unordered_map<string, int>searchNPC_map;//����npc�ı�,Ϊ�ص������

};




class School_Map {   //������ѧԺ��ͼ
public:
	School_Map();
	void showmap();
	void move(Role& character);//�ƶ�����wasd,e�˳� �������λ��,ֻ���ڴ˵ش���
	char isthere(int x, int y);//�ж������ʱ�ڲ�������,�����,����*
	bool school_map_show();
private:
	vector<vector<string>>posname = { {"����","ѵ����"},{"�ؽ�","װ����"},{"��Ϣ��","ͼ���"} };
	int pos[2];
};






class MapNode   //��ͭ��ר�õ�ͼ��
{
public:
	//��ͬ������ָ��
	MapNode(string name);
	MapNode(unique_ptr<Role>& role, shared_ptr<MapNode> left, shared_ptr<MapNode> right);
	shared_ptr<MapNode> left;
	shared_ptr<MapNode> right;
	string getname();
	void Getthere()//����˵�ʱ����
	{
		isthere = true;
	}
	shared_ptr<MapNode> goaway();//�뿪ʱ����

	char IsThere();
	bool isthere = false;
private:
	unique_ptr<Role> role;
	string name;
};

class TreeMap {
public:
	TreeMap();
	shared_ptr<MapNode> GetRoot() {//������ڽڵ�
		return root;
	}
	void init()
	{
		now->Getthere();
	}
	shared_ptr<MapNode>GetNow()
	{
		return now;
	}
	void showmap();
	void go(Role& character);
private:
	shared_ptr<MapNode> root;
	shared_ptr<MapNode> now;
};
