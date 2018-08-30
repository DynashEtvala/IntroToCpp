#include <iostream>
using namespace std;

void Quiz()
{
	int corr = 0;
	char input = 0;
	cout << "What is the capital of Washington?" << endl << "A) Belvue" << endl << "B) Olympia" << endl << "C) Seattle" << endl << "D) Yakima" << endl;
	cin >> input;
	if (input == 'b' || input == 'B')
	{
		corr++;
	}

	cout << "Which of the following nations has the largest population as of 2018?" << endl << "A) North Korea" << endl << "B) Luxenbourg" << endl << "C) Denmark" << endl << "D) Syria" << endl;
	cin >> input;
	if (input == 'a' || input == 'A')
	{
		corr++;
	}

	cout << "Which of the following locations does not have an AIE campus?" << endl << "A) Canberra, Australia" << endl << "B) Lafayette, Louisana" << endl << "C) Brisbane, Australia" << endl << "D) Adelaide, Australia" << endl;
	cin >> input;
	if (input == 'c' || input == 'C')
	{
		corr++;
	}
	if (corr == 3)
	{
		cout << "You passed!";
	}
	else
	{
		cout << "You failed with a score of " << corr << ". Try again later.";
	}
}

void Multiples(int mult, int amt)
{
	for (int i = 2; i <= amt; i++)
	{
		cout << i * mult << endl;
	}
}

int Candles(int arr[], int size)
{
	int result = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
		{
			result++;
		}
	}
	return result;
}

void RotateArray(int arr[], int size, int rot)
{
	for (int i = 0; i < rot; i++)
	{
		for (int j = 0; j < size - 1; i++)
		{
			int hold = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = hold;
		}
	}
}

int main()
{
	Quiz();
	Multiples(5, 6);

	return 0;
}