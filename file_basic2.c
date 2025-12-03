#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char isim[50];
    int notu;
} Ogrenci;

Ogrenci list[MAX];
int adet = 0;

// ------------------------------------------------------------
// 1) Belleğe öğrenci ekleme
// ------------------------------------------------------------
void kayitEkle() {
    if (adet >= MAX) {
        printf("Liste dolu!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &list[adet].id);

    printf("Isim: ");
    scanf("%s", list[adet].isim);

    printf("Not: ");
    scanf("%d", &list[adet].notu);

    adet++;
    printf("Kayit eklendi!\n");
}

// ------------------------------------------------------------
// 2) Bellekteki kayıtları listeleme
// ------------------------------------------------------------
void kayitListele() {
    if (adet == 0) {
        printf("Hic kayit yok.\n");
        return;
    }

    printf("\n--- OGRENCI LISTESI ---\n");
    for (int i = 0; i < adet; i++) {
        printf("%d) ID=%d | Isim=%s | Not=%d\n",
               i + 1,
               list[i].id,
               list[i].isim,
               list[i].notu);
    }
}

// ------------------------------------------------------------
// 3) Listeyi CSV dosyasına yazma
// ------------------------------------------------------------
void dosyayaYaz() {
    FILE *f = fopen("ogrenci.csv", "w");
    if (!f) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < adet; i++) {
        fprintf(f, "%d;%s;%d\n",
                list[i].id,
                list[i].isim,
                list[i].notu);
    }

    fclose(f);
    printf("Dosyaya yazildi (ogrenci.csv)\n");
}

// ------------------------------------------------------------
// 4) Güncelleme/Silme (dosya üzerinden)
// ------------------------------------------------------------
void guncelleSil() {
    FILE *f = fopen("ogrenci.csv", "r");
    if (!f) {
        printf("Dosya bulunamadi!\n");
        return;
    }

    Ogrenci temp[MAX];
    int count = 0;

    // Dosyayı oku
    while (fscanf(f, "%d;%49[^;];%d\n",
                  &temp[count].id,
                  temp[count].isim,
                  &temp[count].notu) == 3) {
        count++;
    }
    fclose(f);

    if (count == 0) {
        printf("Dosyada kayit yok!\n");
        return;
    }

    printf("\n--- DOSYADAKI KAYITLAR ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d) ID=%d | Isim=%s | Not=%d\n",
               i + 1, temp[i].id, temp[i].isim, temp[i].notu);
    }

    int secim;
    printf("\n1) Kayit Sil\n2) Not Guncelle\nSecim: ");
    scanf("%d", &secim);

    int index;
    printf("Hangi numara?: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= count) {
        printf("Gecersiz!\n");
        return;
    }

    if (secim == 1) {
        // Silme: kaydı atla
        FILE *wf = fopen("ogrenci.csv", "w");
        for (int i = 0; i < count; i++) {
            if (i == index) continue;
            fprintf(wf, "%d;%s;%d\n",
                    temp[i].id, temp[i].isim, temp[i].notu);
        }
        fclose(wf);
        printf("Kayit silindi.\n");
    }
    else if (secim == 2) {
        printf("Yeni not: ");
        scanf("%d", &temp[index].notu);

        FILE *wf = fopen("ogrenci.csv", "w");
        for (int i = 0; i < count; i++) {
            fprintf(wf, "%d;%s;%d\n",
                    temp[i].id, temp[i].isim, temp[i].notu);
        }
        fclose(wf);
        printf("Kayit guncellendi.\n");
    }
}

// ------------------------------------------------------------
// 5) Dosya boyutu ölçme
// ------------------------------------------------------------
void dosyaBoyutu() {
    FILE *f = fopen("ogrenci.csv", "r");
    if (!f) {
        printf("Dosya yok.\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);

    printf("ogrenci.csv boyutu: %ld byte\n", size);
}

// ------------------------------------------------------------
// 6) Dosya silme
// ------------------------------------------------------------
void dosyaSil() {
    if (remove("ogrenci.csv") == 0)
        printf("Dosya silindi.\n");
    else
        printf("Dosya silinemedi.\n");
}

// ------------------------------------------------------------
// 7) Dosya adını değiştirme
// ------------------------------------------------------------
void dosyaYenidenAdlandir() {
    char yeni[50];
    printf("Yeni dosya adi: ");
    scanf("%s", yeni);

    if (rename("ogrenci.csv", yeni) == 0)
        printf("Dosya adi degistirildi.\n");
    else
        printf("Islem basarisiz.\n");
}

// ------------------------------------------------------------
// MENÜ
// ------------------------------------------------------------
int main() {
    int secim;

    do {
        printf("\n===== OGRENCI SISTEMI =====\n");
        printf("1) Kayit ekle\n");
        printf("2) Kayit listele\n");
        printf("3) Dosyaya yaz (CSV)\n");
        printf("4) Guncelle / Sil\n");
        printf("5) Dosya boyutu goster\n");
        printf("6) Dosya sil\n");
        printf("7) Dosya adini degistir\n");
        printf("8) Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: kayitEkle(); break;
            case 2: kayitListele(); break;
            case 3: dosyayaYaz(); break;
            case 4: guncelleSil(); break;
            case 5: dosyaBoyutu(); break;
            case 6: dosyaSil(); break;
            case 7: dosyaYenidenAdlandir(); break;
            case 8: printf("Cikis yapildi.\n"); break;
            default: printf("Gecersiz secim!\n");
        }

    } while (secim != 8);

    return 0;
}
