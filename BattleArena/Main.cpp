#include<iostream>
#include"Fighter.h"
using namespace std;

bool CheckLoss(Fighter team[], int size)
{
	int dead = 0;
	for (int i = 0; i < size; i++)
	{
		dead += team[i].GetHealth() <= 0;
	}
	return dead >= size;
}

int main()
{
	int size = 3;
	Fighter team1[3];
	team1[0] = Fighter(25, 1, 5, "Iron Man", "Lazer");
	team1[1] = Fighter(20, 3, 7, "War MAchine", "Machine Gun");
	team1[2] = Fighter(40, 1, 2, "Black Panther", "Claw");
	Fighter team2[3];
	team2[0] = Fighter(40, 1, 2, "Captain America", "Shield");
	team2[1] = Fighter(25, 1, 5, "Bucky Barnes", "Punch");
	team2[2] = Fighter(20, 3, 7, "Hawk Eye", "Arrow");
	bool quit = false;
	while (!quit)
	{
		for (int i = 0; i < size * 2; i++)
		{
			if (i % 2 == 0)
			{
				if (team1[i / 2].GetHealth() > 0 && !CheckLoss(team2, size))
				{
					int target = rand() % size;
					while (team2[target].GetHealth() <= 0)
					{
						target = rand() % size;
					}
					team1[i / 2].Attack(team2[target]);
				}
			}
			else
			{
				if (team2[i / 2].GetHealth() > 0 && !CheckLoss(team1, size))
				{
					int target = rand() % size;
					while (team1[target].GetHealth() <= 0)
					{
						target = rand() % size;
					}
					team2[i / 2].Attack(team1[target]);
				}
			}
		}
		if (CheckLoss(team1, size))
		{
			cout << "Team 2 wins!" << endl;
			quit = true;
		}
		else if (CheckLoss(team2, size))
		{
			cout << "Team 1 wins!" << endl;
			quit = true;
		}
	}
	cout << "PRESS ENTER TO QUIT" << endl;
	cin.get();

	return 0;
}