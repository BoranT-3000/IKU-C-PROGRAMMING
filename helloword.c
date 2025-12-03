#include <stdio.h> 

int main() 
{ 
    char text[100]; 
    int shift; 

    printf("Metin girin: "); 
    // scanf("%s", text);
    fgets(text, sizeof(text), stdin); // <-- tüm satırı okur (boşluk dahil) 

    printf("Kaydirma miktari: "); 
    scanf("%d", &shift); 
    
    for (int i = 0; text[i] != '\0'; i++) 
    { 
        text[i] = text[i] + shift; 
    } 

    printf("Sifrelenmis hali: %s\n", text); 
    return 0; 
}