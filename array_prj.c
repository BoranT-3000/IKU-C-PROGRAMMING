#include <stdio.h>
#include <stdlib.h>

int main() {
    int kapasite = 2;  
    int elemanSayisi = 0;
    
    int *dizi = malloc(kapasite * sizeof(int));

    if (dizi == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }

    int secim;
    while (1) {
        printf("\n1- Eleman ekle\n");
        printf("2- Dizi yazdir\n");
        printf("3- Eleman ara\n");
        printf("5- Diziyi sifirla\n");
        printf("0- Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        if (secim == 0) break;

        if (secim == 1) {
            // Yer doldu mu?
            if (elemanSayisi == kapasite) {
                kapasite *= 2;  // 2 katına çıkar
                
                int *temp = realloc(dizi, kapasite * sizeof(int));
                if (temp == NULL) {
                    printf("Bellek genisletilemedi!\n");
                    free(dizi);
                    return 1;
                }
                dizi = temp;
                printf("Dizi genisletildi! Yeni kapasite: %d\n", kapasite);
            }

            printf("Sayi gir: ");
            scanf("%d", &dizi[elemanSayisi]);
            elemanSayisi++;
        }

        if (secim == 2) {
            printf("Dizi elemanlari: ");
            for (int i = 0; i < elemanSayisi; i++) {
                printf("%d ", dizi[i]);
            }
            printf("\n");
        }

        if (secim == 3) {
            int aranacak, bulundu = 0;
            printf("Aranacak sayiyi gir: ");
            scanf("%d", &aranacak);

            for (int i = 0; i < elemanSayisi; i++) {
                if (dizi[i] == aranacak) {
                    printf("Sayi dizide bulundu! Indeks: %d\n", i);
                    bulundu = 1;
                    break;
                }
            }

            if (!bulundu)
                printf("Sayi dizide yok.\n");
        }

        if (secim == 5) {
            elemanSayisi = 0;
            printf("Dizi sifirlandi! (Eleman sayisi = 0)\n");
        }


        if (secim == 6) {
            int idx;
            printf("Silinecek indeks: ");
            scanf("%d", &idx);

            if (idx < 0 || idx >= elemanSayisi) {
                printf("Gecersiz indeks!\n");
            } else {
                for (int i = idx; i < elemanSayisi - 1; i++)
                    dizi[i] = dizi[i + 1];

                elemanSayisi--;
                printf("Eleman silindi.\n");
            }
        }



    }

    free(dizi);
    return 0;
}
