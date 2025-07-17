#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dado;
    struct Node* prox;
};

void inserir_ordenado(struct Node** inicio, int valor) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->prox = NULL;

    if (*inicio == NULL || (*inicio)->dado >= valor) {
        novo->prox = *inicio;
        *inicio = novo;
    } else {
        struct Node* atual = *inicio;
        while (atual->prox != NULL && atual->prox->dado < valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

void remover(struct Node** inicio, int valor) {
    struct Node* temp = *inicio;
    struct Node* anterior = NULL;

    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) {
        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *inicio = temp->prox;
    } else {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("Valor %d removido com sucesso.\n", valor);
}

void exibir(struct Node* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

void reverter_lista(struct Node** inicio) {
    struct Node* anterior = NULL;
    struct Node* atual = *inicio;
    struct Node* prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }

    *inicio = anterior;
}

int main() {
    struct Node* lista = NULL;

    inserir_ordenado(&lista, 30);
    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 50);
    inserir_ordenado(&lista, 20);
    inserir_ordenado(&lista, 40);

    exibir(lista);  

    remover(&lista, 30);
    exibir(lista);  

    printf("Revertendo a lista...\n");
    reverter_lista(&lista);
    exibir(lista);  

    return 0;
}
