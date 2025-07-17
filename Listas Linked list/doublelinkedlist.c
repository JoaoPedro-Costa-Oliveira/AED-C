#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

No* inserirInicio(No* head, int valor) {
    No* novo = criarNo(valor);
    novo->prox = head;
    if (head != NULL)
        head->ant = novo;
    return novo;  // novo vira o novo head
}

No* inserirFim(No* head, int valor) {
    No* novo = criarNo(valor);
    if (head == NULL)
        return novo;
    
    No* temp = head;
    while (temp->prox != NULL)
        temp = temp->prox;
    
    temp->prox = novo;
    novo->ant = temp;
    return head;
}

No* remover(No* head, int valor) {
    No* temp = head;
    while (temp != NULL && temp->valor != valor)
        temp = temp->prox;

    if (temp == NULL)
        return head;  // não achou

    if (temp->ant != NULL)
        temp->ant->prox = temp->prox;
    else
        head = temp->prox;  // estava na cabeça

    if (temp->prox != NULL)
        temp->prox->ant = temp->ant;

    free(temp);
    return head;
}

void imprimir(No* head) {
    No* temp = head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void imprimirReverso(No* head) {
    No* temp = head;
    if (temp == NULL) return;
    while (temp->prox != NULL)
        temp = temp->prox;

    printf("Lista reversa: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->valor);
        temp = temp->ant;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    // Inserção no início
    lista = inserirInicio(lista, 30);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 10);
    imprimir(lista);

    // Inserção no final
    lista = inserirFim(lista, 40);
    lista = inserirFim(lista, 50);
    imprimir(lista);

    // Remover um elemento
    lista = remover(lista, 20);
    imprimir(lista);

    // Imprimir reverso
    imprimirReverso(lista);

    return 0;
}
