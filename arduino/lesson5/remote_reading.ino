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
        readNumber(Val);
        delay(200);
        irrecv.resume(); // Enable receiving of the next value
    }
}
void readNumber(long input) {
    switch (input) {
    case 4077698816:
        Serial.println("SO 0");
        break;
    case 4010852096: 
        Serial.println("SO 1");
        break;
    case 3994140416:
        Serial.println("SO 2");
        break;
    case 3977428736:
        Serial.println("SO 3");
        break;
    case 3944005376:
        Serial.println("SO 4");
        break;
    case 3927293696:
        Serial.println("SO 5");
        break;
    case 3910582016:
        Serial.println("SO 6");
        break;
    case 3877158656:
        Serial.println("SO 7");
        break;
    case 3860446976:
        Serial.println("SO 8");
        break;
    case 3843735296:
        Serial.println("SO 9");
        break;
    default: 
        Serial.println("SO Khac");
        break;
    }
}
// 
// 
// 
// 
// 
// 