#include <stdio.h>

int buscaPar(int v[], int tamanho, int chave) {
    // Verifica se o número é ímpar
    if (chave % 2 != 0) {
        printf("Erro: numeros impares nao podem ser buscados.\n");
        return -1;
    }

    for (int i = 0; i < tamanho; i++) {
        if (v[i] == chave) {
            printf("Valor %d encontrado na posicao %d\n", chave, i);
            return i;
        }
    }

    printf("Valor %d nao encontrado.\n", chave);
    return -1;
}

int main() {
    int vetor[] = {3, 4, 6, 7, 8, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    int valor;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    buscaPar(vetor, tamanho, valor);

    return 0;
}
