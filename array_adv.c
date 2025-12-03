#include <stdio.h>
#include <stdlib.h>

/*
    Bu dosyada malloc, calloc, realloc ve free
    fonksiyonlarının nasıl çalıştığını örneklerle gösteriyoruz.
*/

int main() {

    // ============================================================
    // 1) malloc ile dinamik dizi oluşturma
    // malloc -> sadece bellek ayırır, içini doldurmaz (çöp değer)
    // ============================================================

    printf("\n=== 1) malloc ile dinamik dizi ===\n");

    int n = 5;
    int *m = malloc(n * sizeof(int));

    if (m == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }

    // Diziye değer atama
    for (int i = 0; i < n; i++) {
        m[i] = (i + 1) * 10;
    }

    // Yazdırma
    printf("malloc ile olusan dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");

    /*
    Beklenen cikti:
    malloc ile olusan dizi: 10 20 30 40 50
    */


    /*
    ============================================================
        2) calloc ile dinamik dizi oluşturma
    ============================================================
    calloc -> bellek ayırır ve tüm değerleri 0 yapar
    */

    printf("\n=== 2) calloc ile dinamik dizi ===\n");

    int *c = calloc(5, sizeof(int));

    if (c == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }

    printf("calloc ile olusan dizi: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", c[i]);  // hepsi 0!
    }
    printf("\n");

    /*
    Beklenen cikti:
    calloc ile olusan dizi: 0 0 0 0 0
    */


    /*
    ============================================================
        3) realloc ile diziyi büyütme
    ============================================================
    realloc -> mevcut diziyi yeni boyuta genişletir
    */

    printf("\n=== 3) realloc ile dizi buyutme ===\n");

    int *r = malloc(3 * sizeof(int));
    r[0] = 10; r[1] = 20; r[2] = 30;

    printf("Eski dizi: ");
    for (int i = 0; i < 3; i++) printf("%d ", r[i]);

    // 3 → 6 eleman olacak şekilde büyütüyoruz
    int *temp = realloc(r, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Bellek genisletilemedi!\n");
        free(r);
        return 1;
    }
    r = temp;

    // Yeni elemanlara değer atayalım
    r[3] = 40;
    r[4] = 50;
    r[5] = 60;

    printf("\nYeni dizi: ");
    for (int i = 0; i < 6; i++) printf("%d ", r[i]);
    printf("\n");

    /*
    Beklenen cikti:
    Eski dizi: 10 20 30
    Yeni dizi: 40 50 60
    */


    /*
    ============================================================
        4) free ile belleği boşaltma
    ============================================================
    free -> ayrılmış bellek alanını geri bırakır
    */

    printf("\n=== 4) free kullanimi ===\n");

    free(m);
    free(c);
    free(r);

    printf("Bellek free ile serbest birakildi!\n");

    /*
    Burada gözle görülür bir çıktı yok ama
    bellek sızıntısını önlemek için free şarttır.
    */

    return 0;
}
