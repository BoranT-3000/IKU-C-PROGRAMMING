#include <stdio.h>

union Oyuncak {
    int araba;
    float top;
    char ayicik;
};

// Bir oyuncak kutusu düşün.

// Bu kutunun içine ya bir araba, 
// ya bir top, ya da bir oyuncak ayı koyabiliyoruz.
// Ama aynı anda sadece BİR tanesi!

// İşte C’deki union, böyle bir kutudur. 
// İçine birden fazla tür tanımlayabilirsin ama 
// aynı anda sadece birini saklayabilirsin.

int main() {
    union Oyuncak kutu;

    // Kutunun içine araba koyduk
    kutu.araba = 10;
    printf("Kutuda araba var: %d\n", kutu.araba);

    // Şimdi de top koyuyoruz
    kutu.top = 3.14;
    printf("Kutuda top var: %.2f\n", kutu.top);

    // En son ayıcık koyduk
    kutu.ayicik = 'A';
    printf("Kutuda ayicik var: %c\n", kutu.ayicik);

    // Eski değerler bozuldu!
    printf("\nNOT: Union'da en son ne koyarsan diğerleri bozulur.\n");

    return 0;
}
