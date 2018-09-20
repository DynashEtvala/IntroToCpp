#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <stdio.h>

struct fileTrack
{
	std::string fPaths[999];
	int count;
};

void Bestiary();
fileTrack GetMonsterPaths();
void AddMonster(fileTrack&);
void RemoveMonster(fileTrack&);
void ViewMonster(fileTrack&);
void BrowseMonsters(fileTrack&);
bool NameExists(fileTrack&, std::string);
bool IDExists(fileTrack&, int);
void SToLower(std::string&);
std::string SToLowerOf(std::string);