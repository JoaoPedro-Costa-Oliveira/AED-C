#include <stdio.h>

int buscaBinariaPrimeiraOcorrencia(int v[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;
    int resultado = -1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == chave) {
            resultado = meio;         
            fim = meio - 1;           
        } else if (v[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return resultado;
}

int main() {
    int vetor[] = {2, 4, 4, 4, 7, 9, 12};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 4;

    int posicao = buscaBinariaPrimeiraOcorrencia(vetor, tamanho, valor);

    if (posicao != -1) {
        printf("Primeira ocorrencia do valor %d encontrada na posicao %d\n", valor, posicao);
    } else {
        printf("Valor %d nao encontrado.\n", valor);
    }

    return 0;
}
