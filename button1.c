#include <stdio.h>
#include <wiringPi.h>

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
	
	
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(2, INPUT);
	
	int mode = 0;
	
	for(;;) //for(;;) = while(1)
	{
		
		if(mode)
		{
			Toggle(7);
			delay(200);
			Toggle(8);
			delay(200);
			Toggle(9);
			delay(200);
		}
		else
		{
			Toggle(9);
			delay(200);
			Toggle(8);
			delay(200);
			Toggle(7);
			delay(200);
		}
	
	
	int sw = digitalRead(2);
	
	if(sw == 0) //button pushed
		{
			mode = !mode;    //mode++
		}
	}
	return 0;
}
