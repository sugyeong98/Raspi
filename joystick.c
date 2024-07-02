#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

main()
{
	int x, y;
	float fx, fy;
	
	int dh = wiringPiI2CSetup(0x48);
	
	while(1)
	{
		wiringPiI2CWrite(dh, 0);
		wiringPiI2CRead(dh);
		x = wiringPiI2CRead(dh);
		fx = (float)((x/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(dh, 1);
		wiringPiI2CRead(dh);
		y = wiringPiI2CRead(dh);
		fy = (float)((y/255.0)*5.0);
		delay(100);
		
		
		printf("ADC input level = X %d Y %d (%4.1fV, %4.1fV)\n", x, y, fx, fy);
		delay(500);
		
	}
	
}
