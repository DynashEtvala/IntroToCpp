#include"Bestiary.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::getline;
using std::ios;
using std::stoi;

namespace fs = std::experimental::filesystem;

void Bestiary()
{
	bool quit = false;
	int input;
	fileTrack tracker = GetMonsterPaths();
	cout << "Welcome to Monster Creature Quest." << endl << endl;
	while (!quit)
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1) Add a monster by ID" << endl;
		cout << "2) Remove a monster by ID" << endl;
		cout << "3) View monster by ID" << endl;
		cout << "4) Browse Monsters" << endl;
		cout << "5) Quit" << endl << endl;
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 1:
			AddMonster(tracker);
			tracker = GetMonsterPaths();
			break;
		case 2:
			RemoveMonster(tracker);
			tracker = GetMonsterPaths();
			break;
		case 3:
			ViewMonster(tracker);
			break;
		case 4:
			BrowseMonsters(tracker);
			break;
		case 5:
			quit = true;
			break;
		default:
			cout << "Input invalid." << endl << endl;
			break;
		}
	}
}

fileTrack GetMonsterPaths()
{
	fileTrack result;
	int count = 0;
	for (auto & p : fs::directory_iterator("bestiary"))
	{
		result.fPaths[count] = p.path().string().substr(9, 50);
		count++;
	}
	result.count = count;
	return result;
}

void AddMonster(fileTrack& track)
{
	string input;
	bool oktogo = false;
	int id;
	string name;
	string description = "";
	while (!oktogo)
	{
		cout << "What 3 digit ID would you like to use for this monster?" << endl << endl;
		cin >> input;
		cout << endl;
		if (stoi(input) > 0 && stoi(input) < 100 && !IDExists(track, stoi(input)))
		{
			id = stoi(input);
			oktogo = true;
		}
		else
		{
			cout << "Invalid ID." << endl << endl;
		}
	}
	oktogo = false;
	while (!oktogo)
	{
		cout << "What is the monster called?" << endl << endl;
		cin >> input;
		cout << endl;
		if (NameExists(track, input))
		{
			cout << "Monster already exists." << endl << endl;
		}
		else
		{
			name = input;
			oktogo = true;
		}
	}
	fstream file;
	file.open("bestiary/" + SToLowerOf(name) + ".bin", ios::out | ios::binary);
	file << id << endl;
	file << name.c_str() << endl;
	oktogo = false;
	cout << "Describe this monster. Submit each line by pressing enter. When you're done simply type \"DONE\" (case sensitive)" << endl << endl;
	while (!oktogo)
	{
		std::getline(cin, input);
		if (input == "DONE")
		{
			oktogo = true;
		}
		else
		{
			description += input;
			description += "\n";
		}
	}
	if (description == "")
	{
		description = "None have lived to describe this beast.";
	}
	cout << endl;
	for (int i = 0; i < description.length(); i++)
	{
		file << description.at(i);
	}
	file.flush();
	file.close();
}

void RemoveMonster(fileTrack& track)
{
	int input;
	fstream file;
	bool oktogo = false;
	while (!oktogo)
	{
		cout << "What monster do you want to remove? Or type \"0\" to go back." << endl;
		cin >> input;
		if (IDExists(track, input))
		{
			for (int i = 0; i < track.count; i++)
			{
				file.open("bestiary/" + track.fPaths[i], ios::in | ios::binary);
				string line;
				getline(file, line);
				file.close();
				if (stoi(line) == input)
				{
					string temp = "bestiary/" + track.fPaths[i];
					int debug = remove(temp.c_str());
				}
				else
				{
					continue;
				}
				oktogo = true;
				break;
			}
		}
		else if (input == 0)
		{
			oktogo = true;
		}
		else
		{
			cout << "That monster doesn't exist" << endl;
		}
	}
}

void ViewMonster(fileTrack& track)
{
	int input;
	fstream file;
	bool oktogo = false;
	while (!oktogo)
	{
		cout << "What monster would you like to view? Or type \"0\" to go back." << endl << endl;
		cin >> input; 
		cout << endl;
		if (IDExists(track, input))
		{
			for (int i = 0; i < track.count; i++)
			{
				file.open("bestiary/" + track.fPaths[i], ios::in | ios::binary);
				string line;
				getline(file, line);
				if (stoi(line) == input)
				{
					cout << line << " - ";
					getline(file, line);
					cout << line << endl;
					while (getline(file, line))
					{
						cout << line << endl;
					}
					cout << endl;
				}
				else
				{

					file.close();
					continue;
				}
				file.close();
				oktogo = true;
				break;
			}
		}
		else if (input == 0)
		{
			oktogo = true;
		}
		else
		{
			cout << "That monster doesn't exist" << endl;
		}
	}
}

void BrowseMonsters(fileTrack& track)
{
	fstream file;
	string line;
	int* ids = new int[track.count];
	for (int i = 0; i < track.count; i++)
	{
		file.open("bestiary/" + track.fPaths[i], ios::in | ios::binary);
		getline(file, line);
		ids[i] = stoi(line);
		file.flush();
		file.close();
	}
	for (int i = 0; i < track.count; i++)
	{
		for (int j = i; j > 0 && ids[j - 1] > ids[j]; j--)
		{
			string hold = track.fPaths[j - 1];
			track.fPaths[j - 1] = track.fPaths[j];
			track.fPaths[j] = hold;
		}
	}
	for (int i = 0; i < track.count; i++)
	{
		file.open("bestiary/" + track.fPaths[i], ios::in | ios::binary);
		getline(file, line);
		cout << line << " - ";
		getline(file, line);
		cout << line << endl;
		file.flush();
		file.close();
	}
	cout << endl;
	delete ids;
}

bool NameExists(fileTrack& track, string name)
{
	SToLower(name);
	for (int i = 0; i < track.count; i++)
	{
		string debug = track.fPaths[i].substr(0, track.fPaths[i].length() - 4);
		if (name == debug)
		{
			return true;
		}
	}
	return false;
}

bool IDExists(fileTrack& track, int id)
{
	fstream file;
	for (int i = 0; i < track.count; i++)
	{
		string line;
		file.open("bestiary/" + track.fPaths[i], ios::in | ios::binary);
		getline(file, line);
		if (stoi(line) == id)
		{
			file.flush();
			file.close();
			return true;
		}
		file.flush();
		file.close();
	}
	return false;
}

void SToLower(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s.at(i) = tolower(s.at(i));
	}
}

string SToLowerOf(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s.at(i) = tolower(s.at(i));
	}
	return s;
}