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

#includee<map>
