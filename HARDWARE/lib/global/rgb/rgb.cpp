#include <global.h>
void rgbControl(AdafruitIO_Data *data) {
    String receivedData = data->toString();
    Serial.print("Received RGB Data: ");
    Serial.println(receivedData);

    if (receivedData == "#000000"){
        NeoPixel.clear();
        NeoPixel.show();
    }
    else if (receivedData == "#ff0000"){ //red
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) { //RED
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 0, 0));
            NeoPixel.show();
        }
        NeoPixel.show();
    }
    else if (receivedData == "#008000"){ // Green
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 0));
            NeoPixel.show();
        }
        NeoPixel.show();
    }
    else if (receivedData == "#0000ff"){ //Blue
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 0, 255));
            NeoPixel.show();
        }
        NeoPixel.show();
    }
    else if (receivedData == "#ffffff"){ //White (digitalRead(pirPin) == 1 && analogRead(sensorPin) > 65)  || 
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255));
            NeoPixel.show();
        }
        NeoPixel.show();
    }
    else if (receivedData == "#ffff00") {  // Yelloư
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 0));
        }
        NeoPixel.show();
    }
    else if (receivedData == "#ffa500") {  // Orange
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 165, 0));
        }
        NeoPixel.show();
    }
    else if (receivedData == "#800080") {  // purple
        NeoPixel.clear();
        for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
            NeoPixel.setPixelColor(pixel, NeoPixel.Color(128, 0, 128)); // Tím = (128, 0, 128)
        }
        NeoPixel.show();
    }  
}

void rgbAuto(AdafruitIO_Data *data){
    String autoStatus = data->toString();
    Serial.print("Auto is ");  
    Serial.println(autoStatus);
    stateRGB = autoStatus;
}

void autoLed(){
    if (stateRGB == "1"){
        light = analogRead(sensorPin) * 100 / 4095;
        if (digitalRead(pirPin) && light < 30){
            for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
                NeoPixel.setPixelColor(pixel, NeoPixel.Color(255, 255, 255));
            }
            NeoPixel.show();
        }
        else{
            NeoPixel.clear();
            NeoPixel.show();
        }
    }
    else;
}

void timerControl(AdafruitIO_Data *data) {
    String timeStr = data->toString();
    Serial.print("Received timer off: ");
    Serial.println(timeStr);
    if (timeStr != NULL && timeStr != "00:00"){
        check = 1;
        int hour = timeStr.substring(0, timeStr.indexOf(':')).toInt();
        int minute = timeStr.substring(timeStr.indexOf(':') + 1).toInt();
        unsigned long targetSeconds = (hour * 3600) + (minute * 60);
        offTime = targetSeconds;
        Serial.print("Received seconds off: ");
        Serial.println(offTime);
        setTimer2(offTime);
    }
}

void turnoffLed(){
    NeoPixel.clear();
    NeoPixel.show();
    //Serial.println("OFF");
    //Serial.println("OFF");
}