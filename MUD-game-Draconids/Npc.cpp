#include"Npc.h"

Npc::Npc()
{
}

Npc::Npc(string &name,vector<string>& talk, string& communication,int pos)
	:name(name),communication(communication),pos(pos)
{
	for (int i = 0; i < talk.size(); i++)
		this->talk.push_back(talk[i]);
}
void Npc::GetTask()
{
	for (int i = 0; i < talk.size(); i++)
		cout << talk[i] << endl;	
}


void Npc::conversation()
{
	cout << communication << endl; 
}