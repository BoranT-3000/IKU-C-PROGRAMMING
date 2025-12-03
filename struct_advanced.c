#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// stdio.h → giriş/çıkış
// stdlib.h → bellek + genel araçlar
// string.h → yazı (string) işlemleri
// ctype.h → karakter analizi (büyük/küçük harf vb.)

// =====================================================
// ENUM + STRUCT + TYPEDEF
// =====================================================

// Enum (öğrencinin durumunu göstermek için)
typedef enum {
    BASARILI,
    KALDI
} Durum;

// Struct
typedef struct {
    int id;
    char isim[30];
    float ortalama;
    Durum durum;     // enum field
} Ogrenci;


// -----------------------------------------------------
//  FONKSİYON PROTOTİPLERİ
// -----------------------------------------------------
Ogrenci* dinamikListe(int n);
void ogrenciGir(Ogrenci *o);
void yazdir(Ogrenci o);
void listeYazdir(Ogrenci *liste, int n);

void listeyiDosyayaYaz(Ogrenci *liste, int n, const char *dosya);
void dosyadanOku(const char *dosya);

void siralaOrtalama(Ogrenci *liste, int n);
void siralaIsmeGore(Ogrenci *liste, int n);


// =====================================================
//                        MAIN
// =====================================================

int main() {

    int n;
    printf("Kac ogrenci ekleyeceksiniz? ");
    scanf("%d", &n);
    getchar(); // \n temizle

    // 1) DİNAMİK STRUCT LİSTESİ
    Ogrenci *liste = dinamikListe(n);

    // 2) Veri girişleri
    for (int i = 0; i < n; i++) {
        printf("\n[%d] Ogrenci bilgisi giriniz:\n", i + 1);
        ogrenciGir(&liste[i]);
    }

    printf("\n--- GIRILEN OGRENCILER ---\n");
    listeYazdir(liste, n);


    // 3) İsme göre sıralama
    printf("\n--- ISME GORE SIRALAMA ---\n");
    siralaIsmeGore(liste, n);
    listeYazdir(liste, n);

    // 4) Ortalama göre sıralama
    printf("\n--- ORTALAMAYA GORE SIRALAMA ---\n");
    siralaOrtalama(liste, n);
    listeYazdir(liste, n);

    // 5) Dosyaya yazma
    printf("\nVeriler dosyaya yaziliyor...\n");
    listeyiDosyayaYaz(liste, n, "ogrenciler.txt");

    printf("\nDosyadan okunan veriler:\n");
    dosyadanOku("ogrenciler.txt");

    free(liste);
    return 0;
}


// =====================================================
//        DİNAMİK STRUCT LİSTESİ OLUŞTURMA
// =====================================================

Ogrenci* dinamikListe(int n) {
    Ogrenci *liste = malloc(n * sizeof(Ogrenci));

    if (liste == NULL) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }

    return liste;
}


// =====================================================
//                ÖĞRENCİ VERİSİ GİRİŞİ
// =====================================================

void ogrenciGir(Ogrenci *o) {

    printf("ID: ");
    scanf("%d", &o->id);
    getchar();

    printf("Isim: ");
    fgets(o->isim, sizeof(o->isim), stdin);
    o->isim[strcspn(o->isim, "\n")] = '\0';

    printf("Ortalama: ");
    scanf("%f", &o->ortalama);
    getchar();

    o->durum = (o->ortalama >= 50) ? BASARILI : KALDI;
}


// =====================================================
//          YAZDIRMA FONKSİYONLARI
// =====================================================

void yazdir(Ogrenci o) {
    printf("ID: %d | Isim: %-10s | Ortalama: %.2f | Durum: %s\n",
           o.id, o.isim, o.ortalama,
           o.durum == BASARILI ? "Başarılı" : "Kaldı");
}

void listeYazdir(Ogrenci *liste, int n) {
    for (int i = 0; i < n; i++)
        yazdir(liste[i]);
}


// =====================================================
//              ÖĞRENCİLERİ DOSYAYA YAZMA
// =====================================================

void listeyiDosyayaYaz(Ogrenci *liste, int n, const char *dosya) {
    FILE *f = fopen(dosya, "w");

    if (!f) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d,%s,%.2f,%d\n",
                liste[i].id,
                liste[i].isim,
                liste[i].ortalama,
                liste[i].durum
        );
    }

    fclose(f);
    printf("Dosyaya yazildi: %s\n", dosya);
}


// =====================================================
//         DOSYADAN OKUMA (FILE I/O)
// =====================================================

void dosyadanOku(const char *dosya) {
    FILE *f = fopen(dosya, "r");
    if (!f) {
        printf("Dosya acilamadi!\n");
        return;
    }

    char satir[200];

    while (fgets(satir, sizeof(satir), f)) {
        printf("%s", satir);
    }

    fclose(f);
}


// =====================================================
//            SIRALAMA FONKSİYONLARI
// =====================================================

// Ortalama küçükten büyüğe
void siralaOrtalama(Ogrenci *liste, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (liste[j].ortalama > liste[j + 1].ortalama) {
                Ogrenci temp = liste[j];
                liste[j] = liste[j + 1];
                liste[j + 1] = temp;
            }
        }
    }
}

// İsme göre alfabetik sıralama
void siralaIsmeGore(Ogrenci *liste, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (strcmp(liste[j].isim, liste[j + 1].isim) > 0) {
                Ogrenci temp = liste[j];
                liste[j] = liste[j + 1];
                liste[j + 1] = temp;
            }
        }
    }
}
