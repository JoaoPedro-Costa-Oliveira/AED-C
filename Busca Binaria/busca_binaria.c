#include <stdio.h>

int buscaBin(int v[], int tamanho, int chave){
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim){
        meio = (inicio + fim) / 2;

        if (v[meio] == chave){
            return meio;
        } else if (v[meio] < chave){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main(){
    int vetor[] = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};
    int tam = 10;
    int valor = 13;

    int retorno = buscaBin(vetor, tam, valor);

    if (retorno != -1){
        printf("Valor %d encontrado na posição %d.\n", valor, retorno);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
