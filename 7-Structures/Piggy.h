#pragma once

struct piggybank
{
	int ones;
	int twos;
	int fives;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
};

float calcPiggybankNotes(piggybank piggy);
float calcPiggybankCoins(piggybank piggy);
float calcPiggybankTotal(piggybank piggy);
void piggyDeposit(piggybank &piggy, float val);
