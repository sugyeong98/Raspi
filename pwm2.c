#include <stdio.h>
#include <wiringPi.h>

#define wPi_22 22
//int wPi_22 = 22,,,?

int main(int n, char *s[])
{
	printf("Write pwm, period : \n");
	
	if(n<2)
	{
		printf("usage : pwm1[duty_rate(%%)]\n\n");
		return 1;
	}
	
	int dr, drh, drl, period;
	
	if(n==2)
	{
		period =10;
		sscanf(s[1], "%d", &dr);
		drh = (dr*period) /100;
		drl = period - drh;
	}
	
	else
	{
		sscanf(s[1], "%d", &dr);
		sscanf(s[2], "%d", &period);
		drh = (dr*period) /100;
		drl = period - drh;
	}
	
	int i;
	wiringPiSetup(); //wPi Pin numbering
	
	pinMode(wPi_22, OUTPUT);  //wiringOi 22 = GPIO06
	//pinMode(22, OUTPUT);..?
	
	for(i=0;i<100;i++)
	{
		digitalWrite(wPi_22,1);
		delay(drh);
		digitalWrite(wPi_22,0);
		delay(drl);	
		
	}
		
	return 0;
}	
	
