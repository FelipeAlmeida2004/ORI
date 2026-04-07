#include <stdio.h>


int main() {

    // Open File
    FILE *file;

    file = fopen("compra.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read File and set variables
    char name[100];
    int qnt;
    float price;
    float total = 0.0;

    while (fscanf(file, "%99s %d %f", name, &qnt, &price) == 3) {
        total += qnt * price;
        
        printf("qnt: %d\n", qnt);
        printf("price: %.2f\n", price);
    }

    
    fclose(file);
    
    printf("Total: %.2f\n", total);
    return 0;
}