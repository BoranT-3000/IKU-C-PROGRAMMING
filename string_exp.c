#include <stdio.h>
#include <string.h>    // String fonksiyonları için mutlaka lazım!

int main() {
    
    printf("=== C'DE STRING (METİN) ÖRNEKLERİ ===\n\n");
    
    // 1) CHAR DİZİSİ İLE STRING TANIMLAMA (en temel yol)
   
    char isim1[20] = "Boran Toktay";           // 20 karakterlik yer ayırdık
    char isim2[] = "Aral";            // Boyutu otomatik ayarlanır
    char isim3[20];                     // Boş bir dizi, sonra dolduracağız
    char isim4[20];
    
    printf("1) Char dizisi ile stringler:\n");
    printf("   isim1 = %s\n", isim1);
    printf("   isim2 = %s\n", isim2);
    
    printf("\n 2) Adini gir bakalim: ");
    scanf("%s", isim4);               // boşluk olursa sonrasını almaz
    printf("   Hos geldin %s!\n", isim4);

    // 2) KULLANICIDAN STRING ALMA
    printf("\n2) Adini gir bakalim: ");
    // scanf("%s", isim3);                     // sadece boşluğa kadar alır
    fgets(isim3, 20, stdin);                   // boşluklu da alır, tavsiye edilir!
    
    // fgets satır sonunu (\n) da alır, onu temizleyelim
    int len = strlen(isim3);
    if (isim3[len-1] == '\n') 
        isim3[len-1] = '\0';
    
    printf("   Hos geldin %s!\n", isim3);
    
    // 3) EN ÇOK KULLANILAN STRING FONKSİYONLARI
    printf("\n3) String fonksiyonları örnekleri:\n");
    
    char kelime1[50] = "Merhaba";
    char kelime2[50] = "Dünya";
    char birlesik[100];
    
    // strlen → uzunluk bulur
    printf("   \"Merhaba\" kelimesinin uzunlugu = %lu\n", strlen(kelime1));
    
    // strcpy → bir stringi diğerine kopyalar
    char kopya[50];
    strcpy(kopya, kelime1);
    printf("   kopya = %s\n", kopya);
    
    // strcat → iki stringi birleştirir
    strcpy(birlesik, kelime1);        // önce birini koyalım
    strcat(birlesik, " ");            // boşluk ekle
    strcat(birlesik, kelime2);        // ikinciyi ekle
    printf("   Birleştirme = %s\n", birlesik);
    
    // strcmp → iki stringi karşılaştırır (alfabetik sıra)
    printf("\n   Karşılaştırma örnekleri:\n");
    printf("   strcmp(\"elma\",\"armut\") = %d\n", strcmp("elma", "armut"));   // negatif → elma önce gelir
    printf("   strcmp(\"ali\",\"ali\") = %d\n", strcmp("ali", "ali"));         // 0 → aynı
    printf("   strcmp(\"zeynep\",\"ahmet\") = %d\n", strcmp("zeynep", "ahmet")); // pozitif → zeynep sonra gelir
    
    // pratik kullanım: isimleri alfabetik sıralamak için
    if (strcmp(isim1, isim3) < 0)
        printf("   %s, %s'den once gelir\n", isim1, isim3);
    else
        printf("   %s, %s'den once gelir\n", isim3, isim1);
    
    // 4) KÜÇÜK HARF - BÜYÜK HARF ÇEVİRME (çok sorulur)
    printf("\n4) Buyuk-kucuk harf cevirme:\n");
    char cumle[100] = "BuRaKaN 1453";
    printf("   Once: %s\n", cumle);
    
    for(int i = 0; cumle[i] != '\0'; i++) {
        if (cumle[i] >= 'A' && cumle[i] <= 'Z')
            cumle[i] = cumle[i] + 32;        // büyük → küçük
        // else if (cumle[i] >= 'a' && cumle[i] <= 'z')
        //     cumle[i] = cumle[i] - 32;        // küçük → büyük (yorum satırını açarsan büyük yapar)
    }
    printf("   Sonra: %s\n", cumle);
    
    printf("\n=== Bitti, soru sorabilirsiniz! ===\n");
    return 0;
}