#include <stdio.h>

double ortalamaHesapla(int dizi[], int boyut);

int main() {
    int n;
    // int notlar[n]; // burada çalışmaaz çünkü n henüz tanımlanmadı!
    int toplam = 0;
    double ortalama;
    int max, min;

    printf("Kaç öğrencinin notunu gireceksin? ");
    scanf("%d", &n);

    int notlar[n];
    
    printf("%d öğrencinin notunu gir:\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d. not: ", i + 1);
        scanf("%d", &notlar[i]);
    }

    printf("\nGirilen notlar:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", notlar[i]);
        toplam += notlar[i];
        // toplam = toplam + notlar[i];

        if (i == 0)
        {
            max = notlar[i];
            min = notlar[i];
        }
        else
        {
            if (notlar[i] > max)
                max = notlar[i];
            if (notlar[i] < min)
                min = notlar[i];
        }

    }


    printf("Tersten notlar: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", notlar[i]);
    }

    ortalama = (double)toplam / n;

    printf("\nToplam: %d\n", toplam);

    ortalama = ortalamaHesapla(notlar, n);
    printf("Ortalama: %.2lf\n", ortalama);


    printf("En büyük: %d\n", max);
    printf("En küçük: %d\n", min);

    return 0;
}

double ortalamaHesapla(int dizi[], int boyut) {
    int toplam = 0;
    for (int i = 0; i < boyut; i++)
        toplam += dizi[i];
    return (double)toplam / boyut;
}