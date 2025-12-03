void bul(int dizi[], int boyut, int *min, int *max) {
    *min = dizi[0];
    *max = dizi[0];

    for (int i = 1; i < boyut; i++) {
        if (dizi[i] < *min) *min = dizi[i];
        if (dizi[i] > *max) *max = dizi[i];
    }
}

int main() {
    int arr[5] = {5,2,9,1,7};
    int min, max;

    bul(arr, 5, &min, &max);

    printf("min = %d, max = %d\n", min, max);
}
// min = 1, max = 9