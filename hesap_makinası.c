#include <stdio.h>
#include <math.h>   // pow() ve sqrt() için

int main() {
    int secim;
    double sayi1, sayi2, sonuc;

    printf("=== GELİŞMİŞ HESAP MAKİNESİ ===\n");

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

        // Karekök dışındaki işlemler 2 sayı ister
        if (secim >= 1 && secim <= 5 || secim == 7) {
            printf("Birinci sayıyı gir: ");
            scanf("%lf", &sayi1);
            printf("İkinci sayıyı gir: ");
            scanf("%lf", &sayi2);
        } else if (secim == 6) {
            printf("Karekök alınacak sayıyı gir: ");
            scanf("%lf", &sayi1);
        }

        switch (secim) {
            case 1:
                sonuc = sayi1 + sayi2;
                printf("Sonuç: %.2lf\n", sonuc);
                break;
            case 2:
                sonuc = sayi1 - sayi2;
                printf("Sonuç: %.2lf\n", sonuc);
                break;
            case 3:
                sonuc = sayi1 * sayi2;
                printf("Sonuç: %.2lf\n", sonuc);
                break;
            case 4:
                if (sayi2 == 0) {
                    printf("Hata: 0’a bölünemez!\n");
                } else {
                    sonuc = sayi1 / sayi2;
                    printf("Sonuç: %.2lf\n", sonuc);
                }
                break;
            case 5:
                sonuc = pow(sayi1, sayi2);
                printf("%.2lf ^ %.2lf = %.2lf\n", sayi1, sayi2, sonuc);
                break;
            case 6:
                if (sayi1 < 0) {
                    printf("Hata: Negatif sayının karekökü alınamaz!\n");
                } else {
                    sonuc = sqrt(sayi1);
                    printf("√%.2lf = %.2lf\n", sayi1, sonuc);
                }
                break;
            case 7:
                if ((int)sayi2 == 0) {
                    printf("Hata: 0’a göre mod alınamaz!\n");
                } else {
                    int modSonuc = (int)sayi1 % (int)sayi2;
                    printf("Sonuç: %d\n", modSonuc);
                }
                break;
            default:
                printf("Geçersiz seçim! Lütfen 0-7 arasında bir sayı gir.\n");
        }
    }

    return 0;
}
