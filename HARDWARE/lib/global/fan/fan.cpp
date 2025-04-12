#include "global.h"
void fanControl(AdafruitIO_Data *data){
    int fanSpeed = data->toInt();
    int pwmValue = map(fanSpeed, 0, 100, 0, 255);
    Serial.print("Fan speed: ");  
    Serial.println(fanSpeed);
    analogWrite(miniFanPin, pwmValue);
}

void fanAuto(AdafruitIO_Data *data){
    String autoStatus = data->toString();
    Serial.print("Auto Fan is ");  
    Serial.println(autoStatus);
    stateFan = autoStatus;
}