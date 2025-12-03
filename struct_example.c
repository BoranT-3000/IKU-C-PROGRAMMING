#include <stdio.h>
#include <string.h>

// ----------------------------
//  STRUCT TANIMI
// ----------------------------
struct Ogrenci {
    int id;
    char isim[30];
    float ortalama;
};

// Fonksiyon prototipleri
void yazdir(struct Ogrenci o);
void guncelle(struct Ogrenci *o);

int main() {

    // -------------------------------------------
    // 1) Struct değişkeni oluşturma
    // -------------------------------------------
    struct Ogrenci ogr1 = {1, "Ali", 78.5};

    printf("1) Tek Ogrenci:\n");
    yazdir(ogr1);


    // -------------------------------------------
    // 2) Struct içine kullanıcıdan veri alma
    // -------------------------------------------
    struct Ogrenci ogr2;

    printf("\n2) Ogrenci bilgisi gir:\n");

    printf("ID: ");
    scanf("%d", &ogr2.id);
    getchar(); // \n temizle

    printf("Isim: ");
    fgets(ogr2.isim, sizeof(ogr2.isim), stdin);
    ogr2.isim[strcspn(ogr2.isim, "\n")] = '\0';

    printf("Ortalama: ");
    scanf("%f", &ogr2.ortalama);

    printf("\nGirdigin Ogrenci:\n");
    yazdir(ogr2);


    // -------------------------------------------
    // 3) Struct Array
    // -------------------------------------------
    struct Ogrenci sinif[3] = {
        {101, "Ahmet", 50.0},
        {102, "Ayse", 90.5},
        {103, "Mehmet", 72.3}
    };

    printf("\n3) Struct Array:\n");
    for (int i = 0; i < 3; i++) {
        yazdir(sinif[i]);
    }


    // -------------------------------------------
    // 4) Struct pointer ile güncelleme
    // -------------------------------------------
    printf("\n4) Struct Pointer Ile Guncelleme:\n");
    guncelle(&ogr1);
    yazdir(ogr1);


    return 0;
}


// =====================================================
//  STRUCT FONKSIYONLARI
// =====================================================

// Struct pass-by-value (kopya gider)
void yazdir(struct Ogrenci o) {
    printf("ID: %d | Isim: %s | Ortalama: %.2f\n",
           o.id, o.isim, o.ortalama);
}

// Struct pass-by-pointer (gercek veriyi degistirir)
void guncelle(struct Ogrenci *o) {
    o->ortalama += 5;      // ortalamayı artır
    strcpy(o->isim, "Guncellendi"); 
}
