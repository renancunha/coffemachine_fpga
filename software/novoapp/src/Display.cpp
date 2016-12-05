#include "Display.h"

Display::Display(){

	this->_ledCopo = 0;
	this->_ledRepor = 0;
	this->_ledCoffe = 0;
	this->_ledCoffeMilk = 0;
	this->_ledMocacchino = 0;
	this->_ledSugar = 0;
	this->_ledWaterLevel = 0;
	this->_ledWaterTemp = 0;
}

void Display::refreshLeds()
{
	int soma = 0;

	if(this->_ledCopo)
	{
		soma = soma + 1;
	}

	if(this->_ledRepor)
	{
		soma = soma +  2;
	}

	if(this->_ledCoffe)
	{
		soma = soma +  4;
	}

	if(this->_ledCoffeMilk)
	{
		soma = soma +  8;
	}

	if(this->_ledMocacchino)
	{
		soma = soma +  16;
	}

	if(this->_ledSugar)
	{
		soma = soma + 32;
	}

	if(this->_ledWaterLevel)
	{
		soma = soma +  64;
	}

	if(this->_ledWaterTemp)
	{
		soma = soma +  128;
	}

	IOWR(LED_BASE,0, soma);
}

void Display::setLedRepor(int status)
{
	this->_ledRepor = status;
	this->refreshLeds();
}

void Display::setLedCopo(int status)
{
	this->_ledCopo = status;
	this->refreshLeds();
}

void Display::setLedCoffe(int status)
{
	this->_ledCoffe = status;
	this->refreshLeds();
}

void Display::setLedCoffeMilk(int status)
{
	this->_ledCoffeMilk = status;
	this->refreshLeds();
}

void Display::setLedMocacchino(int status)
{
	this->_ledMocacchino = status;
	this->refreshLeds();
}

void Display::setLedSugar(int status)
{
	this->_ledSugar = status;
	this->refreshLeds();
}

void Display::setLedWaterLevel(int status)
{
	this->_ledWaterLevel = status;
	this->refreshLeds();
}

void Display::setLedWaterTemp(int status)
{
	this->_ledWaterTemp = status;
	this->refreshLeds();
}

void Display::clearDisplays()
{
	IOWR(HEX0_BASE,0,127);
	IOWR(HEX1_BASE,0,127);
	IOWR(HEX2_BASE,0,127);
	IOWR(HEX3_BASE,0,127);
}

void Display::showDone()
{
	IOWR(HEX0_BASE,0,6);		// 0000110 --> e
	IOWR(HEX1_BASE,0,43);	 	// 0101011 --> n
	IOWR(HEX2_BASE,0,35);  		// 0100011 --> o
	IOWR(HEX3_BASE,0,33);		// 0100001 --> d
}

void Display::showWait()
{
	IOWR(HEX0_BASE,0,78);  		// 1001110 --> t
	IOWR(HEX1_BASE,0,121); 		// 1111001 --> i
	IOWR(HEX2_BASE,0,8);   		// 0001000 --> a
	IOWR(HEX3_BASE,0,99);	 	// 1100011 --> w
}

void Display::clearLeds()
{
	this->setLedCoffe(0);
	this->setLedCoffeMilk(0);
	this->setLedCopo(0);
	this->setLedMocacchino(0);
	this->setLedRepor(0);
	this->setLedCoffe(0);
}
