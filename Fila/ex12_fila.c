#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila {
    char nome[50];
    struct Fila* prox;
} Fila;

typedef struct Pilha {
    char nome[50];
    struct Pilha* prox;
} Pilha;

Fila* enfileirar(Fila* fila, char nome[]) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (!fila) return novo;

    Fila* temp = fila;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;

    return fila;
}

Fila* desenfileirar(Fila* fila, char nome[]) {
    if (!fila) return NULL;

    Fila* temp = fila;
    strcpy(nome, temp->nome);
    fila = fila->prox;
    free(temp);
    return fila;
}

Pilha* empilhar(Pilha* topo, char nome[]) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    strcpy(novo->nome, nome);
    novo->prox = topo;
    return novo;
}

Pilha* desempilhar(Pilha* topo, char nome[]) {
    if (!topo) return NULL;

    Pilha* temp = topo;
    strcpy(nome, temp->nome);
    topo = topo->prox;
    free(temp);
    return topo;
}

void imprimirFila(Fila* fila) {
    Fila* temp = fila;
    printf("Fila: ");
    while (temp) {
        printf("%s -> ", temp->nome);
        temp = temp->prox;
    }
    printf("NULL\n");
}

Fila* inverterFila(Fila* fila) {
    Pilha* pilha = NULL;
    char nome[50];

    while (fila != NULL) {
        fila = desenfileirar(fila, nome);
        pilha = empilhar(pilha, nome);
    }

    while (pilha != NULL) {
        pilha = desempilhar(pilha, nome);
        fila = enfileirar(fila, nome);
    }

    return fila;
}

int main() {
    Fila* fila = NULL;

    fila = enfileirar(fila, "Joao");
    fila = enfileirar(fila, "Maria");
    fila = enfileirar(fila, "Carlos");

    printf("Antes da inversao:\n");
    imprimirFila(fila);

    fila = inverterFila(fila);

    printf("Depois da inversao:\n");
    imprimirFila(fila);

    return 0;
}
