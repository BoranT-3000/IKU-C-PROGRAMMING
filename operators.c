#include <stdio.h>

struct Person {
    int age;
};

int main() {

    printf("=== 1. ARITMETIK OPERATÖRLER: + - * / %% ===\n");
    int a = 10, b = 3;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);      // tam sayı bölme
    printf("a %% b = %d\n\n", a % b);   // kalan alma


    printf("=== 2. ARTIRMA / AZALTMA: ++  -- ===\n");
    int x = 5;
    printf("x = %d\n", x);
    printf("++x = %d\n", ++x);   // önce arttır, sonra kullan
    printf("x++ = %d\n", x++);   // önce kullan, sonra artır
    printf("x (son durum) = %d\n\n", x);


    printf("=== 3. ATAMA OPERATÖRLERI: = += -= *= /= %%= ===\n");
    int c = 10;
    c += 5;  // c = 15
    c -= 3;  // c = 12
    c *= 2;  // c = 24
    c /= 4;  // c = 6
    c %= 4;  // c = 2
    printf("c (son durum) = %d\n\n", c);


    printf("=== 4. KARŞILAŞTIRMA OPERATÖRLERI: == != > < >= <= ===\n");
    int p = 7, q = 10;
    printf("p == q: %d\n", p == q);
    printf("p != q: %d\n", p != q);
    printf("p >  q: %d\n", p > q);
    printf("p <  q: %d\n", p < q);
    printf("p >= q: %d\n", p >= q);
    printf("p <= q: %d\n\n", p <= q);


    printf("=== 5. MANTIKSAL OPERATÖRLER: &&  ||  ! ===\n");
    printf("(p < q) && (q > 5): %d\n", (p < q) && (q > 5));
    printf("(p > q) || (q > 5): %d\n", (p > q) || (q > 5));
    printf("!(p == q): %d\n\n", !(p == q));


    printf("=== 6. BIT DUZEYI OPERATÖRLER: & | ^ ~ << >> ===\n");
    int m = 6;  // 110
    int n = 3;  // 011
    printf("m & n  = %d\n", m & n);   // 010 (2)
    printf("m | n  = %d\n", m | n);   // 111 (7)
    printf("m ^ n  = %d\n", m ^ n);   // 101 (5)
    printf("~m     = %d\n", ~m);      // bitleri ters çevirir
    printf("m << 1 = %d\n", m << 1);  // sola kaydır
    printf("m >> 1 = %d\n\n", m >> 1); // sağa kaydır


    printf("=== 7. BOYUT OPERATÖRÜ: sizeof() ===\n");
    printf("sizeof(int)   = %zu byte\n", sizeof(int));
    printf("sizeof(char)  = %zu byte\n", sizeof(char));
    printf("sizeof(double)= %zu byte\n\n", sizeof(double));


    printf("=== 8. KOŞUL (TERNARY) OPERATÖRÜ: ? : ===\n");
    int y = (a > b) ? a : b;
    printf("Buyuk olan: %d\n\n", y);


    printf("=== 9. VIRGUL OPERATÖRÜ: , ===\n");
    int t, u = 5, v = (t = 3, t + u);
    printf("v = %d\n\n", v);


    printf("=== 10. POINTER OPERATÖRLERI: &  * ===\n");
    int num = 40;
    int *ptr = &num;      // adresini tut
    printf("num   = %d\n", num);
    printf("&num  = %p\n", (void*)&num);
    printf("*ptr  = %d\n\n", *ptr);   // ptr'nin gösterdiği değeri yazdır


    printf("=== 11. STRUCT ERISIM OPERATÖRLERI: .  -> ===\n");
    struct Person p1;
    p1.age = 20;
    struct Person *p2 = &p1;
    printf("p1.age  = %d\n", p1.age);
    printf("p2->age = %d\n\n", p2->age);

    return 0;
}

// gcc operators.c -o operators
// ./operators