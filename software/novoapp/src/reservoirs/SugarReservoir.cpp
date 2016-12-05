#include "SugarReservoir.h"


SugarReservoir::SugarReservoir(){
	this->amount = 10;
}

void SugarReservoir::setAmount(int amount)
{
	this->amount = amount;
}

int SugarReservoir::getAmount()
{
	return this->amount;
}
