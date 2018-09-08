#include"Helpers.h"

void Append(char* a, char* b)
{
	for (int i = 0; i <= strlen(b); i++)
	{
		a[strlen(a) + i] = b[i];
	}
}

void Insert(char* a, char* b, int loc)
{
	for (int i = 0; i < strlen(b); i++)
	{
		for (int j = strlen(a); j > loc + i; j--)
		{
			a[j + 1] = a[j];
		}
		a[loc + i] = b[i];
	}
}

int WordCount(char* a)
{
	int result = 0;
	for (int i = 1; i <= strlen(a); i++)
	{
		if (!((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)) && ((a[i - 1] >= 65 && a[i - 1] <= 90) || (a[i - 1] >= 97 && a[i - 1] <= 122)))
		{
			result++;
		}
	}
	return result;
}

void Break(char* a, int breakPoint)
{
	for (int i = breakPoint; i < strlen(a); i += breakPoint + 1)
	{
		if (a[i] != ' ' && a[i] != '\n')
		{
			for (int j = i - 1; j > i - breakPoint + 1; j--)
			{
				if (a[j] == ' ')
				{
					a[j] = '\n';
					i = j;
				}
			}
		}
		else
		{
			a[i] = '\n';
		}
	}
}

char ToLower(char c)
{
	if (c >= 65 && c <= 90)
	{
		return c + 32;
	}
	return c;
}