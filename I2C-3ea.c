#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

main()
{
	int v1, v2, v3;
	float f1, f2, f3;
	
	int dh = wiringPiI2CSetup(0x48);
	
	while(1)
	{
		wiringPiI2CWrite(dh, 0);
		wiringPiI2CRead(dh);
		v1 = wiringPiI2CRead(dh);
		f1 = (float)((v1/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(dh, 1);
		wiringPiI2CRead(dh);
		v2 = wiringPiI2CRead(dh);
		f2 = (float)((v2/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(dh, 3);
		wiringPiI2CRead(dh);
		v3 = wiringPiI2CRead(dh);
		f3 = (float)((v3/255.0)*5.0);
		delay(100);
		
		printf("ADC input level = %d %d %d (%4.1fV, %4.1f, %4.1f)\n", v1, v2, v3, f1, f2, f3);
		delay(500);
		
	}
	
}
