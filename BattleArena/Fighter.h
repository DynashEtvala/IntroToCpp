#pragma once
#include<string>
using namespace std;

class Fighter
{
private:
	int health;
	int minAtk;
	int maxAtk;
	string name;
	string atkName;
public:
	Fighter();
	Fighter(int Health, int MinAtk, int MaxAtk, string Name, string AtkName);
	void Attack(Fighter& target);
	void Damage(int dam);
	int GetHealth();
	string GetName();
	string GetAtkName();
};

