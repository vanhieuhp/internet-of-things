const int temp_pin = A0;
int temp_value=0;
const int red = 4, yellow = 2, green = 3;

void setup() {
    pinMode(red,OUTPUT);
    pinMode(yellow,OUTPUT);
    pinMode(green,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    temp_value = analogRead(temp_pin);
    float mv = (5000/1023.0) * temp_value;
    int cel=(mv - 495)/10;
    Serial.print("Temperature: ");
    Serial.print(cel);
    Serial.println(" *C");

    if(cel < 0) {
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, HIGH);
    } else if(cel < 50 && cel > 0) {
        digitalWrite(red, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(green, LOW);
    } else {
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);
    }
    delay(1000);
}