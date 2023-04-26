#include <IRremote.h>
const int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int red = 2, blue = 3;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(true);
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    if(irrecv.decode()) {
        unsigned long Val = irrecv.decodedIRData.decodedRawData;
        Serial.println(Val); //Print "old" raw data
        if(Val == 4010852096) {
            digitalWrite(red, HIGH);
            digitalWrite(blue, LOW);
        } else if (Val == 3994140416) {
            digitalWrite(red, LOW);
            digitalWrite(blue, HIGH);
        } else if (Val == 4077698816){
            digitalWrite(red, HIGH);
            digitalWrite(blue, HIGH);
        } else {
            digitalWrite(red, LOW);
            digitalWrite(blue, LOW);
        }
        delay(200);
        irrecv.resume(); // Enable receiving of the next value
    }
}

// 4077698816
// 4010852096
// 3994140416
// 3977428736
// 3944005376
// 3927293696
// 3910582016
// 3877158656
// 3860446976
// 3843735296