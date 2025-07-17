#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *dados;
    int inicio;
    int fim;
    int capacidade;
} Fila;

void inicializar(Fila *f, int tamanho) {
    f->dados = (int *)malloc(tamanho * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->capacidade = tamanho;
}

bool isEmpty(Fila *f) {
    return f->inicio == f->fim;
}

bool isFull(Fila *f) {
    return f->fim == f->capacidade;
}

void enqueue(Fila *f, int valor) {
    if (!isFull(f)) {
        f->dados[f->fim++] = valor;
        printf("Enfileirado: %d\n", valor);
    } else {
        printf("Fila cheia!\n");
    }
}

void dequeue(Fila *f) {
    if (!isEmpty(f)) {
        printf("Desenfileirado: %d\n", f->dados[f->inicio]);
        f->inicio++;
    } else {
        printf("Fila vazia!\n");
    }
}

void front(Fila *f) {
    if (!isEmpty(f)) {
        printf("Frente da fila: %d\n", f->dados[f->inicio]);
    } else {
        printf("Fila vazia!\n");
    }
}

void liberar(Fila *f) {
    free(f->dados);
}

int main() {
    Fila fila;
    int tamanho = 5;
    inicializar(&fila, tamanho);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    front(&fila);       
    dequeue(&fila);     
    front(&fila);       

    dequeue(&fila);     
    dequeue(&fila);     
    dequeue(&fila);     

    liberar(&fila);     
    return 0;
}

