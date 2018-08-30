#include<iostream>
#include"Helpers.h"

int GuessNumber(int l, int h)
{
	char choice = 0;
	//prompt for if computers guess is correct
	std::cout << "Is your number [H]igher than, [L]ower than, or [E]qual to " << (h - l) / 2 + l << "?" << std::endl;
	std::cout << std::endl;
	//take input
	std::cin >> choice;
	std::cout << std::endl;
	system("CLS");
	//process input
	switch (choice)
	{
		//number is higher than guess
	case 'h':
	case 'H':
		//call function again but change range to exclude numbers that are lower than current guess. return result.
		return GuessNumber((h - l) / 2 + l + 1, h);
		//number is lower than guess
	case 'l':
	case 'L':
		//call function again but change range to exclude numbers that are higher than current guess. return result.
		return GuessNumber(l, (h - l) / 2 + l - 1);
		//guess was correct
	case 'e':
	case 'E':
		//return guess
		return (h - l) / 2 + l;
	}
	//return -1 if failed
	return -1;
}