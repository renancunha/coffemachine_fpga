#include "Defs.h"
#include "reservoirs/CoffeReservoir.h"
#include "reservoirs/MilkReservoir.h"
#include "reservoirs/ChocolateReservoir.h"
#include "reservoirs/SugarReservoir.h"
//#include "reservoirs/WaterReservoir.h"

class Controller
{

public:
	Controller();

	CoffeReservoir coffeReservoir;
	MilkReservoir milkReservoir;
	ChocolateReservoir chocolateReservoir;
	SugarReservoir sugarReservoir;

	bool needToResupply(coffeTypes coffeType, bool isWithSugar);
	void refill(coffeTypes coffeType, bool isWithSugar);
	void make(coffeTypes coffeType, bool isWithSugar);
};

