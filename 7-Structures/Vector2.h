#pragma once

struct vector2
{
	float x;
	float y;
};

vector2 vectorSum(vector2 a, vector2 b);
vector2 vectorDif(vector2 a, vector2 b);
float vectorDist(vector2 a, vector2 b);