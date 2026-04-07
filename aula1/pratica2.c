#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("notas.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    char name[100];
    char nome_maior[100];
    float media, soma, nota, maior = 0.0;
    int count = 1;


    while (fscanf(file, "NOME: %99s NOTA: %f", name, &nota) == 2)
    {
        soma += nota;
        count++;

        if(nota > maior) {
            maior = nota;
            snprintf(nome_maior, sizeof(nome_maior), "%s", name);
        }
    }

    if (count > 0) {
        media = soma / (float)count;
    }

    printf("Media: %.2f\n", media);
    printf("Maior nota: %s %.2f\n", nome_maior, maior);

    fclose(file);

    return 0;
}