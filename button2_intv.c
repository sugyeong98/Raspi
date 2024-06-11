#include <stdio.h>
#include <wiringPi.h>

#define RED 	7
#define GREEN 	8
#define YELLOW	9
# define SW		2

int ps[40];			//pin state, pin number ; 40 // default 0(reset 0) 
void Toggle(int pin)
	{
	ps[pin] = !ps[pin];  // toggle
	digitalWrite(pin,ps[pin]);
	}

int main()
{
	wiringPiSetup();	// pin in / out(wPi) reset function
	//2pin in mode , 789pin out mode
	int i;
	
	
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	
	int mode = 0;
	int intv = 2;	//2~9
	int time;		//delay yime interval(MS)
	
	for(;;) //for(;;) = while(1)
	{
		time = (9-intv)*100;
		
		if(mode)
		{
			Toggle(RED);
			delay(time);
			Toggle(GREEN);
			delay(time);
			Toggle(YELLOW);
			delay(time);
		}
		else
		{
			Toggle(YELLOW);
			delay(time);
			Toggle(GREEN);
			delay(time);
			Toggle(RED);
			delay(time);
		}
	
	
	int sw = digitalRead(SW);
	
	if(sw == 0) //button pushed
		{
			//mode = !mode;    //mode++
			intv++;
		}
	if(intv>8)
	{
		intv =1;
	}


	}
	return 0;
}
