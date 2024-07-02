#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 22

int main(int n, char *s[])
{
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
		drh = (dr*period) /100;    //mark time
		drl = period - drh;       //space time
	}
	
	
	wiringPiSetup();
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);
	softPwmCreate(wPi_Pin,drh, period);		//create thread 																										
	//softPwmWrite(wPi_Pin,7);
	
	delay(5000);
	softPwmStop(wPi_Pin);

	return 0;
}
