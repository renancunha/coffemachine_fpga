#include "sys/alt_stdio.h"
#include "system.h"
#include "io.h"
#include "Defs.h"

class Selector
{

public:
	Selector();

	bool isPrepararPressed();
	bool isReporPressed();

	coffeTypes getSelectedCoffe();
	int getCupSize();
	bool isWithSugar();

};
