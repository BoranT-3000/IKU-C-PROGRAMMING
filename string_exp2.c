#include <stdio.h>
#include <string.h>

int main() {

    // ----------------------------------------------------
    // 1) CHAR ARRAY (string temeli)
    // ----------------------------------------------------
    char isim1[20] = "Ali";    // değiştirilebilir
    char isim2[] = "Veli";     // boyut otomatik

    printf("1) Char Array Ornekleri:\n");
    printf("isim1 = %s\n", isim1);
    printf("isim2 = %s\n\n", isim2);


    // ----------------------------------------------------
    // 2) STRING INPUT (kullanıcıdan alma)
    // ----------------------------------------------------
    char giris[50];
    printf("2) Bir kelime gir: ");
    fgets(giris, sizeof(giris), stdin);

    // sondaki \n temizle
    giris[strcspn(giris, "\n")] = '\0';

    printf("Girdigin kelime: %s\n\n", giris);


    // ----------------------------------------------------
    // 3) Temel STRING Fonksiyonları
    // ----------------------------------------------------

    // strlen  → uzunluk ölçme
    printf("3) String Fonksiyonlari:\n");
    printf("strlen(\"Ali\") = %lu\n", strlen("Ali"));

    // strcpy → kopyalama
    char kopya[20];
    strcpy(kopya, giris);
    printf("strcpy ile kopya: %s\n", kopya);

    // strcmp → karşılaştırma
    printf("strcmp(\"Ali\", \"Ali\") = %d (0 = esit)\n", strcmp("Ali", "Ali"));
    printf("strcmp(\"Ali\", \"Veli\") = %d\n", strcmp("Ali", "Veli"));

    // strcat → birleştirme
    char mesaj[50] = "Merhaba ";
    strcat(mesaj, isim1);   // "Merhaba Ali"
    printf("strcat sonucu: %s\n\n", mesaj);


    // ----------------------------------------------------
    // 4) Küçük Uygulama: Kelimeyi ters çevirme
    // ----------------------------------------------------
    printf("4) Kelimeyi Ters Cevirme:\n");

    int i = 0;
    int j = strlen(giris) - 1;

    while (i < j) {
        char temp = giris[i];
        giris[i] = giris[j];
        giris[j] = temp;
        i++;
        j--;
    }

    printf("Ters cevrilmis: %s\n", giris);

    return 0;
}
