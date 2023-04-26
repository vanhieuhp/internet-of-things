#include <Servo.h>

#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define btnIn 8
#define btnOut 9
Servo servo;

int count = 0;
int inValue = 0;
int outValue = 0;

void setup()
{
    for (int i = 1; i < 8; i++)
    {
        pinMode(i, OUTPUT);
    }
    pinMode(btnIn, INPUT);
    pinMode(btnOut, INPUT);

    servo.attach(10);
}

void loop()
{
    inValue = digitalRead(btnIn);
    outValue = digitalRead(btnOut);
    if (inValue == HIGH)
    {
        count ++;
        if (count == 6)
        {
            count --;
        } else {
            // count ++;
            openServo(count);
        }
    }

    if (outValue == HIGH)
    {   
        count --;
        if (count == -1)
        {
            count ++;
        }
        else
        {
            // count -= 1;
            openServo(count);
        }
    }

    switch (count)
    {
    case 1:
        so1();
        break;
    case 2:
        so2();
        break;
    case 3:
        so3();
        break;
    case 4:
        so4();
        break;
    case 5:
        so5();
        break;
    case 6:
        so6();
        break;
    case 7:
        so7();
        break;
    case 8:
        so8();
        break;
    case 9:
        so9();
        break;
    default:
        so0();
    }
    delay(200);
}

void so0()
{
    // #SO 0
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
}

void so1()
{
    // #SO 1
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}

void so2()
{
    // #SO 2
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
}

void so3()
{
    // #SO 3
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
}

void so4()
{
    // #SO 4
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}
void so5()
{
    // #SO 5
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}
void so6()
{
    // #SO 6
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}
void so7()
{
    // #SO 7
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}
void so8()
{
    // #SO 8
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}
void so9()
{
    // #SO 9
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

void openServo(int i)
{
    if (i < 6 && i > -1)
    {
        for (int pos = 0; pos <= 180; pos += 10)
        {
            servo.write(pos);
            delay(15);
        }
        for (int pos = 180; pos > 0; pos -= 10)
        {
            servo.write(pos);
            delay(15);
        }
    }
}