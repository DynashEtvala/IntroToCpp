#include"Helpers.h"

int StringLength(char* base)
{
	int result = 0;
	while(base[result] != '\0')
	{
		result++;
	}
	return result;
}

void Greeting(char* name)
{
	cout << "Hello " << name << "!" << endl;
}

void ShiftCipher(char* base, int shift)
{
	for (int i = 0; i < StringLength(base); i++)
	{
		if ((base[i] >= 65 && base[i] <= 87) || (base[i] >= 97 && base[i] <= 119))
		{
			base[i] += shift;
		}
		else if ((base[i] >= 88 && base[i] <= 90) || (base[i] >= 120 && base[i] <= 122))
		{
			base[i] -= 23;
		}
	}
}

void ToUpper(char* base)
{
	for (int i = 0; i < StringLength(base); i++)
	{
		if (base[i] >= 97 && base[i] <= 122)
		{
			base[i] -= 32;
		}
	}
}

void ToLower(char* base)
{
	for (int i = 0; i < StringLength(base); i++)
	{
		if (base[i] >= 65 && base[i] <= 90)
		{
			base[i] += 32;
		}
	}
}

void RemoveWhitespace(char* base)
{
	for (int i = 0; i < StringLength(base); i++)
	{
		if (base[i] == ' ')
		{
			for (int j = i; j < StringLength(base); j++)
			{
				base[j] = base[j + 1];
			}
		}
	}
}

void Substring(char* base, int start)
{
	for (int i = 0; i < StringLength(base) - start + 1; i++)
	{
		base[i] = base[i + start];
	}
}

void Substring(char* base, int start, int end)
{
	for (int i = 0; i < end - start + 1; i++)
	{
		base[i] = base[i + start];
	}
}

void TrimString(char* base)
{
	while (base[0] == ' ')
	{
		for (int i = 0; i < StringLength(base); i++)
		{
			base[i] = base[i + 1];
		}
	}
	while (base[StringLength(base) - 1] == ' ')
	{
		base[StringLength(base) - 1] = '\0';
	}
}

bool Palendrome(char* base)
{
	for (int i = 0; i < StringLength(base) / 2; i++)
	{
		if (base[i] != base[StringLength(base) - i - 1])
		{
			return false;
		}
	}
	return true;
}