#include <stdio.h>
#include<string.h>

struct Person{
    char name[50];
    int age;
    float height;
};

int main(){
    struct Person Persona_1;
    strcpy(Persona_1.name, "Nguyen Minh Tan");
    Persona_1.age = 29;
    Persona_1.height = 1.78;
    printf("Name: %s, Age: %d, Height: %.2f \n", Persona_1.name, Persona_1.age, Persona_1.height);
    return 0;
}