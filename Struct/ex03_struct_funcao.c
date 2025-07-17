#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Produto{
    
    char nome[30];
    int  codigo;
    float preco;

} Produto;

void imprimirProdutos(Produto produto){
    printf("-----------------\n");
    printf("Produto\n");
    printf("Nome: %s\n", produto.nome);
    printf("Codigo: %d\n", produto.codigo);
    printf("Preco: %f", produto.preco);
    printf("-----------------\n");
} 


int main(){
    Produto produto;
    
    scanf("%s", produto.nome);
    scanf("%d", &produto.codigo);
    scanf("%f", &produto.preco);

    imprimirProdutos(produto);

    return 0;
}