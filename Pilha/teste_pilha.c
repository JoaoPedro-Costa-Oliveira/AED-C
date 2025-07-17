#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamanho máximo da pilha

typedef struct {
    int items[MAX];
    int top;  // Índice do topo da pilha
} Stack;

// Inicializa a pilha
void initStack(Stack* s) {
    s->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Verifica se a pilha está cheia
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Empilha um elemento
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    s->items[++s->top] = value;
}

// Desempilha um elemento
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return s->items[s->top--];
}

// Mostra o topo da pilha
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return s->items[s->top];
}

// Imprime a pilha
void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s); // Saída: Pilha: 30 20 10

    printf("Desempilhando: %d\n", pop(&s)); // Remove 30
    printStack(&s); // Saída: Pilha: 20 10

    return 0;
}
