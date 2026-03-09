#include <stdio.h>


typedef union direction{
    int x;
    char a,b,c,d,e,f,g;
    //char arr[40];
}abc;
int main() {
    int x = 20;
    int *ptr = &x;
    printf("%d \n", *ptr);
    printf("%u \n", ptr);

    int y = 13;
    //Clear bit
    printf("Clear Ans: %d\n", y & ~(1 << 3));

    //CHecking bit
    printf("Check Ans %d \n", 13 &( 1 <<3));
    //Set bit
    printf("set Ans: %d \n", 13 & ~( 1 << 4));
    //Flip bit
    printf("Flip bit %d \n", 13 ^ (1<<4));

    return 0;
}
