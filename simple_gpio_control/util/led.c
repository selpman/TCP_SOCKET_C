#include "util.h"

void initLED(void)
{
	if( -1 == wiringPiSetupGpio())
		error_handling("setLED error");

	pinMode(RED_LED,OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED,OUTPUT);
}

void singleLedOn(int pin)
{
	digitalWrite(RED_LED,LOW);
	digitalWrite(YELLOW_LED,LOW);
	digitalWrite(GREEN_LED,LOW);

	digitalWrite(pin,HIGH);
}	
