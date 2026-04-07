#include <stdio.h>
#include <stdlib.h>


FILE * openFile(char path[]){
    FILE *file;

    file = fopen(path, "r");

    if(file == NULL){
        printf("Não foi possível abrir o arquivo!");
        exit(1);
    }

    return file;
}

int main() {

    FILE *file = openFile("compra.txt");

    char str[100];
    char c;

    // Le linha por linha de todo o arquivo
    // while(fgets(str, 100, file)){
    //     printf("%s", str);
    // }

    // Le caracter por caracter de todo o arquivo
    // while ((c = fgetc(file)) != EOF)
    // {
    //     printf("%c", c);
    // }

    
    


    fclose(file);
}