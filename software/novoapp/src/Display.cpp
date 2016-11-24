#include "Display.h"

Display::Display(){

	this->_ledCopo = 0;
	this->_ledRepor = 0;
	this->_ledCoffe = 0;
	this->_ledCoffeMilk = 0;
	this->_ledMocacchino = 0;
	this->_ledSugar = 0;
}

void Display::refreshLeds()
{

	if(this->_ledCopo)
	{
		this->_led_value += 1;
	}

	if(this->_ledRepor)
	{
		this->_led_value += 2;
	}

	if(this->_ledCoffe)
	{
		this->_led_value += 4;
	}

	if(this->_ledCoffeMilk)
	{
		this->_led_value += 8;
	}

	if(this->_ledMocacchino)
	{
		this->_led_value += 16;
	}

	if(this->_ledSugar)
	{
		this->_led_value += 32;
	}

	IOWR(LED_BASE,0, this->_led_value);
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