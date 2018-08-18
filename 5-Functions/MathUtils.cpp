#include"MathUtils.h"
#include<cmath>

int sum(int a, int b)
{
	return a + b;
}

int sum3(int a, int b, int c)
{
	return a + b + c;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int a, int b, int c)
{
	return max(a, min(b, c));
}

float distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}

float eta(float x1, float y1, float x2, float y2, float z)
{
	return distance(x1, y1, x2, y2) / z;
}

float linnearInterpolation(float a, float b, float c)
{
	return ((b - a) * c) + a;
}

char toUpper(char a)
{
	return a - 32;
}

char toLower(char a)
{
	return a + 32;
}