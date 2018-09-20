#include"Helpers.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::getline;

void LoadData(saveData& s)
{
	fstream file;
	file.open("gamesave.bin", std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		string line;
		getline(file, line);
		s.playerName = line;
		getline(file, line);
		s.deathCount = std::stoi(line);
		getline(file, line);
		s.deepestFloor = std::stoi(line);
		getline(file, line);
		s.hasBeenBeatenGame = std::stoi(line);
		getline(file, line);
		s.timePlayed = std::stof(line);
	}
	else
	{
		cout << "No savedata detected!" << endl;
	}
	file.flush();
	file.close();
}

void SaveData(saveData& s)
{
	fstream file;
	file.open("gamesave.bin", std::ios::out | std::ios::binary);
	if (file.is_open())
	{
		for (int i = 0; i < s.playerName.length(); i++)
		{
			file << s.playerName.at(i);
		}
		file << endl;
		file << s.deathCount << endl;
		file << s.deepestFloor << endl;
		file << s.hasBeenBeatenGame << endl;
		file << s.timePlayed << endl;
	}
	file.flush();
	file.close();
}

void NewData(saveData& s)
{
	cout << "Enter name:" << endl;
	cin >> s.playerName;
	cout << "Enter deaths:" << endl;
	cin >> s.deathCount;
	cout << "Enter deepest floor:" << endl;
	cin >> s.deepestFloor;
	cout << "Have you won? [Y]/[N]" << endl;
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
	{
		s.hasBeenBeatenGame = true;
	}
	else
	{
		s.hasBeenBeatenGame = false;
	}
	cout << "Enter time played (seconds):" << endl;
	cin >> s.timePlayed;
}

void PrintData(saveData& s)
{
	cout << "Name: " << s.playerName << endl;
	cout << "Deaths: " << s.deathCount << endl;
	cout << "Deepest Floor: " << s.deepestFloor << endl;
	if (s.hasBeenBeatenGame)
	{
		cout << "Has Beatten Game: Yes" << endl;
	}
	else
	{
		cout << "Has Beatten Game: No" << endl;
	}
	cout << "Time Played (Seconds): " << s.timePlayed << endl;
}