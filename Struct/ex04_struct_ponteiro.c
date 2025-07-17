#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Carro{
    char modelo[30];
    int ano;
    float preco;   
} Carro;

int main(){
    
    Carro* carro =(Carro*)malloc(sizeof(Carro));
    printf("Modelo: ");
    scanf("%[^\n]s", carro->modelo);
    printf("Ano: ");
    scanf("%d", &carro->ano);
    printf("Preco: ");
    scanf("%f", &carro->preco);
    
    printf("Modelo: %s\n", carro->modelo);
    printf("Ano: %d\n", carro->ano);
    printf("Preco: %f\n", carro->preco);

    free(carro);

    return 0;
}