#include<iostream>
#include"Circle.h"
#include"Vector2.h"

bool CircleCircle(circle a, circle b)
{
	return a.r + b.r < vectorDist(a.pos, b.pos);
}