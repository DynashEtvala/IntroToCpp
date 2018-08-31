#include<iostream>
#include"Fighter.h"

//check if all fighters on a team are dead
bool CheckLoss(Fighter team[], int size)
{
	int dead = 0;
	for (int i = 0; i < size; i++)
	{
		dead += team[i].GetHealth() <= 0;
	}
	return dead >= size;
}

//sort all fighters on a team based on health value
void HealthSort(Fighter team[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0 && team[j - 1].GetHealth() > team[j].GetHealth(); j--)
		{
			Fighter hold = team[j - 1];
			team[j - 1] = team[j];
			team[j] = hold;
		}
	}
}

int main()
{
	//set up teams
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
	//start
	cout << "Battle Arena\n\nPRESS ENTER TO START\n" << endl;
	cin.get();
	//main loop
	while (!quit)
	{
		//iterate through all fighters from both teams
		for (int i = 0; i < size * 2; i++)
		{
			//decide the team that the fighter is on. 0 = team one, 1 = team 2
			if (i % 2 == 0)
			{
				//check if current fighter is alive and if team2 isn't already dead
				if (team1[i / 2].GetHealth() > 0 && !CheckLoss(team2, size))
				{
					//decide a random target to attack
					int target = rand() % size;
					//randomize until target has health
					while (team2[target].GetHealth() <= 0)
					{
						target = rand() % size;
					}
					//perform attack
					team1[i / 2].Attack(team2[target]);
				}
			}
			else
			{
				//check if current fighter is alive and if team1 isn't already dead
				if (team2[i / 2].GetHealth() > 0 && !CheckLoss(team1, size))
				{
					//decide a random target to attack
					int target = rand() % size;
					//randomize until target has health
					while (team1[target].GetHealth() <= 0)
					{
						target = rand() % size;
					}
					//perform attack
					team2[i / 2].Attack(team1[target]);
				}
			}
		}
		//pause before next round
		cout << "Press enter to end round" << endl;
		cin.get();
		//check if team1 are all dead
		if (CheckLoss(team1, size))
		{
			//anounce that team2 won and exit main loop
			cout << "Team 2 wins!" << endl;
			quit = true;
		}
		//check if team2 are all dead
		else if (CheckLoss(team2, size))
		{
			//anounce that team1 won and exit main loop
			cout << "Team 1 wins!" << endl;
			quit = true;
		}
		//sort both teams based on their health
		HealthSort(team1, size);
		HealthSort(team2, size);
	}
	//pause before quitting program
	cout << "PRESS ENTER TO QUIT" << endl;
	cin.get();

	return 0;
}