#include <iostream>
#include <fstream>
#include <string>
#include "Bestiary.h"
#include "Helpers.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;

bool testWrite(std::string filePath, std::string message)
{
	std::fstream file;

	// open a file relative to the working directory of the project
	file.open(filePath.c_str(), std::ios::out | std::ios::binary);

	// verify that the file is open
	if (file.fail())
	{
		std::cerr << "File not found." << std::endl;
		return false;
	}

	// reset error flags (such as EOF)
	file.clear();

	// move the cursor to the end of the file for writing
	file.seekp(0, std::ios_base::end);

	// write a message to the text file
	file << message;

	file.flush();   // flush the output buffer, making sure all outputs are sent
	file.close();   // close and release the file

	return true;
}

std::string testRead(std::string filePath)
{
	std::fstream file;

	// open a file relative to the working directory of the project
	file.open(filePath.c_str(), std::ios::in | std::ios::binary);

	// verify that the file is open
	if (file.fail())
	{
		std::cerr << "File not found." << std::endl;
		return "";
	}

	std::string buffer;
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		// we don't really need to do anything while reading
	}

	// reset error flags (such as EOF)
	file.clear();

	// close and release the file
	file.close();

	return buffer;
}



int main()
{
	testWrite("test.bin", "yo");    // write "yo" to the file
	std::cout << testRead("test.bin");  // read "yo" from the file

	saveData s;
	LoadData(s);
	PrintData(s);
	NewData(s);
	SaveData(s);

	Bestiary();

	return 0;
}