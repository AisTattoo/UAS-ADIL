#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Jika elemen tengah sama dengan target, maka kembalikan posisinya
        if (arr[mid] == target) {
            return mid;
        }
        
        // Jika elemen tengah lebih kecil dari target, cari di sebelah kanan
        if (arr[mid] < target) {
            low = mid + 1;
        }
        
        // Jika elemen tengah lebih besar dari target, cari di sebelah kiri
        else {
            high = mid - 1;
        }
    }
    
    // Jika tidak ditemukan, kembalikan -1
    return -1;
}

int main() {
    int n, i, target;

    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &n);

    int arr[n];

    printf("Masukkan data nilai mahasiswa (urutkan dari terkecil ke terbesar):\n");
    for (i = 0; i < n; i++) {
        printf("Data nilai ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Masukkan nilai mahasiswa yang ingin dicari: ");
    scanf("%d", &target);

    int posisi = binarySearch(arr, 0, n - 1, target);

    if (posisi == -1) {
        printf("Nilai mahasiswa tidak ditemukan.\n");
    } else {
        printf("Nilai mahasiswa ditemukan pada posisi %d.\n", posisi + 1);
    }

    return 0;
}