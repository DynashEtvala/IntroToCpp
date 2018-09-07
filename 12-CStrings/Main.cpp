#include "Helpers.h"

int main()
{
	// storing a string literal in an array
	char name[50] = "Hello C-Strings!";

	// printing letter by letter by hand
	for (int i = 0; i < 50; ++i)
	{
		std::cout << name[i];

		if (name[i] == '\0')
		{
			break;
		}
	}

	// printing the whole string
	std::cout << name << std::endl;

	// input buffer
	char input[50] = {};

	// prompting for a string (up to the size of the array)
	// note that you can store 49 characters + 1 for null-terminator
	// note that this also stops at the first whitespace character (e.g. space, newline)
	std::cin >> input;

	std::cin.getline(input, 50);

	std::cout << "You said: " << input << std::endl;

	char personA[50] = "John";
	char personB[50] = "John";

	// strcmp
	if (strcmp(personA, personB) == 0)
	{
		std::cout << "Names match!" << std::endl;
	}
	else
	{
		std::cout << "Names don't match!" << std::endl;
	}

	// strlen
	char yourName[255] = {};

	std::cin.getline(yourName, 255);

	std::cout << "Your name is " << std::strlen(yourName) << " characters long, and is " << yourName << "." << std::endl;

	ShiftCipher(yourName, 1);

	std::cout << yourName << std::endl;

	return 0;
}