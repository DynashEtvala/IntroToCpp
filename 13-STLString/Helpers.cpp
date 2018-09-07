#include"Helpers.h"

void EveryOther(string s)
{
	for (int i = 1; i < s.length(); i += 2)
	{
		cout << s.at(i);
	}
	cout << endl;
}

void Title(string name)
{
	cout << name << ", the ";
	int random = rand() % 4;
	switch (random)
	{
	case 0:
		cout << "Masterful";
		break;
	case 1:
		cout << "Loser";
		break;
	case 2:
		cout << "Decietful";
		break;
	case 3:
		cout << "Dangerous";
		break;
	default:
		cout << "Broken";
		break;
	}
}

int Frequency(string s, char c)
{
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == c)
		{
			result++;
		}
	}
	return result;
}

int InstanceCount(string s, string& sub)
{
	int result = 0;
	for (int i = 0; i < s.length() - sub.length(); i++)
	{
		if (s.substr(i, sub.length()).compare(sub))
		{
			result++;
		}
	}
	return result;
}

void ToLower(char* base)
{
	for (int i = 0; i < strlen(base); i++)
	{
		if (base[i] >= 65 && base[i] <= 90)
		{
			base[i] += 32;
		}
	}
}

char TakeInput()
{
	char result = cin.get();
	ToLower(&result);
	return result;
}

void Hangman()
{
	bool quit = false;
	bool game = false;
	int strikesMax = 5;
	int strikes = 0;
	string goal = 0;
	string guess = 0;
	char input = 0;
	while (!quit)
	{
		cout << "Hangman" << endl << "[P]lay/[Q]uit" << endl;
		input = TakeInput();
		bool oktogo = false;
		switch (input)
		{
		case 'p':
			game = true;
			while (!oktogo)
			{
				cout << "Select difficulty:" << endl << "[E]asy/[M]edium/[H]ard" << endl;
				input = TakeInput();
				goal = HangList(input);
				if (goal.compare(0))
				{
					cout << "input invalid" << endl;
				}
				else
				{
					guess = "_";
					for (int i = 1; i < goal.length(); i++)
					{
						guess.append("_");
					}
					oktogo = true;
				}
			}
			break;
		case'q':
			quit = true;
			break;
		default:
			cout << "input invalid" << endl;
			break;
		}
		while (game)
		{
			cout << "You have " << strikes << "/" << strikesMax << " strikes." << endl;
			PrintGuess(guess);
			cout << "Guess a letter." << endl;
			input = TakeInput();
			if (Frequency(goal, input) > 0)
			{
				for (int i = 0; i < goal.length(); i++)
				{
					if (goal.at(i) == input)
					{
						guess.replace(i, 1, 1, input);
					}
				}
			}
			else
			{
				strikes++;
				cout << "Strike " << strikes << "!" << endl;
			}
			if (strikes >= strikesMax)
			{
				cout << "You lose!" << endl << "Returning to menu...";
				game = false;
			}
			else if (guess.compare(goal))
			{
				cout << "You win!" << endl << "Returning to menu...";
				game = false;
			}
		}
	}
}

string HangList(char difficulty)
{
	string easy[4]{ "time", "help", "blue", "fork" };
	string medium[4]{ "jumping", "tyrants", "majorly", "trumpet" };
	string hard[4]{ "gratuitous", "unfortunate", "ungrateful", "superficial" };
	int r = rand() % 4;
	switch (difficulty)
	{
	case 'e':
		return easy[r];
	case 'm':
		return medium[r];
	case 'h':
		return hard[r];
	default:
		return 0;
	}
}

void PrintGuess(string guess)
{
	cout << guess.at(0);
	for (int i = 1; i < guess.length(); i++)
	{
		cout << ' ' << guess.at(i);
	}
	cout << endl;
}