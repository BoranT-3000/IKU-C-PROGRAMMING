#include <stdio.h>

int main() {
    int sayi = 10;
    int *ptr1 = &sayi;  // ptr, sayi değişkeninin adresini tutuyor

    printf("sayi   = %d\n", sayi);
    printf("ptr1    = %p\n", ptr1);      // adres
    printf("*ptr1   = %d\n", *ptr1);     // adresin tuttuğu değer

    // Pointer ile Değer Değiştirme
    int sayi2 = 40;
    int *ptr2 = &sayi;

    *ptr2 = 99;   // sayi artık 99 olur
    printf("sayi = %d\n", sayi);


    // Pointer Arithmetic (Hafıza Adım Adım)
    int dizi[3] = {10, 20, 30};
    int *ptr3 = dizi;

    printf("%d\n", *ptr3);       // 10
    printf("%d\n", *(ptr3 + 1)); // 20
    printf("%d\n", *(ptr3 + 2)); // 30



    // Array & Pointer İlişkisi
    int dizi2[5] = {1,2,3,4,5};

    printf("%p\n", dizi2);       // dizinin adresi
    printf("%p\n", &dizi2[0]);   // aynı adres
    printf("%d\n", *(dizi2 + 2)); // 3. eleman


    // Pointer to Pointer (Çift Pointer)
    int sayi3 = 5;
    int *ptr4 = &sayi3;
    int **pptr = &ptr4;  // pointer to pointer

    // pptr: pointer’ın adresini tutan pointer
    printf("%d\n", **pptr);  // 5


    // Pointer + string (char array) ilişkisi
    char kelime[] = "hello";
    char *p = kelime;

    printf("%c\n", *p);      // h
    printf("%c\n", *(p+1));  // e


    return 0;
}
// sayi   = 10
// ptr    = 0x7ffee3b8c9ac (örnek adres)
// *ptr   = 10
// ptr bir adres tutuyor (hexa format)
// *ptr → adresteki değeri okur (=10)