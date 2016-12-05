#include "sys/alt_stdio.h"
#include "io.h"
#include "system.h"

class Display
{

public:
	Display();

	void clearDisplays();
	void clearLeds();
	void showDone();
	void showWait();

	void setLedRepor(int status);
	void setLedCopo(int status);
	void setLedCoffe(int status);
	void setLedCoffeMilk(int status);
	void setLedMocacchino(int status);
	void setLedSugar(int status);
	void setLedWaterLevel(int status);
	void setLedWaterTemp(int status);

	void refreshLeds();

private:
	int _ledRepor;
	int _ledCopo;
	int _ledCoffe;
	int _ledCoffeMilk;
	int _ledMocacchino;
	int _ledSugar;
	int _ledWaterLevel;
	int _ledWaterTemp;
	int _led_value;
};
