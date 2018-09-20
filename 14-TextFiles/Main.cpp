#include"Helpers.h"

using namespace std;

int main()
{
	srand(time(NULL));

	fstream file;

	// open a file relative to the working directory of the project
	file.open("test.txt", ios::out);

	// verify that the file is open
	if (file.fail())
	{
		cerr << "File not found." << endl;
		return -1;
	}

	string buffer;
	while (getline(file, buffer))  // iterates until error or EOF
	{
		// print the line after it is buffered
		cout << buffer << endl;
	}

	// reset error flags (such as EOF)
	file.clear();

	// move the cursor to the end of the file for writing
	file.seekp(0, ios_base::end);

	// write a message to the text file
	file << "Howdy Text!";

	file.flush();   // flush the output buffer, making sure all outputs are sent
	file.close();   // close and release the file

	return 0;
}