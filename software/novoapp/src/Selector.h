#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

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
	bool isWithSugar();

};
