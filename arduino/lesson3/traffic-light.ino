#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7

#define red1 8
#define yellow1 9
#define green1 10

#define red2 11
#define yellow2 12
#define green2 13

int flag = 1;
void setup()
{
    for (int i = 1; i < 14; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{   
    for (int i = 0; i < 10; i++)
    {
        switch (i)
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
        traffic1(i, flag);
        traffic2(i, flag);
        delay(500);
    }
    flag ++;
    if(flag == 3) {
        flag = 1;
    }
}


void traffic1(int i, int flag) {
    if(flag == 2) {
        digitalWrite(red1, HIGH);
        digitalWrite(yellow1, LOW);
        digitalWrite(green1, LOW);
    } else {
        if(i >= 0 && i < 9) {
            digitalWrite(red1, LOW);
            digitalWrite(yellow1, LOW);
            digitalWrite(green1, HIGH);
        } else if( i == 9) {
            digitalWrite(red1, LOW);
            digitalWrite(yellow1, HIGH);
            digitalWrite(green1, LOW);
        }
    }
   
}


void traffic2(int i, int flag) {
    if(flag == 1) {
        digitalWrite(red2, HIGH);
        digitalWrite(yellow2, LOW);
        digitalWrite(green2, LOW);
    } else {
        if(i >= 0 && i < 9) {
            digitalWrite(red2, LOW);
            digitalWrite(yellow2, LOW);
            digitalWrite(green2, HIGH);
        } else if( i == 9) {
            digitalWrite(red2, LOW);
            digitalWrite(yellow2, HIGH);
            digitalWrite(green2, LOW);
        }
    }
   
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
