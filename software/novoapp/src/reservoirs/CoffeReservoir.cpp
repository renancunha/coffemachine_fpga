#include "CoffeReservoir.h"


CoffeReservoir::CoffeReservoir(){
	this->amount = 10;
}

void CoffeReservoir::setAmount(int amount)
{
	this->amount = amount;
}

int CoffeReservoir::getAmount()
{
	return this->amount;
}
