#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {

    int choice;
    char filename[100];
    char text[200];
    char search[100];
    char line[300];

    do {
        printf("\n===== DOSYA MENUSU =====\n");
        printf("1 - Klasordeki .c dosyalarini listele\n");
        printf("2 - Dosya oku\n");
        printf("3 - Dosyada kelime ara\n");
        printf("4 - Dosyaya yaz\n");
        printf("5 - Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);
        getchar(); // scanf sonrası Enter'ı temizler

        if (choice == 1)
        {
            printf("\n--- Mevcut .c dosyalari ---\n");
            DIR *d = opendir(".");
            struct dirent *dir;
            while ((dir = readdir(d)) != NULL) {
                if (strstr(dir->d_name, ".c"))
                    printf("- %s\n", dir->d_name);
            }
            closedir(d);
        }

        else if (choice == 2)
        {
            printf("Okunacak dosya adini girin: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            FILE *f = fopen(filename, "r");
            if (!f) { printf("Dosya acilamadi.\n"); continue; }

            printf("\n--- %s icerigi ---\n", filename);
            while (fgets(line, sizeof(line), f))
                printf("%s", line);

            fclose(f);
        }

        else if (choice == 3)
        {
            printf("Arama yapilacak dosya adi: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            FILE *f = fopen(filename, "r");
            if (!f) { printf("Dosya acilamadi.\n"); continue; }

            printf("Aranacak kelime: ");
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = '\0';

            int lineNum = 0, found = 0;
            while (fgets(line, sizeof(line), f)) {
                lineNum++;
                if (strstr(line, search)) {
                    printf("-> %d. satir: %s", lineNum, line);
                    found = 1;
                }
            }
            if (!found) printf("Kelime bulunamadi.\n");

            fclose(f);
        }

        else if (choice == 4)
        {
            printf("Yazmak istedigin dosya adi: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            FILE *f = fopen(filename, "a"); // a = sona ekle
            if (!f) { printf("Dosya olusturulamadi.\n"); continue; }

            printf("Yazilacak metin: ");
            fgets(text, sizeof(text), stdin);

            fputs(text, f);
            fclose(f);

            printf("Metin dosyaya yazildi.\n");
        }

    } while (choice != 5);

    printf("Program bitti.\n");
    return 0;
}
