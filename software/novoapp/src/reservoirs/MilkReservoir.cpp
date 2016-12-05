#include "MilkReservoir.h"


MilkReservoir::MilkReservoir(){
	this->amount = 10;
}

void MilkReservoir::setAmount(int amount)
{
	this->amount = amount;
}

int MilkReservoir::getAmount()
{
	return this->amount;
}
