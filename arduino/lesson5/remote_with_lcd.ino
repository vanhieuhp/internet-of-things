#include <IRremote.h>
#include <LiquidCrystal.h>

const int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int cld_val = 0;

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    irrecv.enableIRIn();
    irrecv.blink13(true);
}

void loop()
{
    for (int i = 2; i < 10; i++)
    {
        if (irrecv.decode())
        {
            unsigned long Val = irrecv.decodedIRData.decodedRawData;
            Serial.println(Val); // Print "old" raw data
            cld_val = readNumber(Val, i);
            Serial.println(cld_val);
            lcd.clear();
            lcd.setCursor(i,0);
            lcd.print(cld_val);
            delay(200);
            irrecv.resume(); // Enable receiving of the next value
        }
    }
}

int readNumber(long input, int i)
{
    int number_print;
    switch (input)
    {
    case 4077698816:
        number_print = 0;
        break;
    case 4010852096:
        number_print = 1;
        break;
    case 3994140416:
        number_print = 2;
        break;
    case 3977428736:
        number_print = 3;
        break;
    case 3944005376:
        number_print = 4;
        break;
    case 3927293696:
        number_print = 5;
        break;
    case 3910582016:
        number_print = 6;
        break;
    case 3877158656:
        number_print = 7;
        break;
    case 3860446976:
        number_print = 8;
        break;
    case 3843735296:
        number_print = 9;
        break;
    default:
        number_print = -1;
        break;
    }
    return number_print;
    // lcd.clear();
    // lcd.setCursor(i, 0);
    // lcd.print(number_print);
    // digitalWrite(led, LOW);
    // delay(200);
}