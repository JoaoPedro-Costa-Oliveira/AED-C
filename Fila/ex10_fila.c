#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void inicializar(FilaCircular *fila, int capacidade) {
    fila->capacidade = capacidade;
    fila->dados = (int *)malloc(capacidade * sizeof(int));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

int isEmpty(FilaCircular *fila) {
    return fila->tamanho == 0;
}

int isFull(FilaCircular *fila) {
    return fila->tamanho == fila->capacidade;
}

void enqueue(FilaCircular *fila, int valor) {
    if (isFull(fila)) {
        printf("Fila cheia. Não é possível enfileirar %d.\n", valor);
        return;
    }

    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int dequeue(FilaCircular *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia. Nada para remover.\n");
        return -1;
    }

    int valor = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}

void imprimirFila(FilaCircular *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    int i = fila->inicio;
    for (int cont = 0; cont < fila->tamanho; cont++) {
        printf("%d ", fila->dados[i]);
        i = (i + 1) % fila->capacidade;
    }
    printf("\n");
}

void liberarFila(FilaCircular *fila) {
    free(fila->dados);
}

int main() {
    FilaCircular fila;
    inicializar(&fila, 5);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    imprimirFila(&fila);

    dequeue(&fila);
    imprimirFila(&fila);

    enqueue(&fila, 40);
    enqueue(&fila, 50);
    enqueue(&fila, 60); 
    imprimirFila(&fila);

    dequeue(&fila);
    enqueue(&fila, 70);
    imprimirFila(&fila);

    dequeue(&fila);
    dequeue(&fila);
    dequeue(&fila);
    imprimirFila(&fila);


    liberarFila(&fila);
    return 0;
}
