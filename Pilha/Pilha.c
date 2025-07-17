#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha{
    char dado;
    struct Pilha* prox;
} Pilha;

Pilha* empilhar(Pilha* topo, char valor){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->dado = valor;
    novo->prox =topo;
    return novo;
} 

Pilha* desempilhar(Pilha* topo, char*  valor){
    if (!topo){
        return NULL;
    }
    Pilha* tempo = topo;
    *valor = topo->dado;
    topo = topo->prox;
    free(tempo);

    return topo;
}
void inverterPalavra(char palavra[]){
    Pilha* pilha = NULL;

    for (int i = 0; palavra[i] != '\0' ; i++){
        pilha = empilhar(pilha,palavra[i]);
    }
    printf("Palavra invertida: ");
    char c;
    while (pilha){
        pilha = desempilhar(pilha, &c), printf("%c", c);
        printf("");
    }
}

int main(){
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inverterPalavra(palavra);
   
    return 0;

}

