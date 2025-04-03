#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <Ticker.h>
extern int timer_flag1;
extern int timer_flag2;
extern Ticker myTimer;
void timerRun();
void setTimer1(int duration);
void setTimer2(int duration);


#endif