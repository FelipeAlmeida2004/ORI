#include <stdlib.h>
#include <stdio.h>


FILE * openFile(char path[]){
    FILE *file;

    file = fopen(path, "rb");

    if(file == NULL){
        printf("Não foi possível abrir o arquivo!");
        exit(1);
    }

    return file;
}

int main() {
    FILE *file = openFile("compras.bin");

    unsigned char line_len = 0;
    char line_data[200];

    int i;
    int count_pipe = 0;
    float sum = 0.0;


    while (fread(&line_len, sizeof(unsigned char), 1, file) == 1) {
        if (fread(line_data, sizeof(char), line_len, file) == line_len) {
            line_data[line_len] = '\0';
            
            // Conta pipes na linha
            count_pipe = 0;
            for (i = 0; i < line_len; i++) {
                if (line_data[i] == '|') {
                    count_pipe++;
                }

                if (count_pipe == 2){
                    printf("%s", line_data[i]);
                    count_pipe = 0;
                }
            }
            
            printf("Tamanho: %u | Pipes: %d | Conteúdo: %s | Soma: %f \n", line_len, count_pipe, line_data);
            
        } else {
            printf("Erro ao ler conteúdo da linha\n");
            break;
        }
    }

    fclose(file);
    return 0;
}
