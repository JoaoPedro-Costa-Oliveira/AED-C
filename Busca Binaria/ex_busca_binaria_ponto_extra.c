#include <stdio.h>

int buscabinaria(int arr[], int tamanho, int valor){
    int inicio = 0, fim = tamanho -1, meio;
    while (inicio <= fim){
        meio = (inicio + fim) /2;

        if (arr[meio] == valor){
            return meio;
        }

        else if (arr[meio] < valor){
            inicio = meio +1;
        }
        else{
            fim = meio -1;
        } 
    }

    return -1;
}

int buscabinContador(int arr[], int tamanho, int valor, int *comparacoes){
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim) {
        (*comparacoes)++; 
        meio = (inicio + fim) / 2;

        if (arr[meio] == valor) {
            return meio;
        } else if (arr[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int posicaoInsercao(int arr[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (arr[meio] == valor) {
            return meio;
        } else if (arr[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return inicio;
}



int main(){
    int vetor[] = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};
    int tam = 10;
    int valor = 13;

    int retorno = buscabinaria(vetor, tam, valor);
    
    printf("-------------------\n");
    printf("Questao 1\n");
    printf("Vetor: {2, 4, 6, 8, 10, 12, 13, 14, 16, 18}; valor :13\n");
    if (retorno != -1){
        printf("Valor %d encontrado na posicao %d.\n", valor, retorno);
    } else {
        printf("Valor nao encontrado.\n");
    }

    int vetor2[] = {10,20,30,40,50,60,70,80,90,100};
    tam = 10;
    valor = 100;
    int cont = 0;

    int retorno1 = buscabinContador(vetor2, tam, valor, &cont);
    printf("--------------------\n");
    printf("Questao 2\n");
    printf("Vetor: {10,20,30,40,50,60,70,80,90,100}; valor: 100\n");

    if (retorno1 != -1) {
        printf("Valor %d encontrado na posicao %d.\n", valor, retorno);
    } else {
        printf("Valor nao encontrado.\n");
    }

    printf("Numero de comparacoes feitas: %d\n", cont);
       
    printf("--------------------\n");
    printf("Questao 3\n");

    int vetor3[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    tam = 10;
    valor = 27;

    int posInsercao = posicaoInsercao(vetor3, tam, valor);

    printf("Vetor: {5, 10, 15, ..., 50}; valor: %d\n", valor);
    printf("Posicao de insercao do valor %d: %d\n", valor, posInsercao);






    return 0;
}