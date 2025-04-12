#include "global.h"
void servoControl(AdafruitIO_Data *data){
    String servoStatus = data->toString();
    Serial.print("Servo is ");  
    Serial.println(servoStatus);
    myservo.write(servoStatus == "1" ? 90 : 180);
}
void setupServo(int pin){
    myservo.attach(pin);
    myservo.write(180);
}

void servoAuto(AdafruitIO_Data *data){
    String autoStatus = data->toString();
    Serial.print("Auto Door is ");  
    Serial.println(autoStatus);
    stateDoor = autoStatus;
}