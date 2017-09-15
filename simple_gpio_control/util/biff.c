#include "util.h"

void initBIFF(void)
{
	if(-1 == wiringPiSetupGpio())
		error_handling("beefGpio error");

	pinMode(BIFF_PIN,OUTPUT);
}

