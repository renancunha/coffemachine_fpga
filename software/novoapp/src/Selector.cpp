#include "Selector.h"

Selector::Selector(){

}

bool Selector::isPrepararPressed()
{
	return IORD(PREPARAR_BASE,0) == 0;
}

bool Selector::isReporPressed()
{
	return IORD(REPOR_BASE,0) == 0;
}

coffeTypes Selector::getSelectedCoffe()
{
	int valor_lido = IORD(SWITCH_BASE,0);

	if(CHECK_BIT(valor_lido, 0))
	{
		return T_COFFE;
	}
	else if(CHECK_BIT(valor_lido, 1))
	{
		return T_COFFEMILK;
	}
	else if(CHECK_BIT(valor_lido, 2))
	{
		return T_MOCACCHINO;
	}

	return T_NONE;
}

bool Selector::isWithSugar()
{
	int valor_lido = IORD(SWITCH_BASE,0);

	if(CHECK_BIT(valor_lido, 3))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Selector::getCupSize()
{
	int valor_lido = IORD(SWITCH_BASE,0);
	return CHECK_BIT(valor_lido, 4);
}
