#include "ChocolateReservoir.h"


ChocolateReservoir::ChocolateReservoir(){
	this->amount = 10;
}

void ChocolateReservoir::setAmount(int amount)
{
	this->amount = amount;
}

int ChocolateReservoir::getAmount()
{
	return this->amount;
}
