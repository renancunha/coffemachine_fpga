#include "WaterReservoir.h"


WaterReservoir::WaterReservoir(){

}

int WaterReservoir::getLevel()
{
	int valor_lido = IORD(SWITCH_BASE,0);
	return CHECK_BIT(valor_lido, 5);
}

int WaterReservoir::getTemp()
{
	int valor_lido = IORD(SWITCH_BASE,0);
	return CHECK_BIT(valor_lido, 6);
}
