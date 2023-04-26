#include <LiquidCrystal.h>

const int rs=12, en=11, d4=4, d5=5, d6=6, d7=7;
const int sensor = A0;
const int temp_pin = A1;
const int led = 3;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int temp_value=0;
int sensor_state=0;

void setup() {
    lcd.begin(16,2);
    pinMode(led,OUTPUT);
    Serial.begin(9600);
    
}

void loop() {
    
    for (int i = 0; i < 12; i++)
    {   
        temp_value = analogRead(temp_pin);
        float mv = (5000/1023.0) * temp_value;
        int cel=(mv - 495)/10;
        Serial.print("Temperature: ");
        Serial.print(cel);
        Serial.println(" *C");
        lcd.clear();
        lcd.setCursor(i,0);
        lcd.print("Temperature");
        lcd.setCursor(i,1);
        lcd.print(cel);
        lcd.print(" *C");
        delay(200);
    }
    
}