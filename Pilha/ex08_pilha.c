#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int bit;
    struct Pilha* prox;
} Pilha;


Pilha* push(Pilha* topo, int bit) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->bit = bit;
    novo->prox = topo;
    return novo;
}

void imprimir_binario(Pilha* topo) {
    Pilha* temp;
    while (topo != NULL) {
        printf("%d", topo->bit);
        temp = topo;
        topo = topo->prox;
        free(temp);
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("0\n");
        return 0;
    }

    Pilha* topo = NULL;

    while (numero > 0) {
        int resto = numero % 2;
        topo = push(topo, resto);
        numero = numero / 2;
    }

    printf("Binario: ");
    imprimir_binario(topo);

    return 0;
}
