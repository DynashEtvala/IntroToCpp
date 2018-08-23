#include<iostream>
#include<cmath>
#include"Vector2.h"

vector2 vectorSum(vector2 a, vector2 b)
{
	vector2 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return result;
}

vector2 vectorDif(vector2 a, vector2 b)
{
	vector2 result;
	result.x = abs(a.x - b.x);
	result.y = abs(a.y - b.y);
	return result;
}

float vectorDist(vector2 a, vector2 b)
{
	return sqrtf(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}