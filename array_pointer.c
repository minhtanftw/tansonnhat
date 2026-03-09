#include <stdio.h>

void add(int a, int b) {
    printf("SUm of a and b  \t \n: %d",a +b);
}

void subtract (int a, int b) {
    printf("Subtract a and b  \t \n: %d", a -b);
}

void multiply(int a, int b) {
    printf("Subtract a and b: \t \n %d", a- b);

}

void divide (int a,int b) {
    printf("quotient :%d \t \n", a /b);
}

int main(){
    int  x = 50,  y =5;

    void (*arr[4]) (int, int) = { &add,&subtract, &multiply, &divide};
    for (int i =0; i <4; i++){
        arr[i](x,y);
    }

    return 0;
}