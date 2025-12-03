#include <stdio.h>
#include <string.h>

int main() {

    FILE *f;
    // Dosya açma kipleri:
    // "w"	Yazma → dosya varsa içini siler
    // "a"	Ekleme → sona ekler, silmez
    // "r"	Okuma → dosya yoksa hata
    // "w+"	Hem okuma hem yazma (silerek)
    // "a+"	Hem okuma hem ekleme
    // "r+"	Hem okuma hem yazma (silmeden)

    // ------------------------------------------
    // 1) DOSYAYA YAZMA
    // ------------------------------------------
    f = fopen("kisiler.txt", "w");

    if (f == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    char isim[50];
    int yas;

    for (int i = 0; i < 3; i++) {
        printf("%d. kisinin ismi: ", i + 1);
        fgets(isim, sizeof(isim), stdin);
        isim[strcspn(isim, "\n")] = '\0';

        printf("%d. kisinin yasi: ", i + 1);
        scanf("%d", &yas);
        getchar();

        // dosyaya yaz
        fprintf(f, "%s %d\n", isim, yas);
    }

    fclose(f);
    printf("\nKisiler dosyaya yazildi.\n");


    // ------------------------------------------
    // 2) DOSYADAN OKUMA
    // ------------------------------------------
    printf("\n--- DOSYADAN OKUNAN VERILER ---\n");

    f = fopen("kisiler.txt", "r");
    if (f == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    char satir[100];
    while (fgets(satir, sizeof(satir), f)) {
        printf("%s", satir);
    }

    fclose(f);

    return 0;
}
