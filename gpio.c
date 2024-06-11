#include <stdio.h>
#include <wiringPi.h>

int main()
{
	wiringPiSetup();	// pin in / out(wPi) 
	//2pin in mode , 789pin out mode
	int i;
	
	while(1)
	{
	
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	delay(1000);
	pinMode(2, INPUT);
	
	for(i=7;i<=9;i++)
	{
		digitalWrite(i, HIGH);
		delay(1000);
		digitalWrite(i, LOW);
		delay(1000);
	}
	}

	
}
