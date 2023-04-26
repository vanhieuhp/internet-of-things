#include <Servo.h>

const unsigned int TRIG_PIN = 7;
const unsigned int ECHO_PIN = 8;
const unsigned int BAUD_RATE = 9600;
int red = 2;
int yellow = 3;
int green = 4;

int pos = 0;
int distanceThreshold = 0;
int cm = 0;
int inches = 0;
int flag = 0;
Servo servo_9;

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

    servo_9.attach(6);

    Serial.begin(BAUD_RATE);

}

void loop()
{   
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(20);

    const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    cm = duration/29/2;
    if(cm < 50) {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
    } else if(cm >= 50 && cm < 200) {
        digitalWrite(yellow, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
    } else{
        digitalWrite(green, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(red, LOW);
    }
    if(cm < 333 && flag == 0) {
        TT1();
    } else if(cm > 333 && flag == 1){
        TT2();
    }
    Serial.print(cm);
    Serial.println(" cm");
    // delay(10);

}

void TT1() {
    for(pos = 0; pos <= 180; pos +=1) {
        servo_9.write(pos);
        delay(15);
    }
    flag = 1;
}

void TT2() {
    for(pos = 180; pos > 0; pos -= 1) {
        servo_9.write(pos);
        delay(15);
    }
    flag = 0;
} 