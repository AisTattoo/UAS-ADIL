#include <stdio.h>

#define MAX_SIZE 9

void mencariTigaTerbesar(int arr[MAX_SIZE], int* terbesar1, int* terbesar2, int* terbesar3) {
    *terbesar1 = *terbesar2 = *terbesar3 = -9999999;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (arr[i] > *terbesar1) {
            *terbesar3 = *terbesar2;
            *terbesar2 = *terbesar1;
            *terbesar1 = arr[i];
        } else if (arr[i] > *terbesar2 && arr[i] <= *terbesar1) {
            *terbesar3 = *terbesar2;
            *terbesar2= arr[i];
        } else if (arr[i] > *terbesar3 && arr[i] <= *terbesar2) {
            *terbesar3 = arr[i];
        }
    }
}

int main() {
   
    int arr[MAX_SIZE] = {12, 45, 9, 67, 23, 56, 31, 78, 90}; //saya tidak menggunakan sizeof karena dalam soal array harus ada nilainya. makadari itu saya memakai define MAX_SIZE
    int terbesar1, terbesar2, terbesar3;

    mencariTigaTerbesar(arr, &terbesar1, &terbesar2, &terbesar3);

    printf("Tiga elemen terbesar adalah: %d, %d, %d\n", terbesar1, terbesar2, terbesar3);

    return 0;
}