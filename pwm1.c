#include <stdio.h>
#include <wiringPi.h>

#define wPi_22 22
//int wPi_22 = 22,,,?

int main(int n, char *s[])
{
	if(n<2)
	{
		printf("usage : pwm1[duty_rate(%%)]\n\n");
		return 1;
	}
	
	int dr, drh, drl, period =10;
	sscanf(s[1], "%d", &dr);
	drh = (dr*period) /100;
	drl = period - drh;
	
	int i;
	wiringPiSetup(); //wPi Pin numbering
	
	pinMode(wPi_22, OUTPUT);  //wiringOi 22 = GPIO06
	//pinMode(22, OUTPUT);..?
	
	for(i=0;i<500;i++)
	{
		digitalWrite(wPi_22,1);
		delay(drh);
		digitalWrite(wPi_22,0);
		delay(drl);	
		
	}
		
	return 0;
}	
	
