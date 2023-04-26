#include <LiquidCrystal.h>

const int rs=12, en=11, d4=4, d5=5, d6=6, d7=7;
const int sensor = A0;
int sensor_state=0;
const int led = 3;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
    lcd.begin(16,2);
    pinMode(led,OUTPUT);
}

void loop() {
    for (int i = 2; i < 8; i++)
    {
        sensor_state = analogRead(sensor);
        if (sensor_state < 500)
        {
            lcd.clear();
            lcd.setCursor(i,0);
            lcd.print(sensor_state);
            lcd.setCursor(i,1);
            lcd.print("Troi sang");
            digitalWrite(led, LOW);
            delay(200);
        } else {
            lcd.clear();
            lcd.setCursor(i,0);
            lcd.print(sensor_state);
            lcd.setCursor(i,1);
            lcd.print("Troi Toi");
            digitalWrite(led, HIGH);
            delay(200);
        }
        
    }
    
}