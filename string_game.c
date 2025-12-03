#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DOSYA_ADI "kelimeler.txt"
#define MAX_KELIME 200
#define MAX_UZUNLUK 25
#define SIFRE "iku2025"        // buradan değiştirirsin

char kelimeler[MAX_KELIME][MAX_UZUNLUK];
int kelime_sayisi = 0;

// Dosyadan kelimeleri yükle
void kelimeleri_yukle() {
    FILE *dosya = fopen(DOSYA_ADI, "r");
    if(dosya == NULL) {
        printf("kelimeler.txt bulunamadı, yeni oluşturulacak...\n");
        return;
    }

    kelime_sayisi = 0;
    while(fgets(kelimeler[kelime_sayisi], MAX_UZUNLUK, dosya)) {
        kelimeler[kelime_sayisi][strcspn(kelimeler[kelime_sayisi], "\n")] = '\0';
        if(strlen(kelimeler[kelime_sayisi]) > 0) {
            kelime_sayisi++;
            if(kelime_sayisi >= MAX_KELIME) break;
        }
    }
    fclose(dosya);
    printf("%d kelime yüklendi.\n\n", kelime_sayisi);
}

// Dosyaya tüm kelimeleri kaydet
void kelimeleri_kaydet() {
    FILE *dosya = fopen(DOSYA_ADI, "w");
    if(dosya == NULL) {
        printf("Dosya yazma hatası!\n");
        return;
    }
    for(int i = 0; i < kelime_sayisi; i++) {
        fprintf(dosya, "%s\n", kelimeler[i]);
    }
    fclose(dosya);
}

// Karıştırma fonksiyonu
void karistir(char kelime[]) {
    int n = strlen(kelime);
    for(int i = 0; i < n*10; i++) {
        int a = rand() % n;
        int b = rand() % n;
        char temp = kelime[a];
        kelime[a] = kelime[b];
        kelime[b] = temp;
    }
}

// Admin paneli
void admin_paneli() {
    char sifre[30];
    printf("\n=== ADMIN GİRİŞİ ===\nŞifre: ");
    fgets(sifre, 30, stdin);
    sifre[strcspn(sifre, "\n")] = '\0';

    if(strcmp(sifre, SIFRE) != 0) {
        printf("Yanlış şifre!\n\n");
        return;
    }

    int secim;
    do {
        printf("\n--- ADMIN PANELİ (%d kelime) ---\n", kelime_sayisi);
        printf("1) Kelimeleri Listele\n");
        printf("2) Yeni Kelime Ekle\n");
        printf("3) Kelime Sil\n");
        printf("4) Dosyaya Kaydet ve Çık\n");
        printf("Seçim: ");
        scanf("%d", &secim);
        getchar();

        if(secim == 1) {
            printf("\n--- KELİME LİSTESİ ---\n");
            for(int i = 0; i < kelime_sayisi; i++) {
                printf("%3d) %s\n", i+1, kelimeler[i]);
            }
        }
        else if(secim == 2) {
            if(kelime_sayisi >= MAX_KELIME) {
                printf("Depo dolu!\n");
            } else {
                printf("Yeni kelime: ");
                fgets(kelimeler[kelime_sayisi], MAX_UZUNLUK, stdin);
                kelimeler[kelime_sayisi][strcspn(kelimeler[kelime_sayisi], "\n")] = '\0';
                if(strlen(kelimeler[kelime_sayisi]) > 0) {
                    kelime_sayisi++;
                    printf("Kelime eklendi!\n");
                }
            }
        }
        else if(secim == 3) {
            int no;
            printf("Silinecek kelime numarası: ");
            scanf("%d", &no);
            getchar();
            if(no < 1 || no > kelime_sayisi) {
                printf("Geçersiz numara!\n");
            } else {
                printf("\"%s\" silindi.\n", kelimeler[no-1]);
                for(int i = no-1; i < kelime_sayisi-1; i++) {
                    strcpy(kelimeler[i], kelimeler[i+1]);
                }
                kelime_sayisi--;
            }
        }
    } while(secim != 4);

    kelimeleri_kaydet();  // Çıkarken mutlaka kaydet!
    printf("Kelimeler kaydedildi. Oyuna dönülüyor...\n\n");
}

// Oyun fonksiyonu (önceki gibi)
void oyunu_oyna() {
    if(kelime_sayisi == 0) {
        printf("Kelime yok! Admin ile ekleyiniz.\n\n");
        return;
    }

    int secilen = rand() % kelime_sayisi;
    char gizli[30], karisik[30];
    strcpy(gizli, kelimeler[secilen]);
    strcpy(karisik, gizli);
    karistir(karisik);

    char tahmin[30];
    int hak = 6;

    printf("\n=== KELİME TAHMİN OYUNU ===\n");
    printf("Karışık: %s\n", karisik);
    printf("6 hakkin var!\n\n");

    while(hak > 0) {
        printf("Tahmin (%d): ", hak);
        fgets(tahmin, 30, stdin);
        tahmin[strcspn(tahmin, "\n")] = '\0';

        if(strcmp(tahmin, gizli) == 0) {
            printf("\nTEBRİKLER! Doğru kelime: %s\n\n", gizli);
            return;
        }

        int dogru_yer = 0, yanlis_yerde = 0;
        char kg[30], kt[30];
        strcpy(kg, gizli);
        strcpy(kt, tahmin);

        for(int i = 0; kg[i]; i++) {
            if(kg[i] == kt[i]) {
                dogru_yer++;
                kg[i] = '*'; kt[i] = '#';
            }
        }
        for(int i = 0; kt[i]; i++) {
            if(kt[i] != '#') {
                char *p = strchr(kg, kt[i]);
                if(p) { yanlis_yerde++; *p = '*'; }
            }
        }

        printf("Doğru yerde: %d  |  Yanlış yerde: %d\n\n", dogru_yer, yanlis_yerde);
        hak--;
    }
    printf("Haklar bitti! Kelime: %s\n\n", gizli);
}

int main() {
    srand(time(NULL));
    kelimeleri_yukle();  // Program başlar başlamaz dosyadan oku

    // Eğer dosya yoksa birkaç örnek kelime koy
    if(kelime_sayisi == 0) {
        strcpy(kelimeler[0], "bilgisayar"); kelime_sayisi++;
        strcpy(kelimeler[1], "kodlama");    kelime_sayisi++;
        strcpy(kelimeler[2], "klavye");     kelime_sayisi++;
        strcpy(kelimeler[3], "istanbul");   kelime_sayisi++;
        strcpy(kelimeler[4], "cprogramlama"); kelime_sayisi++;
        kelimeleri_kaydet();
        printf("Örnek kelimeler oluşturuldu.\n\n");
    }

    char secim;
    do {
        printf("╔══════════════════════════╗\n");
        printf("║    KELİME TAHMİN OYUNU   ║\n");
        printf("╚══════════════════════════╝\n");
        printf("1) Oyunu Oyna\n");
        printf("2) Admin Paneli\n");
        printf("3) Çıkış\n");
        printf("Seçimin: ");
        scanf(" %c", &secim);
        getchar();

        if(secim == '1') oyunu_oyna();
        else if(secim == '2') admin_paneli();

    } while(secim != '3');

    printf("\nGüle güle! Yine bekleriz!\n");
  
    return 0;
}