#include<iostream>

int main() 
{
	std::cout << "Hello AIE" << std::endl; //print Hello AIE
	std::cout << "Mercury - Sleeping at Last" << std::endl << "Cruel Wars - Longest Johns" << std::endl; //print track list

	for (int i = 0; i <= 5; i++) //print numbers 0-5 inclusive
	{
		std::cout << i << std::endl;
	}

	for (int i = 5; i >= 0; i--) //print numbers 5-0 inclusive
	{
		std::cout << i << std::endl;
	}

	system("pause"); //pause before open exercise 1

	std::cout << "Howdy AIE" << std::endl;
	std::cout << "It's a fine day today as any!" << std::endl; //required semicolon on this line
	std::cout << "I really wish I had some potatoes..." << std::endl;

	system("pause"); //pause before open exercise 2

	std::cout << "Four score and seven years ago" << std::endl;
	std::cout << "our fathers brought forth on this continent," << std::endl;
	std::cout << "a new nation," << std::endl;
	std::cout << "conceived in Libery, and dedicated to the proposition" << std::endl;
	std::cout << "that all men are created equal." << std::endl;

	std::cout << "Now we are engaged in a great civil war," << std::endl;
	std::cout << "testing whether that nation, or any nation" << std::endl; //string never concluded
	std::cout << "so conceived and so dedicated, can long endure." << std::endl;

	system("pause"); //pause before end of program

	return 0;
}