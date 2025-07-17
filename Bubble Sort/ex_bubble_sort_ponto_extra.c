#include <stdio.h>

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++){ 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortMelhorado(int v[], int n) {
    int iteracoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        iteracoes++;
        if (!trocou) {
            printf("(Bubble Sort parou apos %d iteracoes)\n", iteracoes);
            break;
        }
    }
}

void bubbleSortDecrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++){
            if (v[j] < v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void printVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int tam = 10;

    int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 0};
    bubblesort(arr, tam);
    printf("---------------\n");
    printf("Questao 1\n");
    printf("Array original: {9, 7, 5, 3, 1, 2, 4, 6, 8, 0}\n");
    printf("Array ordenado: ");
    printVetor(arr, tam);

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("---------------\n");
    printf("Questao 2\n");
    printf("Array original: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}\n");
    bubbleSortMelhorado(arr1, tam);
    printf("Array ordenado: ");
    printVetor(arr1, tam);


    int arr2[] = {12, 3, 45, 7, 18, 9, 25, 31, 6, 11};
    printf("---------------\n");
    printf("Questao 3\n");
    printf("Array original: {12, 3, 45, 7, 18, 9, 25, 31, 6, 11}\n");
    bubbleSortDecrescente(arr2, tam);
    printf("Array ordenado decrescente: ");
    printVetor(arr2, tam);

    return 0;
}
