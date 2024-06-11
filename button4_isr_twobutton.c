#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <signal.h>

#define RED 	7
#define GREEN 	8
#define YELLOW	9
#define SW		2
#define OW		1

int mode = 0;
int intv = 2;	//2~9
int time;		//delay yime interval(MS)
int stop = 1;

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

void stopisr()
{
		digitalWrite(RED,0);
		digitalWrite(GREEN,0);
		digitalWrite(YELLOW,0);
		printf("STOP...\n");
		stop = 0;
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
	wiringPiISR(OW, INT_EDGE_FALLING, stopisr);
	
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
		
		if(stop == 0)
		{
			break;	
		}
		
	}
	return 0;
}
