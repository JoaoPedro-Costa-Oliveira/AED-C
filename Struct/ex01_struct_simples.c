#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
} Pessoa;



int main(){
    Pessoa pessoa;
    printf("Nome: ");
    scanf("%s", pessoa.nome);
    printf("Idade: ");
    scanf("%d", &pessoa.idade);
    printf("Altura: ");
    scanf("%f", &pessoa.altura);
    printf("Nome -> %s; Idade -> %d, Altura -> %f\n", pessoa.nome, pessoa.idade, pessoa.altura);

    return 0;
}