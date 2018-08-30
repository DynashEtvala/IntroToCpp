#include "Fighter.h"
#include <iostream>
using namespace std;

//constructors

//default constructor
Fighter::Fighter()
{
	health = 0;
	minAtk = 0;
	maxAtk = 0;
	name = "N/A";
	atkName = "N/A";
}

//constructor with all variables
Fighter::Fighter(int Health, int MinAtk, int MaxAtk, string Name, string AtkName)
{
	health = Health;
	minAtk = MinAtk;
	maxAtk = MaxAtk;
	name = Name;
	atkName = AtkName;
}



//getters

int Fighter::GetHealth()
{
	return health;
}

string Fighter::GetName()
{
	return name;
}

string Fighter::GetAtkName()
{
	return atkName;
}



//functions

//fighter will attack the target
void Fighter::Attack(Fighter& target)
{
	//calculate random damage value
	int damage = (rand() % (maxAtk - minAtk)) + minAtk;
	//have target take damage
	target.Damage(damage);
	//display what happened
	cout << name << " attacks " << target.GetName() << " with " << atkName << " and inflicts " << damage << " damage!" << endl;
}

//fighter takes damage
void Fighter::Damage(int dam)
{
	health -= dam;
}


