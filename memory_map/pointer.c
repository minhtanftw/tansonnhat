#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};  // khai báo mảng
    int *ptr = arr;                // con trỏ trỏ đến mảng

    printf("%d\n", *ptr);      // phần tử đầu tiên
    printf("%d\n", *(ptr+1));  // phần tử thứ 2
    printf(" %d \n", *(ptr-1));
}