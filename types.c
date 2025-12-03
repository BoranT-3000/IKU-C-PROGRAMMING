// types.c 
#include <stdio.h>

/* This program takes age input from the user
It stores it in the age variable
And, print the value using printf() */
int main() {

    // create integer variable    
    int age = 25; 
    
    // print the age variable
    printf("Age: %d", age);



    // chars 
    //A character literal is created by enclosing a single character 
    // inside single quotation marks. 
    char ch = 'a';
    printf("harf: %c\n", ch);

    // değişebiliyor uuu
    ch = 'l';
    printf("degisen harf: %c\n", ch);


    // sabitler 
    const double PI = 3.14;
    printf("PI sayisi: %.2f\n", PI);

    // PI değiştirilemez
    PI = 2.9; // hata verir
    printf("degisen PI sayisi: %.2f\n", PI);


    // A string literal is a sequence of characters 
    // enclosed in double-quote marks. 

    int yas = 12;
    float notOrt = 87.5f;
    char ilkHarf = 'A';
    char isim[20] = "Salim";

    printf("Isim: %s, Yas: %d, Not ort: %.1f, Ilk harf: %c\n", isim, yas, notOrt, ilkHarf);
    return 0;
}



// #include <stdio.h>
// #include <limits.h>   // min/max değerler
// #include <float.h>    // float ve double sınırları

// int main() {

//     printf("=== BASIC DATA TYPES ===\n\n");

//     // int (tamsayı)
//     // çoğu sistemde 4 byte yer kaplar
//     // signed int aralığı: INT_MIN ile INT_MAX arasında
//     int age = 25;
//     printf("int age = %d | size = %zu byte | range = %d to %d\n",
//            age, sizeof(int), INT_MIN, INT_MAX);

//     // char (tek karakter)
//     // bellekte 1 byte yer kaplar
//     char ch = 'A';
//     printf("char ch = %c | size = %zu byte\n", ch, sizeof(char));

//     // float (ondalıklı – yaklaşık 7 basamak doğruluk)
//     float price = 12.5f;
//     printf("float price = %f | size = %zu byte | range = %.3e to %.3e\n",
//            price, sizeof(float), FLT_MIN, FLT_MAX);

//     // double (float'tan daha hassas – yaklaşık 15 basamak doğruluk)
//     double pi = 3.1415926535;
//     printf("double pi = %lf | size = %zu byte | range = %.3e to %.3e\n",
//            pi, sizeof(double), DBL_MIN, DBL_MAX);

//     // short int (daha küçük tamsayı, az yer kaplar)
//     short int smallNumber = 32000;
//     printf("short int smallNumber = %hd | size = %zu byte | range = %d to %d\n",
//            smallNumber, sizeof(short int), SHRT_MIN, SHRT_MAX);

//     // unsigned int (sadece pozitif tamsayılar, negatif yok)
//     unsigned int studentCount = 240;
//     printf("unsigned int studentCount = %u | size = %zu byte | range = 0 to %u\n",
//            studentCount, sizeof(unsigned int), UINT_MAX);

//     // long int (int'ten daha geniş aralık)
//     long int bigNum = 9876543210;
//     printf("long int bigNum = %ld | size = %zu byte | range = %ld to %ld\n",
//            bigNum, sizeof(long int), LONG_MIN, LONG_MAX);

//     // long long int (çok büyük sayılar için)
//     long long int population = 7900000000;
//     printf("long long int population = %lld | size = %zu byte | range = %lld to %lld\n",
//            population, sizeof(long long int), LLONG_MIN, LLONG_MAX);

//     // signed char
//     // signed char aralığı: -128 ile +127
//     signed char signedCh = -10;
//     printf("signed char signedCh = %d | size = %zu byte | range: %d to %d\n",
//            signedCh, sizeof(signed char), SCHAR_MIN, SCHAR_MAX);

//     // unsigned char
//     // unsigned char aralığı: 0 ile 255
//     unsigned char unCh = 200;
//     printf("unsigned char unCh = %c (%u) | size = %zu byte | range = 0 to %u\n",
//            unCh, unCh, sizeof(unsigned char), UCHAR_MAX);

//     // long double (yüksek hassasiyetli sayı)
//     long double longPi = 3.14159265358979323846L;
//     printf("long double longPi = %Lf | size = %zu byte | range = %.3Le to %.3Le\n",
//            longPi, sizeof(long double), LDBL_MIN, LDBL_MAX);

//     // const değişken — değiştirilmez
//     const double KATSAYI = 2.17;
//     printf("\nconst double KATSAYI = %.2f\n", KATSAYI);
//     // KATSAYI = 5.0;  // hata: const değişken değiştirilemez

//     // karakter dizisi (string)
//     char name[20] = "Salim";
//     printf("char name[20] = %s | size (array) = %zu byte (max kapasite)\n",
//            name, sizeof(name));

//     return 0;
// }
