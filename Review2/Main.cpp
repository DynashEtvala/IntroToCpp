#include"Helpers.h"
#include"AddressBook.h"

int main()
{
	contact aa;
	aa.name = "Adrian";
	aa.phone = 1;
	cout << aa.name << endl;
	AddressBook book = AddressBook(aa);
	contact ab;
	ab.name = "Anderson";
	ab.phone = 2;
	contact abc;
	abc.name = "Amelia";
	abc.phone = 3;
	contact b;
	b.name = "Jason";
	b.phone = 4;
	contact ba;
	ba.name = "Jacob";
	ba.phone = 5;
	contact c;
	c.name = "Jessey";
	c.phone = 6;
	book.AddContact(c);
	book.AddContact(abc);
	book.AddContact(b);
	book.AddContact(ab);
	book.AddContact(ba);
	book.ViewContacts();
	book.SortContacts();
	cout << endl;
	book.ViewContacts();
	return 0;
}