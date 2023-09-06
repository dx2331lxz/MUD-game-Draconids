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
	void move();
	void Map_find(string& str);//��ѯ��ǰ��ͼ�ڵ�Npc
private:
	int pos;
	unordered_map<string, int>search_map;//�洢�ص����ƺ������±�
	vector<string> posname = { "������ѧԺ","��ͭ��","����","�ձ�","����˹","����","������ѧ""����" };
	//����Ϊ�̵�
	vector<shared_ptr<Npc>> allnpc;//��ͼ�ϵ�����npcָ��
	unordered_map<string, int>searchNPC_map;//����npc�ı�,Ϊ�ص������
};




class School_Map {   //������ѧԺ��ͼ
public:
	School_Map();
	void showmap();
	void move();//�ƶ�����wasd,e�˳� �������λ��,ֻ���ڴ˵ش���
	char isthere(int x, int y);//�ж������ʱ�ڲ�������,�����,����*
private:
	vector<vector<string>>posname = { {"����","ѵ����"},{"�ؽ�","װ����"},{"��Ϣ��","ͼ���"} };
	int pos[2];
};






class MapNode   //��ͭ��ר�õ�ͼ��
{
public:
	//��ͬ������ָ��
	MapNode();
	MapNode(unique_ptr<Role>& role, shared_ptr<MapNode> left, shared_ptr<MapNode> right);
	shared_ptr<MapNode> left;
	shared_ptr<MapNode> right;

	void Getthere()//����˵�ʱ����
	{
		isthere = true;
	}
	shared_ptr<MapNode> goaway();//�뿪ʱ����

	char IsThere();

private:
	unique_ptr<Role> role;
	bool isthere = false;
};

class TreeMap {
public:
	//TreeMap();
	TreeMap(shared_ptr<MapNode> root);
	shared_ptr<MapNode> GetRoot() {//������ڽڵ�
		return root;
	}
	void init()
	{
		now->Getthere();
	}
	void showmap();
private:
	shared_ptr<MapNode> root;
	shared_ptr<MapNode> now;
};
