#include"Helpers.h"

void feedAussie(Aussiegochi& aus)
{
	aus.hunger -= 10;
	if (aus.hunger < 0)
	{
		aus.hunger = 0;
	}

	aus.happiness++;
	if (aus.happiness > 100)
	{
		aus.happiness = 100;
	}
}
void waterAussie(Aussiegochi& aus)
{
	aus.thirst -= 10;
	if (aus.thirst < 0)
	{
		aus.thirst = 0;
	}

	aus.happiness++;
	if (aus.happiness > 100)
	{
		aus.happiness = 100;
	}
}
void abuseAussie(Aussiegochi& aus)
{
	aus.sanity -= 10;
	if (aus.sanity < 0)
	{
		aus.sanity = 0;
	}

	aus.happiness -= 25;
	if (aus.happiness < 0)
	{
		aus.happiness = 0;
	}
}
void coddleAussie(Aussiegochi& aus)
{
	aus.sanity += 10;
	if (aus.sanity > 100)
	{
		aus.sanity = 100;
	}

	aus.happiness += 5;
	if (aus.happiness > 100)
	{
		aus.happiness = 100;
	}
}



void swap(float &a, float &b)
{
	float hold = a;
	a = b;
	b = hold;
}