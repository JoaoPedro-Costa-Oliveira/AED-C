#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Livros{
    char titulo[50];
    char autor[50];
    int ano;
}Livros;

void verificarAno(Livros livro[], int n, int ano){
   printf("Livros publicados apos %d\n", ano);
   for (int i = 0; i < n; i++){
    if(livro[i].ano > ano){ 
        printf("Titulo: %s \n", livro[i].titulo);
        printf("Autor:  %s \n", livro[i].autor);
        printf("Ano: %d\n", livro[i].ano);
        printf("-------------------\n");
        }
    }
}

int main(){
    int N, anoFilto;
    scanf("%d", &N);

    Livros livro[N];
    for (int i = 0; i < N; i++){
        printf("----------------------\n");
        printf("Livro %d\n", i +1);
        printf("Titulo: ");
        scanf(" %49[^\n]", livro[i].titulo);
        printf("Autor: ");
        scanf("%49[^\n]", livro[i].autor);
        printf("Ano de publicão: ");
        scanf("%d", &livro[i].ano);
    }
    printf("\nDigite um ano para filtrar os livros apos esse ano: ");
    scanf("%d", &anoFilto);
    
    verificarAno(livro, N, anoFilto);

    return 0;
}