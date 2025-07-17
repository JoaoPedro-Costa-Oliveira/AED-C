#include <stdio.h>

void selectionSortTrocasVisiveis(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            printf("Troca %d <-> %d: ", arr[i], arr[min_idx]);
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

int selectionSortContarTrocas(int arr[], int n) {
    int trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            trocas++;
        }
    }
    return trocas;
}

void selectionSortDecrescente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        int temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}




#include <stdio.h>

int main() {
    
    int arr1[] = {29, 10, 14, 37, 13, 40, 2, 7, 5, 18};
    int tam  = 10;
    printf("Questao 1 - Mostrar trocas:\n");
    selectionSortTrocasVisiveis(arr1, tam);

    
    int arr2[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    printf("\nQuestao 2 - Contar trocas:\n");
    int total = selectionSortContarTrocas(arr2, tam);
    printf("Total de trocas: %d\n", total);

    
    int arr3[] = {42, 33, 60, 15, 75, 12, 25, 90, 1, 6};
    printf("\nQuestao 3 - Decrescente:\n");
    selectionSortDecrescente(arr3, tam);
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
