#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<memory>
#include<map>
#include<unordered_map>
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

private:
	int pos;
	unordered_map<string, int>search_map;
	vector<string> posname = { "卡塞尔学院","青铜城","北京","日本","俄罗斯","北极","仕兰中学" };
};

class School_Map {   //卡塞尔学院地图
public:
	School_Map();
	void showmap();
	void move(string &action);
private:
	vector<vector<string>>posname = { {"教室","训练室"},{"地窖","装备部"},{"休息室","图书馆"} };
	int pos[2];
};

class MapNode   //青铜城专用地图块
{
public:
	 //不同的人物指针
	MapNode() {}
	//MapNode(MapNode *root);
	vector<MapNode*>& GetChildren()
	{
		return children;
	}
	void AddChildren(MapNode* NewChildren);
private:
	vector<MapNode*> children;//存储相邻的地图节点
};


class TreeMap {
public:
	TreeMap()
		: root(nullptr)
	{}
	void AddNote(MapNode* newone,MapNode *parent);
private:
	MapNode* root;//根节点存储入口位置
};