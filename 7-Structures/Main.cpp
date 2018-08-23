#include<iostream>
#include"Vector2.h"
#include"Circle.h"
#include"Piggy.h"
#include"Student.h"

int main() 
{
	vector2 a;
	a.x = 2;
	a.y = 5;
	vector2 b;
	b.x = 3;
	b.y = 8;

	vector2 c = vectorSum(a, b);
	vector2 d = vectorDif(a, b);
	float e = vectorDist(a, b);

	return 0;
}