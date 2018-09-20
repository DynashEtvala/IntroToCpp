#include"Helpers.h"

using namespace std;

void PrintFile()
{
	fstream file;
	cout << "What file would you like to read?" << endl << endl;
	string fName;
	cin >> fName;
	file.open(fName, ios::in | ios::_Nocreate);
	if (file.is_open)
	{
		cout << endl << fName << endl << "----------------" << endl;
		string buffer;
		while (getline(file, buffer))
		{
			cout << buffer << endl;
		}
		cout << endl;
	}
	else
	{
		cout << endl << "File does not exist for failed to open." << endl << endl;
	}
	file.flush();
	file.close();
}

void SaveInfo()
{
	fstream file;
	cout << "Where would you like to save this?" << endl << endl;
	string input;
	cin >> input;
	file.open(input, ios::out);
	if (file.is_open)
	{
		cout << endl << "What is your name?" << endl << endl;
		cin >> input;
		file << "Name: " << input << endl;
		cout << endl << "How old are you?" << endl << endl;
		cin >> input;
		file << "Age: " << input << endl;
		cout << endl << "What is your favorite color?" << endl << endl;
		cin >> input;
		file << "Favorite Color: " << input << endl;
	}
	else
	{
		cout << endl << "File failed to open or create." << endl << endl;
	}
	file.flush();
	file.close();
}

void Corrupt(float chance)
{
	fstream file;
	cout << "What file would you like to read?" << endl << endl;
	string fName;
	cin >> fName;
	file.open(fName, ios::in | ios::_Nocreate);
	if (file.is_open)
	{
		cout << endl;
		for (int i = 0; i < fName.length(); i++)
		{
			if ((((float)(rand() % 100 + 1)) / 100) < chance)
			{
				fName.at(i) = '\219';
			}
		}
		cout << fName << endl;
		for (int i = 0; i < 16; i++)
		{
			if ((((float)(rand() % 100 + 1)) / 100) < chance)
			{
				cout << '\219';
			}
			else
			{
				cout << '-';
			}
		}
		cout << endl;
		string buffer;
		while (getline(file, buffer))
		{
			for (int i = 0; i < buffer.length(); i++)
			{
				if ((((float)(rand() % 100 + 1)) / 100) < chance)
				{
					buffer.at(i) = '\219';
				}
			}
			cout << buffer << endl;
		}
		cout << endl;
	}
	else
	{
		cout << endl << "File does not exist for failed to open." << endl << endl;
	}
	file.flush();
	file.close();
}

int* ValArray()
{
	int* result = new int[];
	fstream file;
	cout << "What are you pulling your array from?" << endl << endl;
	string fName;
	cin >> fName;
	file.open(fName, ios::in | ios::_Nocreate);
	if (file.is_open)
	{
		int i = 0;
		while (!file.eof())
		{
			file >> result[i];
			i++;
		}
	}
	else
	{
		cout << endl << "File does not exist for failed to open." << endl << endl;
	}
	file.flush();
	file.close();
	return result;
}

entity* LoadEntity()
{
	entity* result = new entity[1];
	int entSize = 1;
	int contained = 1;
	fstream file;
	cout << "What file would you like to load from?" << endl << endl;
	string fName;
	cin >> fName;
	file.open(fName, ios::in | ios::_Nocreate); 
	if (file.is_open)
	{
		string line;
		while (getline(file, line))
		{
			if (line.length() == 0 && line[0] != '@')
			{
				continue;
			}
			entity temp;
			temp.name = line;
			getline(file, line);
			temp.hitpoints = stof(line);
			getline(file, line);
			temp.armor = stof(line);
			getline(file, line);
			temp.strength = stoi(line);
			getline(file, line);
			temp.defense = stoi(line);
			getline(file, line);
			temp.agility = stoi(line);
			getline(file, line);
			temp.luck = stoi(line);

		}
	}
	else
	{
		cout << endl << "File does not exist for failed to open." << endl << endl;
		return NULL;
	}
	file.flush();
	file.close();
	return result;
}