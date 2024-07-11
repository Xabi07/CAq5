#include "mbed.h"
#include "string.h"
#include <cstdio>



//DigitalIn button(BUTTON1);    //works as a digital in, the interruptIn also works here
InterruptIn button(BUTTON1);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
volatile int myflag = 0;
volatile int counter = 0;

void buttonRise(){
    myflag = 1;
}

int main ()
{
    button.rise(&buttonRise);
	while (1){

        if (myflag == 1){ 
            counter +=1;
            printf("Button has been pressed %d times!\r\n", counter);
            myflag = 0;
        }
}
}
