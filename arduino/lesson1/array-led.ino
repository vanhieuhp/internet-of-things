int timer = 100;
void setup() {
    for (int thisPin = 3; thisPin < 10; thisPin++)
    {
        pinMode(thisPin, OUTPUT);
    }
    
}

void tt1() {
    for (int thisPin = 3; thisPin < 10; thisPin++)
    {
        digitalWrite(thisPin, HIGH);
        delay(timer);
        digitalWrite(thisPin, LOW);
    }
}

void tt2() {
    for (int thisPin = 9; thisPin > 2; thisPin--)
    {
        digitalWrite(thisPin, HIGH);
        delay(timer);
        digitalWrite(thisPin, LOW);
    }
}

void loop() {
    tt1();
    tt2();
}
