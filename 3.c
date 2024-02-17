#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partisi(int arr[], int low, int high) {
    int pivot = arr[high];  // Pilih pivot sebagai elemen terakhir
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Jika elemen saat ini lebih kecil atau sama dengan pivot, tukar dengan elemen di sebelah kiri pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Tukar elemen pivot dengan elemen di sebelah kanan pivot untuk memposisikan pivot di tempat yang benar
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Dapatkan posisi partisi yang benar
        int pivotIndex = partisi(arr, low, high);

        // Lakukan rekursi pada sub-array sebelah kiri dan kanan dari pivot
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan: ");
    printArray(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Array setelah diurutkan: ");
    printArray(arr, size);

    return 0;
}