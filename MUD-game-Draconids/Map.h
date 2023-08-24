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
//将地图分成不同的块,按照块的不同将其组合
class Map
{
public:
	Map();
	~Map();
	int GetPosition()//获取当前所在位置
	{
		return pos;
	}
	void ShowMap();
	void move(string &str);
	void Map_find(string& str);//查询当前地图内的Npc
private:
	int pos;
	unordered_map<string, int>search_map;
	vector<string> posname = { "卡塞尔学院","青铜城","北京","日本","俄罗斯","北极","仕兰中学" };
	vector<Npc*> allnpc;//地图上的所有npc指针
	unordered_map<string, int>searchNPC_map;//查找npc的表,为地点和数组
	
};

class School_Map {   //卡塞尔学院地图
public:
	School_Map();
	void showmap();
	void move(char action);//移动输入wasd 如果超出位置,只能在此地呆着
	char isthere(int x,int y);//判断人物此时在不在这里,如果在,返回*
private:
	vector<vector<string>>posname = { {"教室","训练室"},{"地窖","装备部"},{"休息室","图书馆"} };
	int pos[2];
};

class MapNode   //青铜城专用地图块
{
public:
	 //不同的人物指针
	MapNode();
	MapNode(Role* role, MapNode* left, MapNode* right);
	MapNode* left;
	MapNode* right;
	//MapNode(MapNode *root);
	void Getthere()//到达此地时调用
	{
		isthere = true;
	}
	void goaway()//离开时调用
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
	MapNode* GetRoot() {//返回入口节点
		return root;
	}
	void showmap();
private:
	MapNode* root;
};
