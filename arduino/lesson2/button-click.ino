int LED = 9;
int Button=2;
int BValue = 0;
int i = 0;

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(Button, INPUT);
    Serial.begin(9600);

}

void loop() {
    BValue = digitalRead(Button);
    Serial.print(BValue);
    if(BValue==HIGH) {
        i++;
        if(i == 2) {
            i = 0;
        }
    }
    if(i == 1) {
        digitalWrite(LED, HIGH);
      	delay(10);
    }
    else {
        digitalWrite(LED, LOW);
      	delay(10);
    }
}