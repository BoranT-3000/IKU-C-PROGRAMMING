#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1) DOSYA OLUŞTURMA ve YAZMA (w)
    FILE *f = fopen("data.txt", "w");
    if (!f) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    fprintf(f, "Merhaba Dünya!\n");
    fprintf(f, "Bu dosya write modunda olusturuldu.\n");

    fclose(f);


    // 2) DOSYA SONUNA EKLEME (a)
    f = fopen("data.txt", "a");
    fprintf(f, "Append modunda yeni satir eklendi.\n");
    fclose(f);


    // 3) DOSYA OKUMA (fgets ile satir satir)
    f = fopen("data.txt", "r");
    if (!f) {
        printf("Dosya bulunamadi!\n");
        return 1;
    }

    printf("\n--- DOSYA ICERIGI ---\n");
    char satir[200];
    while (fgets(satir, sizeof(satir), f)) {
        printf("%s", satir);
    }
    fclose(f);


    // 4) FORMATLI YAZMA / OKUMA (CSV gibi)
    FILE *csv = fopen("ogrenci.csv", "w");
    if (!csv) {
        printf("ogrenci.csv acilamadi!\n");
        return 1;
    }

    fprintf(csv, "1;Ali;85\n");
    fprintf(csv, "2;Ayse;90\n");
    fprintf(csv, "3;Mehmet;77\n");

    fclose(csv);


    // Şimdi CSV'yi okuyalım
    csv = fopen("ogrenci.csv", "r");
    if (!csv) {
        printf("ogrenci.csv bulunamadi!\n");
        return 1;
    }

    printf("\n--- OGRENCI LISTESI ---\n");

    int id, notu;
    char isim[50];

    while (fscanf(csv, "%d;%49[^;];%d\n", &id, isim, &notu) == 3) {
        printf("ID=%d | Isim=%s | Not=%d\n", id, isim, notu);
    }

    fclose(csv);

    return 0;
}
