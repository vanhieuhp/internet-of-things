int LED = 9;
int Button=2;
int BValue = 0;
void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(Button, INPUT);

}

void loop() {
    BValue = digitalRead(Button);
    if(BValue==HIGH) {
        digitalWrite(LED, HIGH);
        delay(10);
    }
    else {
        digitalWrite(LED, LOW);
        delay(10);
    }
}