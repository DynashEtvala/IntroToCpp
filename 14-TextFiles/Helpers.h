#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

struct entity
{
	string name;

	float hitpoints;
	float armor;

	int strength;
	int defense;
	int agility;
	int luck;
};

void PrintFile();
void SaveInfo();
void Corrupt(float);
int* ValArray();
entity* LoadEntity();