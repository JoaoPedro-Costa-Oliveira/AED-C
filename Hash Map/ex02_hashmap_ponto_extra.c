#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct No {
    int chave;
    struct No* prox;
} No;

No* tabelaHash[TAM];

void inicializarTabela() {
    for (int i = 0; i < TAM; i++) {
        tabelaHash[i] = NULL;
    }
}

int hash(int chave) {
    return chave % TAM;
}

void inserir(int chave) {
    int indice = hash(chave);
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->prox = tabelaHash[indice];
    tabelaHash[indice] = novo;
}

No* buscar(int chave) {
    int indice = hash(chave);
    No* atual = tabelaHash[indice];
    while (atual != NULL) {
        if (atual->chave == chave)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void imprimirTabela() {
    for (int i = 0; i < TAM; i++) {
        printf("[%d]: ", i);
        No* atual = tabelaHash[i];
        while (atual) {
            printf("%d -> ", atual->chave);
            atual = atual->prox;
        }
        printf("NULL\n");
    }
}

int main() {
    inicializarTabela();

    inserir(12);
    inserir(22);
    inserir(32);
    inserir(42);
    inserir(15);

    imprimirTabela();

    int chaveBusca = 22;
    No* resultado = buscar(chaveBusca);

    if (resultado)
        printf("Elemento %d encontrado na tabela hash.\n", resultado->chave);
    else
        printf("Elemento nao encontrado na tabela hash.\n");

    return 0;
}
