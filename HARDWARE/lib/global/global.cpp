#include "global.h"

int miniFanPin = P10;
String stateFan = "";

int timer_flag1 = 0;
int timer_flag2 = 0;
Ticker myTimer;

Servo myservo;
String password = "";
int servoPin = P4;
String stateDoor = "";

int relayPin = P14;

int receiverPin = P1;
int speed = 0;
String color = "";
String passwordAda = "";

int PIN_NEO_PIXEL = P0;
int NUM_PIXELS  =   4;
int pirPin = P16;
bool check = false;
unsigned long offTime = 0;
String stateRGB = "";
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

DHT20 DHT(&Wire1);
int sensorPin = P2_ADC;
LiquidCrystal_I2C lcd(0x21, 16, 2);
// int status = DHT.read();
float temperature = random(10, 99);//DHT.getTemperature();
float humidity = random(10, 99);//DHT.getHumidity();
float light = random(10, 99);//analogRead(sensorPin) * 100 / 4095;

int timeoutRGB = 1000;
int timeoutDoor = 1000;
int timeoutFan = 1000;