#include <iostream>
#include <thread>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include<set>
#include"Role.h"
#include <memory>
#include <string>
#include <vector>
#include"Skill.h"
#include"Bag.h"
using namespace std;

void save(Role& character, const std::vector<std::unique_ptr<Skill>>& Skill_vector, const std::string& skillData, Bag& Bag);
