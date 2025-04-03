#include <timer.h>
#include <stdint.h>
int counter1 = 0;
int counter2 = 0;
int timer_flag1 = 0;
int timer_flag2 = 0;
Ticker myTimer;
void setTimer1(int duration){
    counter1 = duration;
    timer_flag1 = 0;
}

void setTimer2(int duration){
    counter2 = duration;
    timer_flag2 = 0;
}

void timerRun(){
    if (counter1 > 0){
        counter1--;
        if (counter1 <= 0) timer_flag1 = 1;
    }

    if (counter2 > 0){
        counter2--;
        if (counter2 <= 0) timer_flag2 = 1;
    }
}