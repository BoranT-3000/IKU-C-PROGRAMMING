#include <stdio.h> 
#include <string.h> 

int main() 
{ 
    FILE *file = fopen("data.txt", "r"); 
    char search[50]; 
    char line[256]; 
    int lineNum = 0; 
    
    printf("Aranacak kelime: "); 
    scanf("%s", search); 

    while (fgets(line, sizeof(line), file)) { 
        lineNum++; 
        if (strstr(line, search)) { 
            printf("%d. satirda bulundu.\n", lineNum); 
        } 
    } 
    fclose(file); 
    return 0; 
}


