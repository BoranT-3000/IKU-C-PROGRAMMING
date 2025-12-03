#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// =======================================================
//                 GLOBAL DEĞİŞKENLER
// =======================================================

int    globalInt    = 42;
float  globalFloat  = 1.23f;
double globalDouble = 9.876;
char   globalChar   = 'A';
bool   globalBool   = true;
char   globalString[] = "Hello from Global!";


// =======================================================
//               FONKSİYON PROTOTİPLERİ
// =======================================================

// Basit fonksiyon
void selam();

// INT fonksiyonları
int topla(int a, int b);
void arttirInt(int *x);
void yazdirInt(int dizi[], int n);

// FLOAT fonksiyonları
float averageFloat(float dizi[], int n);
void yazdirFloat(float dizi[], int n);

// DOUBLE fonksiyonları
double maxDouble(double dizi[], int n);
void yazdirDouble(double dizi[], int n);

// CHAR fonksiyonları
char buyukHarfYap(char c);
void yazdirCharArray(char dizi[], int n);

// BOOL fonksiyonları
void yazdirBoolArray(bool dizi[], int n);
bool anyTrue(bool dizi[], int n);

// STRING fonksiyonları
void yazdirString(const char *str);
int stringLength(const char *str);
void stringUpper(char *str);

// Global – Local gösterimi
void globalLocalGoster(int localX);

// Rekürsif
int faktoriyel(int n);


// =======================================================
//                       MAIN
// =======================================================

int main() {

    selam();

    // --------------------------------------------------
    // INT FONKSİYONLAR
    printf("\nToplam (3 + 7): %d\n", topla(3, 7));

    int x = 10;
    arttirInt(&x);
    printf("Arttirilmis int: %d\n", x);

    int idizi[5] = {5, 2, 7, 1, 9};
    printf("\nInt Dizi: ");
    yazdirInt(idizi, 5);


    // --------------------------------------------------
    // FLOAT FONKSİYONLAR
    float fdizi[4] = {1.2, 2.4, 3.6, 4.8};
    printf("\nFloat Dizi: ");
    yazdirFloat(fdizi, 4);
    printf("Float Ortalama: %.2f\n", averageFloat(fdizi, 4));


    // --------------------------------------------------
    // DOUBLE FONKSİYONLAR
    double ddizi[4] = {2.5, 9.1, 4.4, 8.8};
    printf("\nDouble Dizi: ");
    yazdirDouble(ddizi, 4);
    printf("En buyuk double: %.2lf\n", maxDouble(ddizi, 4));


    // --------------------------------------------------
    // CHAR FONKSİYONLAR
    char kelime[] = "hello";
    printf("\nKelime (orijinal): %s\n", kelime);
    stringUpper(kelime);
    printf("Kelime (BUYUK): %s\n", kelime);


    char harf = 'b';
    printf("'%c' -> '%c'\n", harf, buyukHarfYap(harf));

    char cdizi[] = {'A','l','i','\0'};
    printf("Char array: ");
    yazdirCharArray(cdizi, 3);


    // --------------------------------------------------
    // BOOL FONKSİYONLAR
    bool bdizi[5] = {true, false, true, false, false};
    printf("\nBool array: ");
    yazdirBoolArray(bdizi, 5);

    printf("Any true? %s\n", anyTrue(bdizi, 5) ? "YES" : "NO");


    // --------------------------------------------------
    // STRING FONKSİYONLAR
    const char *mesaj = "Pointer string!";
    printf("\nString yaz: ");
    yazdirString(mesaj);

    printf("String uzunlugu: %d\n", stringLength(mesaj));


    // --------------------------------------------------
    // GLOBAL – LOCAL
    int localVar = 999;
    globalLocalGoster(localVar);


    // --------------------------------------------------
    // REKÜRSİF
    printf("\nFaktoriyel 6 = %d\n", faktoriyel(6));

    return 0;
}



// =======================================================
//               FONKSİYON TANIMLARI
// =======================================================

void selam() {
    printf("Fonksiyon dersine hos geldiniz!\n");
}


// ------------------------ INT --------------------------

int topla(int a, int b) {
    return a + b;
}

void arttirInt(int *x) {
    (*x)++;
}

void yazdirInt(int dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", dizi[i]);
    printf("\n");
}


// ------------------------ FLOAT ------------------------

float averageFloat(float dizi[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += dizi[i];
    return sum / n;
}

void yazdirFloat(float dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", dizi[i]);
    printf("\n");
}


// ------------------------ DOUBLE -----------------------

double maxDouble(double dizi[], int n) {
    double m = dizi[0];
    for (int i = 1; i < n; i++)
        if (dizi[i] > m) m = dizi[i];
    return m;
}

void yazdirDouble(double dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2lf ", dizi[i]);
    printf("\n");
}


// ------------------------ CHAR -------------------------

char buyukHarfYap(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;  
    return c;
}

void yazdirCharArray(char dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c", dizi[i]);
    printf("\n");
}


// ------------------------ BOOL -------------------------

void yazdirBoolArray(bool dizi[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s ", dizi[i] ? "true" : "false");
    printf("\n");
}

bool anyTrue(bool dizi[], int n) {
    for (int i = 0; i < n; i++)
        if (dizi[i]) return true;
    return false;
}


// ------------------------ STRING -----------------------

void yazdirString(const char *str) {
    printf("%s\n", str);
}

int stringLength(const char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

void stringUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}


// ------------------------ GLOBAL – LOCAL ----------------

void globalLocalGoster(int localX) {
    printf("\n--- Global & Local ---\n");
    printf("Global int   : %d\n", globalInt);
    printf("Local  int   : %d\n", localX);
    printf("Global float : %.2f\n", globalFloat);
    printf("Global double: %.3lf\n", globalDouble);
    printf("Global char  : %c\n", globalChar);
    printf("Global bool  : %s\n", globalBool ? "true" : "false");
    printf("Global string: %s\n", globalString);
}


// ------------------------ RECURSIVE ----------------------

int faktoriyel(int n) {
    if (n <= 1) return 1;
    return n * faktoriyel(n - 1);
}
