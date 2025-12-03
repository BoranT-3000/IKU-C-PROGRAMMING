#include <stdio.h>

int main() {

    printf("1) \\n (newline) -> Satir atlama:\n");
    printf("Merhaba\nDunya\n\n");

    printf("2) \\t (tab) -> Sekme boslugu:\n");
    printf("Ad\tSoyad\tYas\n");
    printf("Ali\tVeli\t15\n\n");

    printf("3) \\\\ (backslash) -> Ters slash yazmak:\n");
    printf("C:\\\\Users\\\\Salim\\\\Desktop\n\n");

    printf("4) \\' (single quote) -> Tek tirnak yazmak:\n");
    printf("Bu bir \\'tek tirnak\\' ornegidir.\n\n");

    printf("5) \\\" (double quote) -> Cift tirnak yazmak:\n");
    printf("Bu bir \\\"cift tirnak\\\" ornegidir.\n\n");

    printf("6) \\b (backspace) -> Geri silme:\n");
    printf("Merhabab\b\n\n");   // sondaki b silinir → Merhaba

    printf("7) \\r (carriage return) -> Satir basina doner:\n");
    printf("Merhaba\rDunya\n\n"); // Merhaba üzerine Dunya yazar

    printf("8) \\v (vertical tab) -> Dikey tab:\n");
    printf("Ust kısım\vAlt kısım\n\n");

    printf("9) \\f (form feed) -> Yeni sayfa / bosluk etkisi:\n");
    printf("Sayfa1\fSayfa2\n\n");

    printf("10) \\? (question mark) -> Soru isareti yazmak:\n");
    printf("Bu bir soru isareti: \\?\n\n");

    printf("11) \\0 (null character) -> String sonu:\n");
    char text[] = "Hello\0World"; // \0 den sonra okunmaz
    printf("%s\n", text);

    return 0;
}
  
// 1) \n (newline) -> Satir atlama:
// Merhaba
// Dunya

// 2) \t (tab) -> Sekme boslugu:
// Ad      Soyad   Yas
// Ali     Veli    15

// 3) \\ (backslash) -> Ters slash yazmak:
// C:\\Users\\Salim\\Desktop

// 4) \' (single quote) -> Tek tirnak yazmak:
// Bu bir 'tek tirnak' ornegidir.

// 5) \" (double quote) -> Cift tirnak yazmak:
// Bu bir "cift tirnak" ornegidir.

// 6) \b (backspace) -> Geri silme:
// Merhaba

// 7) \r (carriage return) -> Satir basina doner:
// Dunya

// 8) \v (vertical tab) -> Dikey tab:
// Ust kısım
//         Alt kısım

// 9) \f (form feed) -> Yeni sayfa / bosluk etkisi:
// Sayfa1
//        Sayfa2

// 10) \? (question mark) -> Soru isareti yazmak:
// Bu bir soru isareti: ?

// 11) \0 (null karakter):
// Hello
