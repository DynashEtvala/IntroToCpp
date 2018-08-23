#include<iostream>
#include"Piggy.h"

float calcPiggybankNotes(piggybank piggy)
{
	return piggy.ones + piggy.twos * 2 + piggy.fives * 5;
}

float calcPiggybankCoins(piggybank piggy)
{
	return piggy.pennies * 0.01f + piggy.nickels * 0.05f + piggy.dimes * 0.1f + piggy.quarters * 0.25f;
}

float calcPiggybankTotal(piggybank piggy)
{
	return calcPiggybankCoins(piggy) + calcPiggybankNotes(piggy);
}

void piggyDeposit(piggybank &piggy, float val)
{
	while (val >= 5.0f)
	{
		piggy.fives++;
		val -= 5.0f;
	}
	while (val >= 2.0f)
	{
		piggy.twos++;
		val -= 2.0f;
	}
	while (val >= 1.0f)
	{
		piggy.ones++;
		val -= 1.0f;
	}
	while (val >= 0.25f)
	{
		piggy.quarters++;
		val -= 0.25f;
	}
	while (val >= 0.1f)
	{
		piggy.dimes++;
		val -= 0.1f;
	}
	while (val >= 0.05f)
	{
		piggy.nickels++;
		val -= 0.05f;
	}
	while (val >= 0.01f)
	{
		piggy.pennies++;
		val -= 0.01f;
	}
}

void piggyWithdraw(piggybank &piggy, float val)
{
	if (calcPiggybankTotal(piggy) >= val)
	{
		while (val >= 5.0f)
		{
			piggy.fives--;
			val -= 5.0f;
		}
		while (val >= 2.0f)
		{
			piggy.twos--;
			val -= 2.0f;
		}
		while (val >= 1.0f)
		{
			piggy.ones--;
			val -= 1.0f;
		}
		while (val >= 0.25f)
		{
			piggy.quarters--;
			val -= 0.25f;
		}
		while (val >= 0.1f)
		{
			piggy.dimes--;
			val -= 0.1f;
		}
		while (val >= 0.05f)
		{
			piggy.nickels--;
			val -= 0.05f;
		}
		while (val >= 0.01f)
		{
			piggy.pennies--;
			val -= 0.01f;
		}
	}
	else
	{
		std::cout << "Unable to withdraw $" << val << "; not enough funds." << std::endl;
	}
}