#include <reg.51.h>
void delay() (void);
void main() (void);
{
    while(1){
        LED = 1;
        delay();
        LED = 0;
        delay();
    }
}


void main() {
    unsigned char a,b,c;
    P1= 0xFF;
    P2= 0XFF;
    a = P1;
    b = P2;
    c =  a +b;
    P3 =c;
}

