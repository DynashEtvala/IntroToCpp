#pragma once
#include"Helpers.h"

struct contact
{
	string name;
	int phone;
};

class AddressBook
{
private:
	contact contacts[256];
	int totalContacts;
	bool DoLonger(int, int, int, char);
	void Delete(int);
	void SortContacts(int, int, int);
public:
	AddressBook(contact&);
	void AddContact(contact&);
	void RemoveContact(string);
	void RemoveContact(int);
	void SortContacts();
	void ViewContacts();
};

