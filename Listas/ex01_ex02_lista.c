#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dado;
    struct Node* prox;
};

void inserir_inicio(struct Node** inicio, int valor) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->prox = *inicio;
    *inicio = novo;
}

void inserir_fim(struct Node** inicio, int valor) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    struct Node* temp = *inicio;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
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

int contar_elementos(struct Node* inicio) {
    int contador = 0;
    while (inicio != NULL) {
        contador++;
        inicio = inicio->prox;
    }
    return contador;
}



void exibir(struct Node* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

int main() {
    struct Node* lista = NULL;

    inserir_inicio(&lista, 10);   
    inserir_inicio(&lista, 20);   
    inserir_fim(&lista, 30);      
    inserir_fim(&lista, 40);      

    exibir(lista);

    remover(&lista, 10);          
    exibir(lista);

    remover(&lista, 99);

    return 0;
}
