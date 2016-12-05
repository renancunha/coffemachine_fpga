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
			if(coffeReservoir.getAmount() == 0)
				return true;
			else
				return false;
		break;

		case T_COFFEMILK:
			if(coffeReservoir.getAmount() == 0 ||
					milkReservoir.getAmount() == 0)
				return true;
			else
				return false;
		break;

		case T_MOCACCHINO:
			if(coffeReservoir.getAmount() == 0 ||
					milkReservoir.getAmount() == 0 ||
					chocolateReservoir.getAmount() == 0)
				return true;
			else
				return false;
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

void Controller::make(coffeTypes coffeType, bool isWithSugar, bool cupSize)
{
	int wait_time = 0;

	if(isWithSugar)
	{
		sugarReservoir.setAmount(sugarReservoir.getAmount() - 1);
		wait_time += 1000000;
	}

	switch(coffeType)
	{
		case T_COFFE:
			coffeReservoir.setAmount(coffeReservoir.getAmount() - 1);
			wait_time += 1000000;
		break;

		case T_COFFEMILK:
			coffeReservoir.setAmount(coffeReservoir.getAmount() - 1);
			milkReservoir.setAmount(milkReservoir.getAmount() - 1);
			wait_time += 2000000;
		break;

		case T_MOCACCHINO:
			coffeReservoir.setAmount(coffeReservoir.getAmount() - 1);
			milkReservoir.setAmount(milkReservoir.getAmount() - 1);
			chocolateReservoir.setAmount(chocolateReservoir.getAmount() - 1);
			wait_time += 3000000;
		break;

		case T_NONE:
			break;
	}

	if(cupSize)
	{
		wait_time += 10000000;
	}
	else
	{
		wait_time += 5000000;
	}

	usleep(wait_time);

}

int Controller::getWaterLevel()
{
	return this->waterReservoir.getLevel();
}

int Controller::getWaterTemp()
{
	return this->waterReservoir.getTemp();
}
