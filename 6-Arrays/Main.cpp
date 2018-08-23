#include<iostream>

void printNumbers(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
}

int sumNumbers(int numbers[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += numbers[i];
	}
	return result;
}

int smallestValue(int numbers[], int size)
{
	int result = numbers[0];
	for (int i = 1; i < size; i++)
	{
		result = result < numbers[i] ? result : numbers[i];
	}
	return result;
}

int largestValue(int numbers[], int size)
{
	int result = numbers[0];
	for (int i = 1; i < size; i++)
	{
		result = result > numbers[i] ? result : numbers[i];
	}
	return result;
}

int findValue(int numbers[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int findValue(int numbers[], int size, int value, int start)
{
	for (int i = start; i < size; i++)
	{
		if (numbers[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int countElements(int numbers[], int size, int value)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == value)
		{
			result++;
		}
	}
	return result;
}

int countElements(int numbers[], int size, int value, int start)
{
	int result = 0;
	for (int i = start; i < size; i++)
	{
		if (numbers[i] == value)
		{
			result++;
		}
	}
	return result;
}

int elementUnique(int numbers[], int size, int value)
{
	int result = countElements(numbers, size, value);
	switch (result)
	{
	case 1:
		std::cout << "Yes" << std::endl;
		break;
	case 0:
		std::cout << "Not Found" << std::endl;
		break;
	default:
		std::cout << "No" << std::endl;
		break;
	}
	return result;
}

bool arrayUnique(int numbers[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numbers[i] == numbers[j])
			{
				return false;
			}
		}
	}

	return true;
}

void reverseArray(int numbers[], int size)
{
	int hold = 0;
	for (int i = 0; i < size / 2; i++)
	{
		hold = numbers[i];
		numbers[i] = numbers[size - 1 - i];
		numbers[size - 1 - i] = hold;
	}
}

void sortArrayUp(int numbers[], int size)
{
	int hold = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numbers[i] > numbers[j])
			{
				hold = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = hold;
			}
		}
	}
}

void sortArrayDown(int numbers[], int size)
{
	int hold = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numbers[i] < numbers[j])
			{
				hold = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = hold;
			}
		}
	}
}

void insertionSort(int numbers[], int size)
{
	int hold = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
		{
			hold = numbers[j - 1];
			numbers[j - 1] = numbers[j];
			numbers[j] = hold;
		}
	}
}

int main() 
{
	int numbers[]{ 5, 1, 7, 3, 4, 9, 0 };
	int size = 7;

	insertionSort(numbers, size);
	printNumbers(numbers, size);

	return 0;
}