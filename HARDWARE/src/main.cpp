#include <WiFi.h>
#include "pins_arduino.h"
#include <timer.h>
#include <sensor.h>
#include <remote.hpp>
#include <string.h>
#include <relay.h>
#include <fan.h>
#include <rgb.h>
//#include <IRremote.hpp>
// Thông tin WiFi
const char* WIFI_SSID = "";
const char* WIFI_PASS = "";

// Thông tin Adafruit IO
#define AIO_USERNAME    ""
#define AIO_KEY         ""
// Khởi tạo Adafruit IO
AdafruitIO_WiFi io(AIO_USERNAME, AIO_KEY, WIFI_SSID, WIFI_PASS);
AdafruitIO_Feed *temperatureFeed = io.feed("DHT20_TEMPERATURE");
AdafruitIO_Feed *humidityFeed = io.feed("DHT20_HUMIDITY");
AdafruitIO_Feed *lightFeed = io.feed("LIGHT_SENSOR");
AdafruitIO_Feed *relayFeed = io.feed("RELAY");
AdafruitIO_Feed *servoFeed = io.feed("SERVO_DOOR");
AdafruitIO_Feed *rgbFeed = io.feed("LED_RGB");
AdafruitIO_Feed *fanFeed = io.feed("MINI_FAN");
AdafruitIO_Feed *remoteFeedfan = io.feed("MINI_FAN");
AdafruitIO_Feed *autorgb = io.feed("LED_RGB_AUTO");
AdafruitIO_Feed *remoteFeedrgb = io.feed("LED_RGB");
AdafruitIO_Feed *passwordFeed = io.feed("PASSWORD");
AdafruitIO_Feed *timer_off = io.feed("TIME_OFF");

void timerCallback() {
    timerRun();
}

void sendData(){
    updateData();
    Serial.print("Sending light: ");
    Serial.println(light * 100 / 4095);
    lightFeed->save(light * 100 / 4095);

    Serial.print("Sending temperature: ");
    Serial.println(temperature);
    temperatureFeed->save(temperature);

    Serial.print("Sending humidity: ");
    Serial.println(humidity);
    humidityFeed->save(humidity);
}


void feedSetup(){
    io.connect();
    servoFeed->onMessage(servoControl);
    servoFeed->get();
    relayFeed->onMessage(relayControl);
    relayFeed->get();
    fanFeed->get();
    fanFeed->onMessage(fanControl);
    rgbFeed->get();
    rgbFeed->onMessage(rgbControl);
    autorgb->get();
    autorgb->onMessage(rgbAuto);
    passwordFeed->get();
    passwordFeed->onMessage(passAuthorized);
    timer_off->get();
    timer_off->onMessage(timerControl);
}


void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    pinMode(relayPin, OUTPUT);
    pinMode(miniFanPin, OUTPUT);
    pinMode(pirPin, INPUT);
    Wire.begin();
    Wire1.begin(P20, P19);
        //  ESP32 default pins 21 22
    setupRemote();
    Serial.println("IR Receiver Ready...");
    feedSetup();
    setupLCD();

    setupServo(servoPin);
    myservo.write(180);

    NeoPixel.begin();

    sendData();
    myTimer.attach(1.0, timerCallback);
    // setTimer(1, false, &dataTimer1, 6000, timerRun2);
    setTimer1(30);
}


void loop() {
    io.run();
    if (timer_flag1 == 1) {
        sendData();
        setTimer1(30);
    }
    if (timer_flag2 == 1) {
        turnoffLed();
        timer_flag2 = 0;
    }

    autoLed();
    controlRemote();
    //Serial.println(digitalRead(pirPin));
}
