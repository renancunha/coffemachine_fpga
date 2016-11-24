#include "Controller.h"

Controller::Controller(){

}

bool Controller::needToResupply(coffeTypes coffeType, bool isWithSugar)
{
	if(isWithSugar && sugarReservoir.getAmount() == 0)
	{
		return true;
	}

	switch(coffeType)
	{
		case T_COFFE:
			return coffeReservoir.getAmount() == 0;
		break;

		case T_COFFEMILK:
			return coffeReservoir.getAmount() == 0 &&
					milkReservoir.getAmount() == 0;
		break;

		case T_MOCACCHINO:
			return coffeReservoir.getAmount() == 0 &&
					milkReservoir.getAmount() == 0 &&
					chocolateReservoir.getAmount() == 0;
		break;

		case T_NONE:
			return false;
			break;
	}
}

void Controller::refill(coffeTypes coffeType, bool isWithSugar)
{
	if(isWithSugar)
	{
		sugarReservoir.setAmount(10);
	}

	switch(coffeType)
	{
		case T_COFFE:
			coffeReservoir.setAmount(10);
		break;

		case T_COFFEMILK:
			coffeReservoir.setAmount(10);
			milkReservoir.setAmount(10);
		break;

		case T_MOCACCHINO:
			coffeReservoir.setAmount(10);
			milkReservoir.setAmount(10);
			chocolateReservoir.setAmount(10);
		break;

		case T_NONE:
			break;
	}
}

void Controller::make(coffeTypes coffeType, bool isWithSugar)
{

}
