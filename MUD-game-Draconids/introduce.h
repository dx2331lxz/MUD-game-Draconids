#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include"main.h"

using namespace std;

class Map;

void introduce();

void choose(Map& map);

void loading();

int menu(Role& character);