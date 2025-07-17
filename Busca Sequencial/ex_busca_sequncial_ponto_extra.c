#include <stdio.h>

int busca(int vetor[], int tamanho, int valor){
    
    for (int i = 0; i < tamanho; i++){
        if (vetor[i] == valor){
            return i;
        }
    }
    return -1;

}

int main(){
    int vetor[] = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};
    int tam= 10;
    int valor =25;

    int retorno =busca(vetor,tam,valor);
    printf("------------------------------\n");
    printf("----- QUESTAO 1 -----\n");
    printf("Valor: 25, vetor : {15, 8, 25, 7, 12, 18, 5, 9, 30, 3}\n ");
    if(retorno != -1){
        printf("Valor %d na posicao %d\n", valor, retorno);
    }
     else {
        printf("Valor não encontrado.\n");
    }

    printf("------------------------------\n");
    printf("----- QUESTAO 2 -----\n");
    printf("Quantas vezes valor 7 aparece no vetor: {7, 3, 5, 7, 9, 2, 7, 1, 4, 6}\n");

    int vetor1[] = {7, 3, 5, 7, 9, 2, 7, 1, 4, 6};
    tam = 10;
    valor = 7;
    int primeiraPosicao = -1;
    int contador = 0;

    for (int i = 0; i < tam; i++) {
        if (vetor1[i] == valor) {
            if (primeiraPosicao == -1) {
                primeiraPosicao = i;
            }
            contador++;
        }
    }

    if (contador > 0) {
        printf("Valor %d encontrado e apareceu %d vezes.\n", valor, contador);
    } else {
        printf("Valor não encontrado.\n");
    }


    int vetor2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    tam = 10;
    valor = 55;
    retorno = busca(vetor2, tam, valor);
    printf("------------------------------\n");
    printf("----- QUESTAO 3 -----\n");
    printf("Valor: 55, vetor : {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}\n ");
    if(retorno != -1){
        printf("Valor %d na posicao %d\n", valor, retorno);
    }
     else {
        printf("-1\n");
    }



    return 0;
}