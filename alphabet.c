#include <stdio.h>
#include <string.h>

int main()
{
    char alphabet[] = "ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ"
                      "abcçdefgğhıijklmnoöprsştuüvyz"
                      "0123456789 .,!?*-_";

    char text[200];
    int shift;
    int alphaLen = strlen(alphabet);

    printf("Metni girin: ");
    fgets(text, sizeof(text), stdin);   // boşluklu okur

    printf("Kaydirma miktari: ");
    scanf("%d", &shift);

    // SHIFT negatifse bile çalışır
    if (shift < 0)
        shift = (shift % alphaLen + alphaLen) % alphaLen;

    for (int i = 0; text[i] != '\0'; i++)
    {
        for (int j = 0; j < alphaLen; j++)
        {
            if (text[i] == alphabet[j])
            {
                text[i] = alphabet[(j + shift) % alphaLen];
                break;
            }
        }
    }

    printf("Sifrelenmis hali: %s\n", text);
    return 0;
}
