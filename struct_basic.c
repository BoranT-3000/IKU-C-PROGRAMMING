#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Çok basit struct (sadece 3 şey var)
struct Ogrenci {
    int no;
    char isim[30];
    float notu;
};

// Tüm fonksiyonları en basit hâliyle yazdık
struct Ogrenci* listeOlustur(int adet) {
    return (struct Ogrenci*)malloc(adet * sizeof(struct Ogrenci));
}

void bilgiGir(struct Ogrenci *o) {
    printf("Numara: ");
    scanf("%d", &o->no);
    getchar(); // enter'ı temizle

    printf("Isim   : ");
    fgets(o->isim, 30, stdin);
    o->isim[strlen(o->isim)-1] = '\0'; // sonundaki \n'yi sil

    printf("Not    : ");
    scanf("%f", &o->notu);
    getchar();
}

void yazdir(struct Ogrenci o) {
    printf("%3d - %-15s - %.2f\n", o.no, o.isim, o.notu);
}

void tumunuYazdir(struct Ogrenci *liste, int adet) {
    printf("\n--- OGRENCİ LİSTESİ ---\n");
    for(int i = 0; i < adet; i++) {
        yazdir(liste[i]);
    }
    printf("\n");
}

int main() {
    int kac_kisi;
    
    printf("=== HOŞ GELDİNİZ ÇOCUKLAR! ===\n");
    printf("Kaç öğrenci gireceksiniz? ");
    scanf("%d", &kac_kisi);
    getchar(); // enter temizle

    // 1) Dinamik liste oluştur
    struct Ogrenci *sinif = listeOlustur(kac_kisi);

    // 2) Bilgileri gir
    for(int i = 0; i < kac_kisi; i++) {
        printf("\n%d. öğrenci:\n", i+1);
        bilgiGir(&sinif[i]);
    }

    // 3) Normal liste
    tumunuYazdir(sinif, kac_kisi);

    // 4) Nota göre sırala (küçükten büyüğe)
    for(int i = 0; i < kac_kisi-1; i++) {
        for(int j = 0; j < kac_kisi-i-1; j++) {
            if(sinif[j].notu > sinif[j+1].notu) {
                // yer değiştir
                struct Ogrenci gecici = sinif[j];
                sinif[j] = sinif[j+1];
                sinif[j+1] = gecici;
            }
        }
    }

    printf("=== NOTA GÖRE SIRALANDI ===\n");
    tumunuYazdir(sinif, kac_kisi);

    // 5) İsme göre sırala (A'dan Z'ye)
    for(int i = 0; i < kac_kisi-1; i++) {
        for(int j = 0; j < kac_kisi-i-1; j++) {
            if(strcmp(sinif[j].isim, sinif[j+1].isim) > 0) {
                struct Ogrenci gecici = sinif[j];
                sinif[j] = sinif[j+1];
                sinif[j+1] = gecici;
            }
        }
    }

    printf("=== İSME GÖRE SIRALANDI ===\n");
    tumunuYazdir(sinif, kac_kisi);

    free(sinif); // belleği temizle
    printf("Program bitti, elinize sağlık çocuklar!\n");
    return 0;
}