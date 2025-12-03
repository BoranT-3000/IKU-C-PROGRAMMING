#include <stdio.h>
#include <math.h> // pow() ve sqrt() için

// --- Fonksiyon Tanımları ---
double topla(double a, double b) {
    return a + b;
}

double cikar(double a, double b) {
    double temp_x = 0.0;
    temp_x = a - b;
    printf("Sonuç: %.2lf\n", temp_x);
    return temp_x;
}

double carp(double a, double b) {
    return a * b;
}

double bol(double a, double b) {
    if (b == 0) {
        printf("Hata: 0'a bölünemez!\n");
        return 0;
    }
    return a / b;
}

double us(double a, double b) {
    return pow(a, b);
}

double karekok(double a) {
    if (a < 0) {
        printf("Hata: Negatif sayının karekökü alınamaz!\n");
        return 0;
    }
    return sqrt(a);
}

int mod(int a, int b) {
    if (b == 0) {
        printf("Hata: 0’a göre mod alınamaz!\n");
        return 0;
    }
    return a % b;
}

// --- Ana Fonksiyon ---
int main() {
    int secim;
    double sayi1, sayi2, sonuc;

    printf("=== FONKSİYONLU GELİŞMİŞ HESAP MAKİNESİ ===\n");

    while (1) {
        printf("\n--- MENÜ ---\n");
        printf("1. Toplama\n");
        printf("2. Çıkarma\n");
        printf("3. Çarpma\n");
        printf("4. Bölme\n");
        printf("5. Üs Alma\n");
        printf("6. Karekök Alma\n");
        printf("7. Mod Alma\n");
        printf("0. Çıkış\n");
        printf("Seçimin: ");
        scanf("%d", &secim);

        if (secim == 0) {
            printf("Programdan çıkılıyor...\n");
            break;
        }

        switch (secim) {
            case 1:
                printf("Birinci sayı: "); 
                scanf("%lf", &sayi1);
                printf("İkinci sayı: "); 
                scanf("%lf", &sayi2);
                sonuc = topla(sayi1, sayi2);
                printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 2:
                printf("Birinci sayı: "); scanf("%lf", &sayi1);
                printf("İkinci sayı: "); scanf("%lf", &sayi2);
                sonuc = cikar(sayi1, sayi2);
                printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 3:
                printf("Birinci sayı: "); scanf("%lf", &sayi1);
                printf("İkinci sayı: "); scanf("%lf", &sayi2);
                sonuc = carp(sayi1, sayi2);
                printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 4:
                printf("Birinci sayı: "); scanf("%lf", &sayi1);
                printf("İkinci sayı: "); scanf("%lf", &sayi2);
                sonuc = bol(sayi1, sayi2);
                if (sayi2 != 0) printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 5:
                printf("Taban: "); scanf("%lf", &sayi1);
                printf("Üs: "); scanf("%lf", &sayi2);
                sonuc = us(sayi1, sayi2);
                printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 6:
                printf("Sayı: "); scanf("%lf", &sayi1);
                sonuc = karekok(sayi1);
                if (sayi1 >= 0) printf("Sonuç: %.2lf\n", sonuc);
                break;

            case 7: {
                int x, y;
                printf("Birinci sayı: "); scanf("%d", &x);
                printf("İkinci sayı: "); scanf("%d", &y);
                int modSonuc = mod(x, y);
                if (y != 0) printf("Sonuç: %d\n", modSonuc);
                break;
            }

            default:
                printf("Geçersiz seçim! Lütfen 0-7 arasında bir sayı gir.\n");
        }
    }

    printf("Program sonlandı.\n");
    return 0;
}
