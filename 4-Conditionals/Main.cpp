#include<iostream>

int main()
{
	int numberA = 0;

	std::cout << "Give me a number 1 - 100" << std::endl;
	std::cout << std::endl;
	std::cin >> numberA;

	if (numberA >= 1 && numberA <= 100)
	{
		if (numberA < 50)
		{
			std::cout << numberA << " is a small number" << std::endl;
		}
		else if (numberA > 50)
		{
			std::cout << numberA << " is a large number" << std::endl;
		}
		else
		{
			std::cout << numberA << " is a balanced number" << std::endl;
		}
	}

	std::cout << "What's your age?" << std::endl;
	std::cout << std::endl;
	std::cin >> numberA;

	if (numberA < 18)
	{
		std::cout << "You are a minor." << std::endl;
	}
	else
	{
		std::cout << "You are an adult.";
		if (numberA >= 50)
		{
			std::cout << " You are eligible for AARP.";
			if (numberA >= 65)
			{
				std::cout << " You are eligible for retirement benefits.";
			}
		}
	}

	int hold = 0;
	int smallest = 99999999;

	for (int i = 1; i <= 3; i++)
	{
		std::cout << "What is your " << i;
		switch (i % 10)
		{
		default:
		case 1:
			std::cout << "st ";
			break;
		case 2:
			std::cout << "nd ";
			break;
		case 3:
			std::cout << "rd ";
			break;
		}
		std::cout << "number?" << std::endl;
		std::cin >> hold;
		if (hold < smallest)
		{
			smallest = hold;
		}
	}

	std::cin >> numberA;

	if (numberA % 2 == 0)
	{
		std::cout << "Even, ";
	}
	else
	{
		std::cout << "Odd, ";
	}

	std::cin >> numberA;

	if (numberA < 15)
	{
		std::cout << 15 << std::endl;
	}
	else if (numberA > 30)
	{
		std::cout << 30 << std::endl;
	}
	else
	{
		std::cout << numberA << std::endl;
	}

	//Challenge

	int numberB = 23;

	numberB = numberB >= 20 ? numberB * 5 : numberB;

	int numberC = 6;

	numberC = numberC < 20 ? numberC - 5 : numberC / 2;

	return 0;
}