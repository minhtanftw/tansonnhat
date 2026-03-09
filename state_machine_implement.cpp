#include <iostream>

typedef enum State{
    RED,
    YELLOW,
    GREEN
}state;

int main () {
    while(1) {
        if (state == RED) {
            std::cout << "RED \n";
            state = GREEN;
        }else if (state == GREEN) {
            std::cout << " GREEN\n";
            state = YELLOW;
        }
        else if (state ==  YELLOW) {
            std::cout << "YELLOW";
            state = RED;
        }else if (state == GREEN) {
            std::cout << "GREEN";
            state = RED;
        }
    }
}