#include <stdio.h>

int maior_elemento(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    } else {
        int max_anterior = maior_elemento(vet, n - 1);
        if (vet[n - 1] > max_anterior) {
            return vet[n - 1];
        } else {
            return max_anterior;
        }
    }
}

int main() {
    int n;

    printf("Quantos elementos deseja inserir? ");
    scanf("%d", &n);

    int vetor[n]; // declaração do vetor com tamanho inserido

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int maior = maior_elemento(vetor, n);
    printf("Maior elemento do vetor: %d\n", maior);

    return 0;
}
