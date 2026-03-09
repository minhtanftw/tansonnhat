#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)calloc(5, sizeof(int) );
    if (ptr == NULL) {
        printf("Allocation failed");
        exit(0);
    }

   
    for (int i = 0; i < 5; i++) {
        printf(" %d",ptr[i]);
    }

}