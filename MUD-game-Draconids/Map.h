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
	void move();
	void Map_find(string& str);//查询当前地图内的Npc
private:
	int pos;
	unordered_map<string, int>search_map;//存储地点名称和数组下标
	vector<string> posname = { "卡塞尔学院","青铜城","北京","日本","俄罗斯","北极","仕兰中学""巴西" };
	//巴西为商店
	vector<shared_ptr<Npc>> allnpc;//地图上的所有npc指针
	unordered_map<string, int>searchNPC_map;//查找npc的表,为地点和数组
};

#includee<map>
