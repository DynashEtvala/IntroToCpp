#include<iostream>
#include"Helpers.h"

int GuessNumber(int l, int h)
{
	char choice = 0;
	std::cout << "Is your number [H]igher than, [L]ower than, or [E]qual to " << (h - l) / 2 + l << "?" << std::endl;
	std::cout << std::endl;
	std::cin >> choice;
	std::cout << std::endl;
	switch (choice)
	{
	case 'h':
	case 'H':
		return GuessNumber((h - l) / 2 + l + 1, h);
	case 'l':
	case 'L':
		return GuessNumber(l, (h - l) / 2 + l - 1);
	case 'e':
	case 'E':
		return (h - l) / 2 + l;
	}
	return -1;
}