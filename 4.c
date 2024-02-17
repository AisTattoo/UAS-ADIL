#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i;
    int sum = 0;
    float average;
    int middle;

    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    printf("Masukkan nilai data:\n");
    for (i = 0; i < n; i++) {
        printf("Data nilai ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / n;

    // Mengurutkan array menggunakan algoritma bubble sort
    for (int pass = 0; pass < n - 1; pass++) {
        for (i = 0; i < n - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    if (n % 2 == 0) {
        middle = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        middle = arr[n / 2];
    }

    printf("Jumlah data: %d\n", sum);
    printf("Rata-rata: %.2f\n", average);
    printf("Nilai tengah: %d\n", middle);

    return 0;
}