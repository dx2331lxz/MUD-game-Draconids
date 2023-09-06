#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Npc
{
public:

	Npc();
	Npc(string &name,vector<string>& task,string & communication,int pos);
	void GetTask();//任务对话
	void conversation();//自由谈话
	string GetName()
	{
		return name;
	}
private:
	string name;
	vector<string> talk;//人物对话可以不止一句
	string communication;//人物固定自带一个对话
	int pos;//npc所处位置
};