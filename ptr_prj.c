#include <stdio.h>

// --- Fonksiyon Prototipleri ---
void notlariYazdir(int *dizi, int n);
double ortalamaHesapla(int *dizi, int n);
void minMaxBul(int *dizi, int n, int *min, int *max);
int kacGecti(int *dizi, int n);
void sirala(int *dizi, int n);

int main() {
    int n;

    printf("Kaç öğrencinin notunu gireceksin? ");
    scanf("%d", &n);

    int notlar[n];  // VLA - Variable Length Array

    // --- NOTLARI AL ---
    for (int i = 0; i < n; i++) {
        printf("%d. öğrencinin notu: ", i + 1);
        scanf("%d", &notlar[i]);
    }

    printf("\n--- GİRİLEN NOTLAR ---\n");
    notlariYazdir(notlar, n);

    // --- ORTALAMA ---
    double ort = ortalamaHesapla(notlar, n);
    printf("\nOrtalama: %.2lf\n", ort);

    // --- MIN-MAX ---
    int min, max;
    minMaxBul(notlar, n, &min, &max);
    printf("En küçük not: %d\n", min);
    printf("En büyük not: %d\n", max);

    // --- KAÇ KİŞİ GEÇTİ ---
    int gecen = kacGecti(notlar, n);
    printf("Dersten geçen öğrenci sayısı: %d\n", gecen);

    // --- SIRALANMIŞ HALİ ---
    sirala(notlar, n);
    printf("\n--- SIRALANMIŞ NOTLAR (Küçükten büyüğe) ---\n");
    notlariYazdir(notlar, n);

    return 0;
}


// ============================================================
//                F O N K S I Y O N L A R
// ============================================================

// --- DİZİYİ POINTER İLE YAZDIR ---
void notlariYazdir(int *dizi, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(dizi + i));  // pointer arithmetic
    }
    printf("\n");
}

// --- ORTALAMA HESAPLAMA ---
double ortalamaHesapla(int *dizi, int n) {
    int toplam = 0;
    for (int i = 0; i < n; i++) {
        toplam += *(dizi + i);
    }
    return (double)toplam / n;
}

// --- MIN-MAX BULMA ---
void minMaxBul(int *dizi, int n, int *min, int *max) {
    *min = *max = dizi[0];

    for (int i = 1; i < n; i++) {
        if (*(dizi + i) > *max) *max = *(dizi + i);
        if (*(dizi + i) < *min) *min = *(dizi + i);
    }
}

// --- GEÇEN ÖĞRENCİ SAYISI ---
int kacGecti(int *dizi, int n) {
    int sayac = 0;
    for (int i = 0; i < n; i++) {
        if (*(dizi + i) >= 50)
            sayac++;
    }
    return sayac;
}

// --- POINTER İLE BUBBLE SORT ---
void sirala(int *dizi, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int *a = dizi + j;
            int *b = dizi + j + 1;

            if (*a > *b) {
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}
