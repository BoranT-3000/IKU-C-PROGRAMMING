#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Kelimeler doğrudan kodun içinde (çocuklar görsün diye)
char *kelimeler[] = {
    "elma", "armut", "kiraz", "muz", "portakal",
    "kedi", "köpek", "kuş", "balık", "at",
    "araba", "okul", "kalem", "defter", "silgi"
};
int kelime_sayisi = 15;  // toplam 15 kelime

int main() {
    srand(time(NULL));
    
    printf("Merhaba çocuklar! Kelime oyunu başlıyor\n\n");
    
    oynayalim:
    
    // Rastgele bir kelime seç
    int rastgele = rand() % kelime_sayisi;
    char dogru[20];
    strcpy(dogru, kelimeler[rastgele]);
    
    // Kelimeyi karıştır
    char karisik[20];
    strcpy(karisik, dogru);
    
    int uzunluk = strlen(karisik);
    for(int i = 0; i < uzunluk*5; i++) {
        int a = rand() % uzunluk;
        int b = rand() % uzunluk;
        char gecici = karisik[a];
        karisik[a] = karisik[b];
        karisik[b] = gecici;
    }
    
    // Oyunu oyna
    printf("Karıştırılmış kelime: %s\n", karisik);
    printf("Bu ne olabilir? Tahminin: ");
    
    char tahmin[20];
    fgets(tahmin, 20, stdin);
    tahmin[strlen(tahmin)-1] = '\0';  // enter'ı sil
    
    if(strcmp(tahmin, dogru) == 0) {
        printf("SÜPER! Doğru bildin: %s\n\n", dogru);
    }
    else {
        printf("Üzgünüm, doğru kelime: %s idi\n\n", dogru);
    }
    
    // Tekrar mı?
    printf("Tekrar oynayalım mı? (e yaz, başka tuş çık): ");
    char cevap;
    scanf("%c", &cevap);
    getchar(); // enter'ı temizle
    
    if(cevap == 'e' || cevap == 'E') {
        printf("\nHadi yine oynayalım!\n\n");
        goto oynayalim;  // tekrar başa dön
    }
    
    printf("\nGüle güle çocuklar! Yarın yine oynarız\n");
    return 0;
}