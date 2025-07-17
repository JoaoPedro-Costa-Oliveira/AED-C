#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

int buscar(No* raiz, int valor) {
    if (raiz == NULL) return 0; 
    if (raiz->valor == valor) return 1;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

int main() {
    No* raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores)/sizeof(valores[0]);
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    int busca[] = {60, 25, 40};

    for (int i = 0; i < 3; i++) {
        int encontrado = buscar(raiz, busca[i]);
        printf("-----------\n");
        if (encontrado)
            printf("Valor %d encontrado na arvore.\n", busca[i]);
        else
            printf("Valor %d NAO encontrado na arvore.\n", busca[i]);
    }
    printf("-----------\n");
    return 0;
}
