#include <stdio.h>
#include <stdlib.h>

// Definindo o nó
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Lista com head e tail (como no Python)
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Inicializa a lista
DoublyLinkedList* criarLista() {
    DoublyLinkedList* lista = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

// Adiciona no início
void add_to_front(DoublyLinkedList* lista, int value) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->value = value;
    novo->prev = NULL;
    novo->next = lista->head;

    if (lista->head == NULL) { // lista vazia
        lista->head = lista->tail = novo;
    } else {
        lista->head->prev = novo;
        lista->head = novo;
    }
}

// Adiciona no fim
void add_to_end(DoublyLinkedList* lista, int value) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->value = value;
    novo->next = NULL;
    novo->prev = lista->tail;

    if (lista->tail == NULL) { // lista vazia
        lista->head = lista->tail = novo;
    } else {
        lista->tail->next = novo;
        lista->tail = novo;
    }
}

// Remove do início
int remove_from_front(DoublyLinkedList* lista) {
    if (lista->head == NULL) {
        return -1; // lista vazia
    }

    Node* temp = lista->head;
    int valor_removido = temp->value;

    if (lista->head == lista->tail) { // só tinha 1 elemento
        lista->head = lista->tail = NULL;
    } else {
        lista->head = lista->head->next;
        lista->head->prev = NULL;
    }

    free(temp);
    return valor_removido;
}

// Remove do fim
int remove_from_end(DoublyLinkedList* lista) {
    if (lista->tail == NULL) {
        return -1; // lista vazia
    }

    Node* temp = lista->tail;
    int valor_removido = temp->value;

    if (lista->head == lista->tail) { // só tinha 1 elemento
        lista->head = lista->tail = NULL;
    } else {
        lista->tail = lista->tail->prev;
        lista->tail->next = NULL;
    }

    free(temp);
    return valor_removido;
}

// Imprimir lista
void imprimir(DoublyLinkedList* lista) {
    Node* temp = lista->head;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    DoublyLinkedList* lista = criarLista();

    add_to_front(lista, 30);
    add_to_front(lista, 20);
    add_to_front(lista, 10);
    imprimir(lista);

    add_to_end(lista, 40);
    add_to_end(lista, 50);
    imprimir(lista);

    int removido = remove_from_front(lista);
    printf("Removido do início: %d\n", removido);
    imprimir(lista);

    removido = remove_from_end(lista);
    printf("Removido do fim: %d\n", removido);
    imprimir(lista);

    return 0;
}
