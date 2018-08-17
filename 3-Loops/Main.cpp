#include<iostream>

void PrintXY(int X, int Y);

int PromptLargest(int count);

int main() 
{
	for (int i = 1; i <= 100; i++)
	{
		std::cout << i << std::endl;
	}

	for (int i = 100; i > 0; i--)
	{
		std::cout << i << std::endl;
	}

	for (int i = 1995; i <= 2018; i++)
	{
		std::cout << i << std::endl;
	}

	/*int x = 0;
	int y = 0;
	std::cin >> x;
	std::cin >> y;
	PrintXY(x, y);*/

	std::cout << PromptLargest(23) << std::endl;

	system("pause");

	return 0;
}

void PrintXY(int X, int Y)
{
	std::cout << X;

	for (int i = X; X <= Y; i++)
	{
		std::cout << ", " << i;
	}
	std::cout << std::endl;
}

int PromptLargest(int count)
{
	int largest = 0;
	int hold = 0;

	for (int i = 1; i <= count; i++)
	{
		std::cout << "What is your " << i;
		switch (i%10)
		{
		case 1:
			std::cout << "st ";
			break;
		case 2:
			std::cout << "nd ";
			break;
		case 3:
			std::cout << "rd";
			break;
		default:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 0:
			std::cout << "th ";
			break;
		}
		std::cout << "number?" << std::endl;
		std::cin >> hold;
		if (hold > largest)
		{
			largest = hold;
		}
	}


	return largest;
}