#include <stdio.h>

int main() {

    // ---------- OUTPUT (Çıktı) ----------
    printf("=== OUTPUT ===\n");

    // printf -> formatlı çıktı
    int yas = 18;
    printf("printf ornek -- Yas: %d\n", yas);

    // putchar -> tek karakter yazdırır
    putchar('A');
    putchar('\n');   // yeni satır

    // puts -> string yazdırır, otomatik yeni satır ekler
    puts("puts ornegi (otomatik new line ekler)");



    // ---------- INPUT (Girdi) ----------
    printf("\n=== INPUT ===\n");

    // scanf -> boşlukta keser (sadece ilk kelimeyi alır)
    char ad[20];
    printf("Adinizi girin (scanf): ");
    scanf("%s", ad);
    printf("scanf sonucu: %s\n", ad);

    // buffer temizleme -- scanf sonrası ENTER klavyede kalır
    getchar(); // buffer'daki '\n' karakterini temiz (önemli)



    // fgets -> boşluk dahil tüm satırı okur
    char isimTam[50];
    printf("\nTam isminizi girin (fgets): ");
    fgets(isimTam, sizeof(isimTam), stdin); // tüm satırı okur (boşluk dahil)
    printf("fgets sonucu: %s\n", isimTam);



    // getchar -> tek karakter okuma
    printf("Bir karakter girin (getchar): ");
    char karakter = getchar();
    printf("getchar sonucu: %c\n", karakter);



    // putchar -> tek karakter yazdırma
    printf("putchar ile yazilmis hali: ");
    putchar(karakter);
    putchar('\n');



    // gets (KULLANILMAZ - güvenlik açığı)
    // sadece ders için GÖSTER, kullanmayın.
    // char text[50];
    // gets(text); -> TEHLİKELİ
    // printf("%s", text);



    // ---------- SAYI OKUMA ----------
    printf("\n=== SAYI OKUMA ===\n");

    int sayi;
    printf("Bir sayi girin (scanf): ");
    scanf("%d", &sayi); // sayı alırken değişkenin başına &
    printf("Girdiginiz sayi: %d\n", sayi);



    // ---------- FORMATTING (format specifier) ----------
    printf("\n=== FORMAT SPECIFIERS ===\n");
    printf("int: %d\n", 42);
    printf("float: %.2f\n", 3.14159);
    printf("char: %c\n", 'B');
    printf("string: %s\n", "Hello");



    printf("\nProgram bitti.\n");
    return 0;
}
