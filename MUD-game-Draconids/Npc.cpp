
#include"Npc.h"

Npc::Npc(vector<string>& talk, string& communication)
	:communication(communication)
{
	for (int i = 0; i < talk.size(); i++)
		this->talk[i] = talk[i];
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