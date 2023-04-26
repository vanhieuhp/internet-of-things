int VRPin = A0;
int ledPin = 9;
int VRValue = 0;
void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    VRValue = analogRead(VRPin);
    digitalWrite(ledPin, HIGH);
    delay(VRValue);
    digitalWrite(ledPin, LOW);
    delay(VRValue);
}