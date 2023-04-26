const int analogInPin = A0;
const int LED = 9;
int lightValue = 0;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    
    lightValue = analogRead(analogInPin);
    if(lightValue < 300) {
        digitalWrite(LED,HIGH);
	    delay(500);
    } else {
        digitalWrite(LED,LOW);  
	    delay(500);
    }
}