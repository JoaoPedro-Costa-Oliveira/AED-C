#include <stdio.h>

void buscaSequencialTodos(int vetor[], int tamanho, int valorBuscado) {
    int encontrou = 0;

    printf("Posicoes: ");

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valorBuscado) {
            printf("%d ", i);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Valor nao encontrado no vetor.");
    }

    printf("\n");
}

int main() {
    // Vetor com elementos repetidos
    int vetor[] = {4, 7, 9, 4, 2, 4, 8};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int valor = 4;  // Valor a ser buscado

    // Chama a função de busca
    buscaSequencialTodos(vetor, tamanho, valor);

    return 0;
}
