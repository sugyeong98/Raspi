#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

main()
{
	int dh = wiringPiI2CSetup(0x48);
	wiringPiI2CWrite(dh, 3); //ch03 (VR)
	//wiringPiI2CWrite(dh, 0); //ch01 
	//wiringPiI2CWrite(dh, 1); //ch02
	
	while(1)
	{
		int val = wiringPiI2CRead(dh);
		//printf("VR input level = %d", val);
		//delay(500);
		
		float f = (float)((val/255.0)*5.0);
		printf("VR input level = %d (%4.1fV)\n", val, f);
		delay(500);
		
	}
	
}
