#include <stdio.h>

int maior(int lista[], int tamanho){
    if (tamanho == 1){
        return lista[0];
    }

    int maior_restante = maior(lista, tamanho - 1);

    if (lista[tamanho - 1] > maior_restante){
        return lista[tamanho - 1];
    } else {
        return maior_restante;
    }
}

int main(){
    int vetor[] = {10, 2, 4, 11, 99};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Lista: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    printf("\nO maior numero da lista e %d\n", maior(vetor, tamanho));

    return 0;
}
