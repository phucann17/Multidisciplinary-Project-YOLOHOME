#include "global.h"
void setupLCD(){
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("TEST LCD");
}

void updateData() {
    // status = DHT.read();
    temperature = random(10, 99);//DHT.getTemperature();
    humidity = random(10, 99);//DHT.getHumidity();
    light = random(10, 99);//analogRead(sensorPin);

    lcd.setCursor(0, 0);
    lcd.print("RT:");
    lcd.setCursor(3, 0);
    lcd.print((int)temperature);
    lcd.print("*C ");
    lcd.setCursor(8, 0);
    lcd.print("RH:");
    lcd.print((int)humidity);
    lcd.print("%");
    // lcd.setCursor(11, 0);
    // lcd.print(humidity);
    lcd.setCursor(0, 1);
    lcd.print("LUX:");
    lcd.setCursor(4, 1);
    lcd.print(light);
    lcd.print("%");
}
 