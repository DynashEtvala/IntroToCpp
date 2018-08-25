#include<iostream>
#include"Helpers.h"

int main()
{
	bool quit = false;
	int guessmax = 100;
	int guess = -1;
	while (!quit)
	{
		std::cout << "Think of a number between 1 and " << guessmax << ". Press enter when you have." << std::endl;
		std::cout << std::endl;
		std::cin.get();

		guess = GuessNumber(1, guessmax);

		std::cout << "Iguessed your number! It's " << guess << "!" << std::endl;

		char again = 0;
		std::cout << "Play again? [Y]es/[N]o" << std::endl;
		std::cout << std::endl;
		std::cin >> again;
		std::cout << std::endl;
		if (again == 'n' || again == 'N')
		{
			quit = true;
		}
	}

	return 0;
}