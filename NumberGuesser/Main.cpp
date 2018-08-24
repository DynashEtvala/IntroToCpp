#include<iostream>

int main()
{
	bool quit = false;

	while (!quit)
	{
		int myNumber = rand() % 1000 + 1;
		bool play = true;
		while (play)
		{
			int guess = 0;
			std::cout << "I'm thinking of a number between 1 and 1000..." << std::endl;
			std::cout << std::endl;
			std::cin >> guess;
			if (guess < myNumber)
			{
				std::cout << "That's too low!" << std::endl;
			}
			else if (guess > myNumber)
			{
				std::cout << "That's too high!" << std::endl;
			}
			else
			{
				std::cout << "That's my number! Let's play again!" << std::endl;
				play = false;
			}
		}
	}

	return 0;
}