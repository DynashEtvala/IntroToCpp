#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter()
{
	health = 0;
	minAtk = 0;
	maxAtk = 0;
	name = "N/A";
	atkName = "N/A";
}

Fighter::Fighter(int Health, int MinAtk, int MaxAtk, string Name, string AtkName)
{
	health = Health;
	minAtk = MinAtk;
	maxAtk = MaxAtk;
	name = Name;
	atkName = AtkName;
}

void Fighter::Attack(Fighter& target)
{
	int damage = (rand() % (maxAtk - minAtk)) + minAtk;
	target.Damage(damage);
	cout << name << " attacks " << target.GetName() << " with " << atkName << " and inflicts " << damage << " damage!" << endl;
}

void Fighter::Damage(int dam)
{
	health -= dam;
}

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

