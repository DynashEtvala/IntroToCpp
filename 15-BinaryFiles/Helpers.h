#pragma once

#include <iostream>
#include <fstream>
#include <string>

struct saveData
{
	std::string playerName;
	int deathCount;
	int deepestFloor;

	bool hasBeenBeatenGame;

	double timePlayed;  // given in seconds
};

void LoadData(saveData&);
void SaveData(saveData&);
void NewData(saveData&);
void PrintData(saveData&);