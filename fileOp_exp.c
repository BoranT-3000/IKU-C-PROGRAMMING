#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100   // maksimum kitap sayısı

// ---------------------------
// STRUCT TANIMI
// ---------------------------
typedef struct {
    int id;
    char isim[50];
    char yazar[50];
    int yil;
} Kitap;

// ---------------------------
// FONKSİYON PROTOTİPLERİ
// ---------------------------
void kitapEkle(Kitap liste[], int *adet);
void kitaplariYazdir(Kitap liste[], int adet);
void dosyayaKaydet(Kitap liste[], int adet);
int dosyadanYukle(Kitap liste[]);

int main() {

    Kitap kitaplar[MAX];
    int adet = dosyadanYukle(kitaplar);  // program açılır açılmaz dosyadan yükle

    int secim;

    while (1) {
        printf("\n=== KUTUPHANE MENU ===\n");
        printf("1 - Kitap Ekle\n");
        printf("2 - Kitaplari Listele\n");
        printf("3 - Dosyaya Kaydet\n");
        printf("0 - Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);
        getchar(); // \n temizle

        if (secim == 0) break;

        if (secim == 1) kitapEkle(kitaplar, &adet);
        else if (secim == 2) kitaplariYazdir(kitaplar, adet);
        else if (secim == 3) dosyayaKaydet(kitaplar, adet);
        else printf("Gecersiz secim!\n");
    }

    printf("Program kapatildi.\n");
    return 0;
}


// =====================================================
// KİTAP EKLEME
// =====================================================
void kitapEkle(Kitap liste[], int *adet) {

    printf("Kitap ID: ");
    scanf("%d", &liste[*adet].id);
    getchar();

    printf("Kitap ismi: ");
    fgets(liste[*adet].isim, sizeof(liste[*adet].isim), stdin);
    liste[*adet].isim[strcspn(liste[*adet].isim, "\n")] = '\0';

    printf("Yazar: ");
    fgets(liste[*adet].yazar, sizeof(liste[*adet].yazar), stdin);
    liste[*adet].yazar[strcspn(liste[*adet].yazar, "\n")] = '\0';

    printf("Yayin yili: ");
    scanf("%d", &liste[*adet].yil);
    getchar();

    (*adet)++;

    printf("Kitap eklendi!\n");
}

// =====================================================
// KİTAPLARI YAZDIRMA
// =====================================================
void kitaplariYazdir(Kitap liste[], int adet) {

    if (adet == 0) {
        printf("Hic kitap yok!\n");
        return;
    }

    printf("\n--- KITAP LISTESI ---\n");
    for (int i = 0; i < adet; i++) {
        printf("%d) ID: %d | Isim: %s | Yazar: %s | Yil: %d\n",
               i + 1,
               liste[i].id,
               liste[i].isim,
               liste[i].yazar,
               liste[i].yil);
    }
}

// =====================================================
// DOSYAYA KAYDETME
// =====================================================
void dosyayaKaydet(Kitap liste[], int adet) {

    FILE *f = fopen("kutuphane.txt", "w");

    if (!f) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < adet; i++) {
        fprintf(f, "%d;%s;%s;%d\n",
                liste[i].id,
                liste[i].isim,
                liste[i].yazar,
                liste[i].yil);
    }

    fclose(f);

    printf("Kitaplar dosyaya kaydedildi!\n");
}

// =====================================================
// DOSYADAN YÜKLEME
// =====================================================
int dosyadanYukle(Kitap liste[]) {

    FILE *f = fopen("kutuphane.txt", "r");
    if (!f) {
        printf("Ilk defa calisiyor, dosya yok.\n");
        return 0;
    }

    int adet = 0;

    while (!feof(f)) { // Dosyanın sonuna gelene kadar dön feof -> end of file
        Kitap k;
        if (fscanf(f, "%d;%49[^;];%49[^;];%d\n", &k.id, k.isim, k.yazar, &k.yil) == 4) {
            liste[adet++] = k;
        }

        // %49[^;] Noktalı virgüle gelene kadar en fazla 49 karakter oku.
    }

    fclose(f);

    printf("%d kitap dosyadan yuklendi.\n", adet);
    return adet;
}
