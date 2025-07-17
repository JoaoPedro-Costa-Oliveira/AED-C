#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char nome[50];
    struct Cliente* prox;
} Cliente;

Cliente* adicionarCliente(Cliente* fila, char nome[]) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    if (!novo) return fila;

    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (!fila) return novo;

    Cliente* temp = fila;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;

    return fila;
}

Cliente* atenderCliente(Cliente* fila) {
    if (!fila) {
        printf("Nenhum cliente na fila!\n");
        return NULL;
    }

    Cliente* temp = fila;
    printf("Atendendo cliente: %s\n", temp->nome);
    fila = fila->prox;
    free(temp);

    return fila;
}

void exibirFila(Cliente* fila) {
    if (!fila) {
        printf("Fila vazia.\n");
        return;
    }

    Cliente* temp = fila;
    printf("Fila atual: ");
    while (temp != NULL) {
        printf("%s -> ", temp->nome);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int main() {
    Cliente* fila = NULL;

    fila = adicionarCliente(fila, "Joao");
    fila = adicionarCliente(fila, "Maria");
    fila = adicionarCliente(fila, "Carlos");

    exibirFila(fila);

    fila = atenderCliente(fila);
    exibirFila(fila);

    fila = atenderCliente(fila);
    exibirFila(fila);

    fila = adicionarCliente(fila, "Ana");
    exibirFila(fila);

    fila = atenderCliente(fila);
    fila = atenderCliente(fila);
    exibirFila(fila);

    return 0;
}
