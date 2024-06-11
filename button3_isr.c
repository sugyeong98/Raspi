#include <stdio.h>
#include <wiringPi.h>

#define RED 	7
#define GREEN 	8
#define YELLOW	9
# define SW		2


int mode = 0;
int intv = 2;	//2~9
int time;		//delay yime interval(MS)
	
int ps[40];			//pin state, pin number ; 40 // default 0(reset 0) 
void Toggle(int pin)
	{
	ps[pin] = !ps[pin];  // toggle
	digitalWrite(pin,ps[pin]);
	}

void gpioisr()
{
		//intv++;
		if (++intv>8) intv = 0;
		printf("GPIO interrupt occured...\n");
}
int main()
{
	wiringPiSetup();	// pin in / out(wPi) reset function
	//2pin in mode , 789pin out mode
	
	
	
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);		//registration GPIO ISR
	
	for(;;) //for(;;) = while(1)
	{
		time = (9-intv)*100;
		
		if(mode)                                 //mooode x --> only "else" working
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
	

	}
	return 0;
}
