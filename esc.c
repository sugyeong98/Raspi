#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>


int main()
{
	printf("\033[2J");   //clear screen
	int fd = wiringPiI2CSetup(0x48);
	//int x=10, y=20;
	
	while(1)
	{
		wiringPiI2CWrite(fd,00);
		wiringPiI2CRead(fd);
		//int x = wiringPiI2CRead(fd);
		int x = (wiringPiI2CRead(fd)*80)/255;
		delay(100);
		
		wiringPiI2CWrite(fd,01);
		wiringPiI2CRead(fd);
		//int y = wiringPiI2CRead(fd);
		int y = (wiringPiI2CRead(fd)*24)/255;
		delay(100);
		
		//int fx=(float)(x/255)*80.0;
		//int fy=(float)(y/255)*24.0;
	    //int fx=(x*80)/255;
		//int fy=((y*24)/255);
		
		//printf("(%d, %d)", x,y);
		//printf("\033[%d;%dH", x, y);
		printf("\033[%d;%dH(%d, %d)\n", y, x, x, y);
		delay(200);
	
	//printf("\033[2J"); ///escape sequence(\033) ->clear[2J;
	//printf("\033[%d;%dH", fx, fy); ///escape sequence -> move[x;yH;
	
	}
	
	return 0;
}
