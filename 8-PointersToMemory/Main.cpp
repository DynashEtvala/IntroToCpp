#include<iostream>
using namespace std;

void printFloats(float * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int arraySum(int * arr, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += *(arr + i);
	}
	return result;
}

void initBools(bool * arr, int size, bool defaultValue)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = defaultValue;
	}
}

int* intSubArr(bool * arr, int start, int end)
{
	int hold = 0;
	int * result = &hold;
	for (int i = 0; i < end - start; i++)
	{
		result[i] = arr[start + i];
	}
	return result;
}

char* pointerToElement(char * arr, int size, char goal, bool sensitive)
{
	if (sensitive)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == goal)
			{
				return &arr[i];
			}
		}
	}
	else
	{
		if (goal >= 65 && goal <= 90)
		{
			goal += 32;
		}
		for (int i = 0; i < size; i++)
		{
			if (arr[i] >= 65 && arr[i] <= 90 && arr[i] + 32 == goal)
			{
				return &arr[i];
			}
		}
	}
	return nullptr;
}

void swapPointers(int &a, int &b)
{
	int hold = a;
	a = b;
	b = hold;
}

int main()
{


	return 0;
}