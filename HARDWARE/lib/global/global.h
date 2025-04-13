#include <WiFi.h>
#include "pins_arduino.h"
#include <string.h>
#include "AdafruitIO_WiFi.h"
#include <Adafruit_NeoPixel.h>
#include <DHT20.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Arduino.h>
#include <Ticker.h>

extern int miniFanPin;
extern String stateFan;
void fanControl(AdafruitIO_Data *data);
void fanAuto(AdafruitIO_Data *data);

extern int relayPin;
void relayControl(AdafruitIO_Data *data);

extern int timer_flag1;
extern int timer_flag2;
extern Ticker myTimer;
void timerRun();
void setTimer1(int duration);
void setTimer2(int duration);

extern Servo myservo;
extern String password;
extern int servoPin;
extern String stateDoor;
void servoControl(AdafruitIO_Data *data);
void setupServo(int pin);
void servoAuto(AdafruitIO_Data *data);


extern int receiverPin;
extern int speed;
extern String color;
extern String passwordAda;
void controlRemote();
void setupRemote();
void passAuthorized(AdafruitIO_Data *data);


extern int PIN_NEO_PIXEL;
extern int NUM_PIXELS;
extern int pirPin;
extern String stateRGB;
extern unsigned long offTime;
extern Adafruit_NeoPixel NeoPixel;
extern bool check;
void rgbControl(AdafruitIO_Data *data);
void rgbAuto(AdafruitIO_Data *data);
void autoLed();
void timerControl(AdafruitIO_Data *data);
void turnoffLed();

extern DHT20 DHT;
extern int sensorPin;
extern LiquidCrystal_I2C lcd;
extern int status;
extern float temperature;
extern float humidity;
extern float light;
void setupLCD();
void updateData();

void fsm();
extern int timeoutRGB;
extern int timeoutDoor;
extern int timeoutFan;

