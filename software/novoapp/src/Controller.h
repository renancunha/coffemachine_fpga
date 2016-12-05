#include "sys/alt_stdio.h"
#include "io.h"
#include "system.h"
#include "unistd.h"

#include "Defs.h"
#include "reservoirs/CoffeReservoir.h"
#include "reservoirs/MilkReservoir.h"
#include "reservoirs/ChocolateReservoir.h"
#include "reservoirs/SugarReservoir.h"
#include "reservoirs/WaterReservoir.h"

class Controller
{

public:
	Controller();

	CoffeReservoir coffeReservoir;
	MilkReservoir milkReservoir;
	ChocolateReservoir chocolateReservoir;
	SugarReservoir sugarReservoir;
	WaterReservoir waterReservoir;

	bool needToResupply(coffeTypes coffeType, bool isWithSugar);
	void refill(coffeTypes coffeType, bool isWithSugar);
	void make(coffeTypes coffeType, bool isWithSugar, bool cupSize);

	int getWaterLevel();
	int getWaterTemp();
};

