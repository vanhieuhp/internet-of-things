const unsigned int TRIG_PIN = 7;
const unsigned int ECHO_PIN = 8;
const unsigned int BAUD_RATE = 9600;

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(BAUD_RATE);
}

void loop()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(20);

    const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration/29/2;
    if(duration==0) {
        Serial.println("Warnin: no pulse from sensor");

    } else {
        Serial.print("Distance to nearest object:");
        Serial.print(distance);
        Serial.println(" cm");
    }
    delay(100);
}