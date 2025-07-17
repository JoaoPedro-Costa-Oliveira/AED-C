#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    char dado;
    struct Pilha* prox;
} Pilha;

Pilha* push(Pilha* topo, char valor) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

Pilha* pop(Pilha* topo) {
    if (!topo) return NULL;
    Pilha* temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

int parenteses_validos(char expressao[]) {
    Pilha* topo = NULL;
    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            topo = push(topo, '(');
        } else if (expressao[i] == ')') {
            if (topo == NULL) {
                return 0;
            }
            topo = pop(topo);
        }
    }

    return topo == NULL;
}

int main() {
    char expressao[100];

    printf("Digite uma expressao: ");
    scanf("%s", expressao);

    if (parenteses_validos(expressao)) {
        printf("Valido\n");
    } else {
        printf("Invalido\n");
    }

    return 0;
}
