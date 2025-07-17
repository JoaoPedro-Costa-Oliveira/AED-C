#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    char dado;
    struct Pilha* prox;

} Pilha;

Pilha* push(Pilha* topo, char valor){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

Pilha* pop(Pilha* topo, char* valor){
    if (!topo){
        return NULL;
    }
    Pilha* tempo = topo;
    *valor = topo->dado;
    topo = topo->prox;
    free(tempo);

    return topo;
}

void top(Pilha* topo){
    if(!topo){
        printf("Está vazia");
    }
    else{
        printf("Topo da pilha -> %c\n", topo->dado);
    }

}

int isEmpty(Pilha* topo){
   return topo == NULL;
}

void exibir(Pilha* topo){
    printf("Pilha: ");
    while (topo){
        printf("%c", topo->dado);
        topo = topo->prox;
        
    }
    printf("\n");
    

}




int main(){

    Pilha* topo = NULL;
    char valor;

    topo = push(topo, 'A');
    topo = push(topo, 'B');
    topo = push(topo, 'C');
    topo = push(topo, 'D');

    exibir(topo);
    top(topo);

    if (!isEmpty(topo)) {
        topo = pop(topo, &valor);
        printf("Desempilhado: %c\n", valor);
    }

    exibir(topo);
    top(topo);


    return 0;
}