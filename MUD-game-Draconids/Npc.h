#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Npc
{
public:

	Npc() {}
	Npc(vector<string>& talk,string & communication);
	void GetTask();//����Ի�
	void conversation();//����̸��
	string GetName()
	{
		return name;
	}
private:
	string name;
	vector<string> talk;//����Ի����Բ�ֹһ��
	string communication;//����̶��Դ�һ���Ի�
};