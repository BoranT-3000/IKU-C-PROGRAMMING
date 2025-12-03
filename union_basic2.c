#include <stdio.h>

struct S {
    int a;
    float b;
    char c;
};

union U {
    int a;
    float b;
    char c;
};

int main() {
    struct S s;
    union U u;

    // STRUCT: tüm üyeleri aynı anda tutulabilir
    s.a = 10;
    s.b = 3.14;
    s.c = 'X';

    printf("STRUCT:\n");
    printf("s.a = %d\n", s.a);
    printf("s.b = %.2f\n", s.b);
    printf("s.c = %c\n\n", s.c);


    // UNION: en son hangisi yazılırsa o değer kalır
    u.a = 10;          // 4 byte
    printf("UNION (a yazdıktan sonra): u.a = %d\n", u.a);

    u.b = 3.14;        // float yazınca integer bozulur
    printf("UNION (b yazdıktan sonra): u.b = %.2f\n", u.b);
    printf("u.a'nin durumu (artık bozuk): %d\n\n", u.a);

    u.c = 'X';         // char yazınca float/int bozulur
    printf("UNION (c yazdıktan sonra): u.c = %c\n", u.c);
    printf("u.b'nin durumu (bozulmuş): %f\n", u.b);

    return 0;
}
