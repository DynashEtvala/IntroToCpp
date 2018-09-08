#include "AddressBook.h"



AddressBook::AddressBook(contact& c)
{
	contacts[0] = c;
	totalContacts = 1;
}

bool AddressBook::DoLonger(int s, int e, int l, char c)
{
	for (int i = s; i <= e; i++)
	{
		if (contacts[i].name.at(l - 1) == c && contacts[i].name.length() > l)
		{
			return true;
		}
	}
	return false;
}

void AddressBook::Delete(int loc)
{
	for (int i = loc; i < totalContacts - 1; i++)
	{
		contacts[i] = contacts[i + 1];
	}
	totalContacts--;
}

void AddressBook::SortContacts(int s, int e, int layer)
{
	for (int i = s; i <= e; i++)
	{
		for (int j = i; j > s && ToLower(contacts[j - 1].name.at(layer)) > ToLower(contacts[j].name.at(layer)); j--)
		{
			contact hold = contacts[j - 1];
			contacts[j - 1] = contacts[j];
			contacts[j] = hold;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		//if (DoLonger(s, e, layer + 1, i))
		{
			int first = -1;
			int last = -1;
			for (int j = s; j <= e; j++)
			{
				if (first == -1 && ToLower(contacts[j].name.at(layer)) == i)
				{
					first = j;
				}
				if (last == -1 && ToLower(contacts[j].name.at(layer)) == i && (j == e || ToLower(contacts[j].name.at(layer)) != ToLower(contacts[j + 1].name.at(layer))))
				{
					last = j;
				}
				if (first != -1 && last != -1 && first < last)
				{
					SortContacts(first, last, layer + 1);
				}
			}
		}
	}
}

void AddressBook::AddContact(contact& c)
{
	contacts[totalContacts] = c;
	totalContacts++;
}

void AddressBook::RemoveContact(string n)
{
	for (int i = 0; i < totalContacts; i++)
	{
		if (contacts[i].name == n)
		{
			Delete(i);
		}
	}
}

void AddressBook::RemoveContact(int p)
{
	for (int i = 0; i < totalContacts; i++)
	{
		if (contacts[i].phone == p)
		{
			Delete(i);
		}
	}
}

void AddressBook::SortContacts()
{
	for (int i = 0; i < totalContacts; i++)
	{
		for (int j = i; j > 0 && ToLower(contacts[j - 1].name.front()) > ToLower(contacts[j].name.front()); j--)
		{
			contact hold = contacts[j - 1];
			contacts[j - 1] = contacts[j];
			contacts[j] = hold;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		//if (DoLonger(0, totalContacts - 1, 1, i))
		{
			int first = -1;
			int last = -1;
			for (int j = 0; j < totalContacts; j++)
			{
				if (first == -1 && ToLower(contacts[j].name.front()) == i)
				{
					first = j;
				}
				if (last == -1 && ToLower(contacts[j].name.front()) == i && (j == totalContacts - 1 || ToLower(contacts[j].name.at(0)) != ToLower(contacts[j + 1].name.front())))
				{
					last = j;
				}
				if (first != -1 && last != -1 && first < last)
				{
					SortContacts(first, last, 1);
				}
			}
		}
	}
}

void AddressBook::ViewContacts()
{
	for (int i = 0; i < totalContacts; i++)
	{
		cout << contacts[i].name << " - " << contacts[i].phone << endl;
	}
}