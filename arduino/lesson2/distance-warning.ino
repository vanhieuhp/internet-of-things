const unsigned int TRIG_PIN = 7;
const unsigned int ECHO_PIN = 8;
const unsigned int BAUD_RATE = 9600;
int red = 2;
int yellow = 3;
int green = 4;

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(BAUD_RATE);

    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

}

void loop()
{   
    digitalWrite(TRIG_PIN, LOW);
    // delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    // delayMicroseconds(20);

    const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration/29/2;
    Serial.print(distance);
    Serial.println("cm");
    if(distance < 50) {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
    } else if(distance >= 50 && distance < 200) {
        digitalWrite(yellow, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
    } else{
        digitalWrite(green, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(red, LOW);
    }
    // delay(10);
}